#ifndef FILE_READER_H
#define FILE_READER_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define SECTOR_SIZE 512

#define FILENAME_SIZE_ROOT 8
#define EXTENSION_SIZE_ROOT 3

#define ERROR_MAGIC 0x01u
#define ERROR_RESERVED_SECTORS 0x02u
#define ERROR_FAT_COUNT 0x04u
#define ERROR_BYTES_PER_SECTOR 0x08u
#define ERROR_LOGICAL_SECTORS 0x10u
#define ERROR_SECTORS_PER_FAT 0x20u
#define ERROR_LOGICAL_SECTORS_VALUE 0x40u
#define ERROR_SECTORS_PER_CLUSTER 0x80u

typedef uint32_t lba_t;
typedef uint32_t cluster_t;

typedef uint16_t fat_date_t;
typedef uint16_t fat_time_t;

typedef enum {
    READ_ONLY = 0x01, HIDDEN_FILE = 0x02, SYSTEM_FILE = 0x04,
    VOLUME_LABEL = 0x08, LONG_FILE_NAME = 0x0f, DIRECTORY = 0x10,
    ARCHIVE = 0x20, LFN = READ_ONLY | HIDDEN_FILE | SYSTEM_FILE | VOLUME_LABEL
} __attribute__((packed)) dir_attributes;

struct fat_super_t {
    uint8_t jump_code[3];
    char oem_name[8];
    uint16_t bytes_per_sector;
    uint8_t sectors_per_cluster;
    uint16_t reserved_sectors;
    uint8_t fat_count;
    uint16_t root_dir_capacity;
    uint16_t logical_sectors16;
    uint8_t media_type;
    uint16_t sectors_per_fat;
    uint16_t chs_sectors_per_track;
    uint16_t chs_tracks_per_cylinder;
    uint32_t hidden_sectors;
    uint32_t logical_sectors32;
    uint8_t media_id;
    uint8_t chs_head;
    uint8_t ext_bpb_signature;
    uint32_t serial_number;
    char volume_label[11];
    char fsid[8];
    uint8_t boot_code[448];
    uint16_t magic;
} __attribute__ ((packed)) fat_super_t;

struct root_entry_t {
    char file_name[FILENAME_SIZE_ROOT + EXTENSION_SIZE_ROOT];
    dir_attributes file_attributes;
    uint8_t reserved0;
    uint8_t cration_time_ms;
    fat_time_t creation_time;
    fat_date_t creation_date;
    fat_time_t last_accessed_time;
    uint16_t high_cluster_index;
    fat_time_t last_modified_time;
    fat_date_t last_modified_date;
    uint16_t low_cluster_index;
    uint32_t file_size;
} __attribute__ ((packed)) root_entry_t;

struct dir_entry_t {
    char *name;
    size_t size;
    bool is_archived;
    bool is_readonly;
    bool is_system;
    bool is_hidden;
    bool is_directory;
};

struct volume_t {
    struct disk_t *disk;
    struct fat_super_t fat_super;

    lba_t start_pos;
    lba_t fat1_start;
    lba_t fat2_start;
    lba_t root_dir_start;
    lba_t root_dir_size;
    lba_t cluster2_start;

    lba_t user_space_size;
    lba_t volume_size;
    cluster_t total_clusters;
    size_t bytes_per_sector;

    uint32_t *fat_table;
    struct root_entry_t *root_dir;
} volume_t;

struct file_t {
    struct volume_t *volume;
    struct root_entry_t *entry;

    cluster_t first_cluster_index;
    size_t size_of_file_bytes;

    lba_t current_sector_offset;
    size_t current_bytes_offset;
} file_t;

struct dir_t {
    struct volume_t *volume;
    struct root_entry_t *entry;
    size_t size;
} dir_t;

struct disk_t {
    FILE *disk_file;
} disk_t;

struct disk_t *disk_open_from_file(const char *volume_file_name);

int disk_read(struct disk_t *pdisk, int32_t first_sector, void *buffer, int32_t sectors_to_read);

int disk_close(struct disk_t *pdisk);

struct volume_t *fat_open(struct disk_t *pdisk, uint32_t first_sector);

int fat_close(struct volume_t *pvolume);

struct file_t *file_open(struct volume_t *pvolume, const char *file_name);

int file_close(struct file_t *stream);

size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream);

int32_t file_seek(struct file_t *stream, int32_t offset, int whence);

struct dir_t *dir_open(struct volume_t *pvolume, const char *dir_path);

int dir_read(struct dir_t *pdir, struct dir_entry_t *pentry);

int dir_close(struct dir_t *pdir);

#endif
