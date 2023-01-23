#ifndef FAT_UTILS_H
#define FAT_UTILS_H

#include "file_reader.h"

size_t check_bytes_to_read(struct file_t *stream, size_t bytes_to_read, size_t remaining_bytes_to_read);

lba_t get_sectors_per_cluster(struct file_t *stream);

cluster_t get_current_cluster_offset(struct file_t *stream);

cluster_t get_cluster_index(struct file_t *stream);

cluster_t get_current_cluster(struct file_t *stream, cluster_t current_cluster_offset);

lba_t get_cluster_start(struct file_t *stream);

size_t get_block_buffer_offset(struct file_t *stream);

bool check_input_args(void *ptr, struct file_t *stream);

bool check_end_of_file(struct file_t *stream);

lba_t get_fat1_pos(struct volume_t *volume);

lba_t get_fat2_pos(struct volume_t *volume);

lba_t get_root_dir_pos(struct volume_t *volume);

lba_t get_cluster2_pos(struct volume_t *volume);

uint32_t get_volume_size(struct volume_t *volume);

uint32_t get_user_space(struct volume_t *volume);

uint32_t get_total_clusters(struct volume_t *volume);

uint32_t get_root_dir_size(struct volume_t *volume);

uint8_t check_fat_super(struct fat_super_t super);

int set_volume_geometry(struct volume_t *volume, uint32_t first_sector);

int compare_fat_tables(const struct volume_t *volume);

uint32_t *load_fat_table(const struct volume_t *volume);

struct root_entry_t *find_entry_in_root_dir(const struct volume_t *volume, const char *name);

ssize_t calculate_offset(struct file_t *stream, int32_t offset, int whence);

int filename_divide(const char *filename, uint8_t *name, uint8_t *extension);

char *filename_join(const char *full_name);

#endif //FAT_UTILS_H
