#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "file_reader.h"
#include "utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

#define FAT_DELETED_MAGIC ((char)0xE5)

struct disk_t *disk_open_from_file(const char *volume_file_name) {
    if (!volume_file_name)
        return NULL;

    struct disk_t *disk = (struct disk_t *) calloc(sizeof(struct disk_t), 1);
    if (!disk)
        return NULL;

    disk->disk_file = fopen(volume_file_name, "rb");
    if (!disk->disk_file)
        return free(disk), NULL;

    return disk;
}

int disk_read(struct disk_t *pdisk, int32_t first_sector, void *buffer, int32_t sectors_to_read) {

    if (!pdisk || !buffer || first_sector < 0 || sectors_to_read < 0)
        return -1;

    fseek(pdisk->disk_file, first_sector * SECTOR_SIZE, SEEK_SET);

    int32_t read_blocks = (int32_t) fread(buffer, SECTOR_SIZE, sectors_to_read, pdisk->disk_file);
    if (read_blocks != sectors_to_read)
        return -1;

    return read_blocks;
}

int disk_close(struct disk_t *pdisk) {
    if (!pdisk || !pdisk->disk_file)
        return -1;

    fclose(pdisk->disk_file);
    free(pdisk);

    return 0;
}

struct volume_t *fat_open(struct disk_t *pdisk, uint32_t first_sector) {
    if (!pdisk || !pdisk->disk_file)
        return NULL;

    struct volume_t *pVolume = (struct volume_t *) calloc(1, sizeof(struct volume_t));
    if (!pVolume)
        return NULL;

    if (disk_read(pdisk, first_sector, &pVolume->fat_super, 1) != 1)
        return fat_close(pVolume), NULL;

    if (check_fat_super(pVolume->fat_super))
        return fat_close(pVolume), NULL;

    if (set_volume_geometry(pVolume, first_sector))
        return fat_close(pVolume), NULL;

    pVolume->disk = pdisk;

    if (pVolume->fat_super.fat_count == 2)
        if (compare_fat_tables(pVolume))
            return fat_close(pVolume), NULL;

    pVolume->fat_table = load_fat_table(pVolume);
    if (!pVolume->fat_table)
        return fat_close(pVolume), NULL;

    pVolume->root_dir = (struct root_entry_t *) calloc(pVolume->root_dir_size, pVolume->bytes_per_sector);
    if (!pVolume->root_dir)
        return fat_close(pVolume), NULL;

    if (disk_read(pVolume->disk, pVolume->root_dir_start, pVolume->root_dir, pVolume->root_dir_size) !=
        (int) pVolume->root_dir_size)
        return fat_close(pVolume), NULL;

    return pVolume;
}

int fat_close(struct volume_t *pvolume) {
    if (!pvolume)
        return -1;

    free(pvolume->fat_table);
    free(pvolume->root_dir);
    free(pvolume);

    return 0;
}

struct file_t *file_open(struct volume_t *pvolume, const char *file_name) {
    if (!pvolume || !file_name || !pvolume->disk)
        return NULL;

    struct file_t *file = calloc(sizeof(struct file_t), 1);
    if (!file)
        return NULL;

    file->volume = pvolume;

    file->entry = find_entry_in_root_dir(file->volume, file_name);
    if (!file->entry || (file->entry->file_attributes & (DIRECTORY | VOLUME_LABEL)) != 0)
        return file_close(file), NULL;

    file->current_bytes_offset = 0;
    file->current_sector_offset = 0;

    file->first_cluster_index = ((cluster_t) file->entry->high_cluster_index << 16) | file->entry->low_cluster_index;

    file->size_of_file_bytes = file->entry->file_size;

    return file;
}

int file_close(struct file_t *stream) {
    if (!stream)
        return -1;

    free(stream);

    return 0;
}

lba_t get_sectors_per_cluster(struct file_t *stream) {
    return stream->volume->fat_super.sectors_per_cluster;
}

cluster_t get_current_cluster_offset(struct file_t* stream) {
    return stream->current_sector_offset / get_sectors_per_cluster(stream);
}

cluster_t get_cluster_index(struct file_t *stream) {
    return stream->first_cluster_index;
}

cluster_t get_current_cluster(struct file_t *stream, cluster_t current_cluster_offset) {
    cluster_t cluster = get_cluster_index(stream);

    for (cluster_t i = 0; i < current_cluster_offset; ++i)
    {
        if (cluster >= stream->volume->fat_table[1])
            break;

        if (cluster > stream->volume->total_clusters)
            return cluster;

        cluster = stream->volume->fat_table[cluster];
    }

    return cluster;
}

lba_t get_cluster_start(struct file_t *stream) {
    lba_t sectors_per_cluster = get_sectors_per_cluster(stream);
    cluster_t current_cluster_offset = get_current_cluster_offset(stream);
    lba_t current_cluster = get_current_cluster(stream, current_cluster_offset);

    return stream->volume->cluster2_start + (current_cluster - 2) * sectors_per_cluster;
}

struct file_t* check_current_bytes_offset(struct file_t *stream, size_t bytes_to_read) {
    stream->current_bytes_offset += bytes_to_read;
    if (stream->current_bytes_offset >= 512) {
        stream->current_bytes_offset = 0;
        stream->current_sector_offset++;
    }
    return stream;
}

size_t get_block_buffer_offset(struct file_t *stream) {
    return stream->current_bytes_offset % 512;
}

size_t check_bytes_to_read(struct file_t *stream, size_t bytes_to_read, size_t remaining_bytes_to_read) {
    size_t block_buffer_offset = get_block_buffer_offset(stream);

    if (remaining_bytes_to_read < 512)
        bytes_to_read = remaining_bytes_to_read;
    else
        bytes_to_read = 512 - block_buffer_offset;

    if (stream->current_bytes_offset + (stream->current_sector_offset * stream->volume->bytes_per_sector) +
        bytes_to_read > stream->size_of_file_bytes)
        bytes_to_read = stream->size_of_file_bytes - (stream->current_bytes_offset +
                                                      (stream->current_sector_offset *
                                                       stream->volume->bytes_per_sector));
    else if (block_buffer_offset + bytes_to_read > 512)
        bytes_to_read = bytes_to_read - ((block_buffer_offset + bytes_to_read) % 512);

    return bytes_to_read;
}

bool check_input_args(void *ptr, struct file_t *stream) {
    if (!ptr || !stream)
        return false;
    return true;
}

bool check_end_of_file(struct file_t *stream) {
    if (stream->current_bytes_offset + stream->current_sector_offset * stream->volume->bytes_per_sector == stream->size_of_file_bytes)
        return true;
    return false;
}

size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream) {
    if (!check_input_args(ptr, stream))
        return -1;

    uint8_t block_buffer[512];
    lba_t sectors_per_cluster = get_sectors_per_cluster(stream);
    cluster_t current_cluster_offset = get_current_cluster_offset(stream);
    lba_t current_cluster = get_current_cluster(stream, current_cluster_offset);

    size_t bytes_loaded = 0;
    size_t remaining_bytes_to_read = size * nmemb;

    size_t bytes_to_read;
    lba_t cluster_start;

    while (remaining_bytes_to_read > 0 &&
           stream->current_bytes_offset + stream->current_sector_offset * stream->volume->bytes_per_sector !=
           stream->size_of_file_bytes) {
        if (current_cluster == stream->volume->fat_table[1])
            break;

        if ((current_cluster) > stream->volume->total_clusters)
            return -1;

        cluster_start = get_cluster_start(stream);

        for (lba_t i = stream->current_sector_offset % sectors_per_cluster; i < sectors_per_cluster; ++i) {
            if (disk_read(stream->volume->disk, cluster_start + i, block_buffer, 1) != 1)
                return -1;

            size_t block_buffer_offset = get_block_buffer_offset(stream);

            bytes_to_read = check_bytes_to_read(stream, bytes_to_read, remaining_bytes_to_read);

            memcpy((uint8_t *) ptr + bytes_loaded, block_buffer + block_buffer_offset, bytes_to_read);

            bytes_loaded += bytes_to_read;
            remaining_bytes_to_read -= bytes_to_read;

            stream = check_current_bytes_offset(stream, bytes_to_read);

            if (check_end_of_file(stream))
                break;
        }

        current_cluster = stream->volume->fat_table[current_cluster];
        current_cluster_offset++;
    }

    return bytes_loaded / size;
}

ssize_t calculate_offset(struct file_t *stream, int32_t offset, int whence) {
    if (!stream)
        return -1;

    ssize_t current_offset;

    switch (whence) {
        case SEEK_SET:
            current_offset = 0;
            break;
        case SEEK_CUR:
            current_offset =
                    stream->current_bytes_offset + (stream->current_sector_offset * stream->volume->bytes_per_sector);
            break;
        case SEEK_END:
            current_offset = stream->size_of_file_bytes;
            break;

        default:
            return -1;
    }

    current_offset += offset;
    return current_offset;
}

int32_t file_seek(struct file_t *stream, int32_t offset, int whence) {
    if (!stream)
        return -1;

    ssize_t current_offset = calculate_offset(stream, offset, whence);

    if (current_offset < 0 || current_offset > (ssize_t) stream->size_of_file_bytes)
        return -1;

    stream->current_sector_offset = current_offset / stream->volume->bytes_per_sector;
    stream->current_bytes_offset = current_offset % stream->volume->bytes_per_sector;

    return current_offset;
}

struct dir_t *dir_open(struct volume_t *pvolume, const char *dir_path) {
    if (!pvolume)
        return NULL;

    struct dir_t *dir = (struct dir_t *) calloc(1, sizeof(struct dir_t));
    if (!dir)
        return NULL;

    dir->entry = pvolume->root_dir;
    dir->volume = pvolume;

    if (strcmp(dir_path, "\\") != 0)
        return free(dir), NULL;

    dir->size = 0;

    return dir;
}

int dir_read(struct dir_t *pdir, struct dir_entry_t *pentry) {
    if (!pdir || !pentry)
        return -1;

    struct root_entry_t *entry = NULL;

    while (1) {
        entry = &pdir->entry[pdir->size++];

        if (entry->file_name[0] == 0) {
            entry = NULL;
            break;
        }

        if (entry->file_name[0] == '\xE5')
            continue;

        if (!(entry->file_attributes & (DIRECTORY | VOLUME_LABEL)) ||
            (entry->file_attributes & DIRECTORY) && !(entry->file_attributes & VOLUME_LABEL))
            break;

    }

    if (!entry)
        return 1;

    pentry->name = filename_join(entry->file_name);
    if (!pentry->name)
        return -1;

    pentry->size = entry->file_size;
    pentry->is_archived = entry->file_attributes & ARCHIVE;
    pentry->is_readonly = entry->file_attributes & READ_ONLY;
    pentry->is_system = entry->file_attributes & SYSTEM_FILE;
    pentry->is_hidden = entry->file_attributes & HIDDEN_FILE;
    pentry->is_directory = entry->file_attributes & DIRECTORY;

    free(pentry->name); // ?

    return 0;
}

int dir_close(struct dir_t *pdir) {
    if (!pdir)
        return -1;

    free(pdir);

    return 0;
}

uint8_t check_fat_super(struct fat_super_t super) {
    uint8_t errors = 0;

    // Check magic number
    if (super.magic != 43605)
        errors |= ERROR_MAGIC;

    // Check number of reserved sectors
    if (super.reserved_sectors < 1)
        errors |= ERROR_RESERVED_SECTORS;

    // Check number of FATs
    if (super.fat_count < 1)
        errors |= ERROR_FAT_COUNT;

    // Check bytes per sector and root directory capacity
    if (super.bytes_per_sector == 0 ||
        (super.root_dir_capacity * sizeof(struct root_entry_t) % super.bytes_per_sector) != 0)
        errors |= ERROR_BYTES_PER_SECTOR;

    // Check number of logical sectors
    if (super.logical_sectors16 == 0 && super.logical_sectors32 == 0)
        errors |= ERROR_LOGICAL_SECTORS;

    // Check number of sectors per FAT
    if (super.sectors_per_fat < 1)
        errors |= ERROR_SECTORS_PER_FAT;

    // Check if logical sectors value is correct
    if (super.logical_sectors16 == 0 && super.logical_sectors32 <= 65535)
        errors |= ERROR_LOGICAL_SECTORS_VALUE;

    // Check if sectors per cluster is power of two
    if (!(super.sectors_per_cluster & (super.sectors_per_cluster - 1)) == 0)
        errors |= ERROR_SECTORS_PER_CLUSTER;

    return errors;
}

lba_t get_fat1_pos(struct volume_t *volume) {
    return volume->start_pos + volume->fat_super.reserved_sectors;
}

lba_t get_fat2_pos(struct volume_t *volume) {
    return volume->fat1_start + volume->fat_super.sectors_per_fat;
}

lba_t get_root_dir_pos(struct volume_t *volume) {
    return volume->fat2_start + volume->fat_super.sectors_per_fat;
}

lba_t get_cluster2_pos(struct volume_t *volume) {
    return volume->root_dir_start + volume->root_dir_size;
}

uint32_t get_volume_size(struct volume_t *volume) {
    return volume->fat_super.logical_sectors16 == 0 ? volume->fat_super.logical_sectors32
                                                    : volume->fat_super.logical_sectors16;
}

uint32_t get_user_space(struct volume_t *volume) {
    return volume->volume_size - volume->fat_super.reserved_sectors -
           volume->fat_super.fat_count * volume->fat_super.sectors_per_fat - volume->root_dir_size;
}

uint32_t get_total_clusters(struct volume_t *volume) {
    return volume->user_space_size / volume->fat_super.sectors_per_cluster;
}

uint32_t get_root_dir_size(struct volume_t *volume) {
    uint32_t size =
            (volume->fat_super.root_dir_capacity * sizeof(struct root_entry_t)) / volume->fat_super.bytes_per_sector;
    if (((volume->fat_super.root_dir_capacity * sizeof(struct root_entry_t)) % volume->fat_super.bytes_per_sector) != 0)
        size += 1;
    return size;
}

int set_volume_geometry(struct volume_t *volume, uint32_t first_sector) {

    volume->start_pos = first_sector;
    volume->fat1_start = get_fat1_pos(volume);
    volume->fat2_start = get_fat2_pos(volume);
    volume->root_dir_start = get_root_dir_pos(volume);

    volume->root_dir_size = get_root_dir_size(volume);

    volume->cluster2_start = get_cluster2_pos(volume);

    volume->volume_size = get_volume_size(volume);
    volume->user_space_size = get_user_space(volume);

    volume->total_clusters = get_total_clusters(volume);
    volume->bytes_per_sector = volume->fat_super.bytes_per_sector;

    if (volume->total_clusters == 0)
        return -1;

    return 0;
}

int compare_fat_tables(const struct volume_t *volume) {
    void *fat1_table = calloc(volume->fat_super.sectors_per_fat, volume->bytes_per_sector);
    void *fat2_table = calloc(volume->fat_super.sectors_per_fat, volume->bytes_per_sector);

    if (!fat1_table || !fat2_table)
        return -1;

    if (disk_read(volume->disk, volume->fat1_start, fat1_table, volume->fat_super.sectors_per_fat) !=
        volume->fat_super.sectors_per_fat ||
        disk_read(volume->disk, volume->fat2_start, fat2_table, volume->fat_super.sectors_per_fat) !=
        volume->fat_super.sectors_per_fat) {
        return free(fat1_table), free(fat2_table), -1;
    }

    int comparison_result = memcmp(fat1_table, fat2_table,
                                   volume->fat_super.sectors_per_fat * volume->bytes_per_sector);
    free(fat1_table);
    free(fat2_table);
    return comparison_result != 0 ? 1 : 0;
}

uint32_t *load_fat_table(const struct volume_t *volume) {
    uint8_t *fat1_table = calloc(volume->fat_super.sectors_per_fat, volume->bytes_per_sector);
    if (!fat1_table)
        return NULL;

    if (disk_read(volume->disk, volume->fat1_start, fat1_table, volume->fat_super.sectors_per_fat) !=
        volume->fat_super.sectors_per_fat)
        return free(fat1_table), NULL;

    uint32_t *fat_data = (uint32_t *) calloc(sizeof(uint32_t), volume->total_clusters);
    if (!fat_data)
        return free(fat1_table), NULL;

    for (cluster_t i = 0; i < volume->total_clusters * 3 / 2; i += 3) {
        fat_data[i / 3 * 2 + 0] = ((uint32_t) (fat1_table[i + 1] & 0x0F) << 8) | fat1_table[i + 0];
        fat_data[i / 3 * 2 + 1] = ((uint32_t) fat1_table[i + 2] << 4) | ((fat1_table[i + 1] & 0xF0) >> 4);
    }

    return free(fat1_table), fat_data;
}

struct root_entry_t *find_entry_in_root_dir(const struct volume_t *volume, const char *name) {

    struct root_entry_t *result = NULL;

    for (int i = 0; i < volume->fat_super.root_dir_capacity; ++i) {
        if (name[0] == '\\') {
            if (strlen(name) < 2) {
                result = volume->root_dir;
                break;
            }
            uint8_t entry_name_buffer[FILENAME_SIZE_ROOT + EXTENSION_SIZE_ROOT];

            memset(entry_name_buffer, ' ', FILENAME_SIZE_ROOT + EXTENSION_SIZE_ROOT);
            memcpy(entry_name_buffer, name + 1, strlen(name) - 1);

            if (memcmp(volume->root_dir[i].file_name, entry_name_buffer, FILENAME_SIZE_ROOT) == 0) {
                result = &volume->root_dir[i];
                break;
            }
        } else {
            uint8_t extension_buffer[EXTENSION_SIZE_ROOT];
            uint8_t name_buffer[FILENAME_SIZE_ROOT];

            memset(extension_buffer, ' ', EXTENSION_SIZE_ROOT);
            memset(name_buffer, ' ', FILENAME_SIZE_ROOT);

            filename_divide(name, name_buffer, extension_buffer);
            if (memcmp(volume->root_dir[i].file_name, name_buffer, FILENAME_SIZE_ROOT) == 0 &&
                memcmp(volume->root_dir[i].file_name + FILENAME_SIZE_ROOT, extension_buffer, EXTENSION_SIZE_ROOT) ==
                0) {
                result = &volume->root_dir[i];
                break;
            }
        }
    }
    return result;
}

int filename_divide(const char *filename, uint8_t *name, uint8_t *extension) {
    if (!filename || !name)
        return 1;

    if (!extension)
        return 2;

    char *dot_index = strchr(filename, '.');
    if (dot_index) {
        size_t len = dot_index - filename;
        memcpy(name, filename, len);
        memcpy(extension, dot_index + 1, strlen(dot_index + 1));
    } else {
        memcpy(name, filename, strlen(filename));
    }

    return 0;
}

char *filename_join(const char *name)
{
    char *buffer = NULL;
    size_t buffer_size = FILENAME_SIZE_ROOT + EXTENSION_SIZE_ROOT + 2;

    buffer = (char *) malloc(buffer_size * sizeof(char));
    if (!buffer)
        return NULL;

    memset(buffer, '\0', buffer_size);

    size_t i = 0, j = 0;
    for (; i < FILENAME_SIZE_ROOT; ++i)
        if (name[i] != ' ')
            buffer[j++] = name[i];

    size_t dot_index = j++;
    buffer[dot_index] = '.';

    bool extension = false;
    for (; i < FILENAME_SIZE_ROOT + EXTENSION_SIZE_ROOT; ++i) {
        if (name[i] != ' ') {
            extension = true;
            buffer[j++] = name[i];
        }
    }

    if (extension == false)
        buffer[dot_index] = '\0';

    return buffer;
}
