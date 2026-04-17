

struct fs_archive {
    char* name; // Union with pack_id (uint32_t)
    struct fs_archive* prev;
    struct fs_archive* next;
    struct os_thread_queue sync_q;
    struct os_thread_queue stat_q;
    uint32_t flag;
    undefined4 link_list_sync;
    undefined4 link_list_async;
    uint32_t base;
    uint32_t fat;
    uint32_t fat_size;
    uint32_t fnt;
    uint32_t fnt_size;
    uint32_t fat_bak;
    uint32_t fnt_bak;
    void* load_mem;
    int read_func;
    int write_func;
    int table_func;
    int proc;
    uint32_t proc_flag;
};

struct fs_dir_pos {
    struct fs_archive* arc;
    uint16_t own_id;
    uint16_t index;
    uint32_t pos;
};

struct fs_file_id {
    struct fs_archive* arc;
    uint32_t file_id;
};

struct fs_file {
    struct fs_file* prev;
    struct fs_file* next;
    struct fs_archive* arc;
    uint32_t stat;
    int32_t cmd_type;
    int32_t error;
    struct os_thread_queue queue;
    undefined4 prop_start[4]; // Is probably a union
    undefined4 arg_start[8];  // Is probably a union
};
// 0x48

struct file_archive_wrapper {
    struct fs_archive arc;
    void* field1_0x5c;
    struct fs_archive* unk_archive_0x60;
    struct fs_archive* unk_archive_0x64;
    struct file_wrapper* file_wrapper_ptr;
};

struct file_wrapper {
    undefined4 unk_fun_ptr_0x0;
    struct fs_file file;
    void* file_data;   // Data extracted from the file
    int file_data_len; // Length of the data extracted from the file
    bool file_is_open; // Whether or not the file is open.
    char unk_buffer[96];
};