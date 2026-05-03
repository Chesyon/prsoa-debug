#ifndef HEADERS_TYPES_COMMON_UTIL_H_
#define HEADERS_TYPES_COMMON_UTIL_H_

#include "enums.h"

// Common data structures not specific to SoA

// RGB8 color
struct rgb {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};
ASSERT_SIZE(struct rgb, 3);

// RGBA8 structure. Sometimes alpha is ignored and only used for padding
struct rgba {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a; // Sometimes used only for padding
};
ASSERT_SIZE(struct rgba, 4);

// RGB5 color
struct rgb5 {
    uint16_t r : 5;
    uint16_t g : 5;
    uint16_t b : 5;
    uint16_t padding : 1; // maybe transparency sometimes
};
ASSERT_SIZE(struct rgb5, 2);

// a 2d uint (32bit) vector
struct uvec2 {
    uint32_t x;
    uint32_t y;
};
ASSERT_SIZE(struct uvec2, 8);

// a 2d int (32bit) vector
struct vec2 {
    int32_t x;
    int32_t y;
};
ASSERT_SIZE(struct vec2, 8);

// a 2d ushort (16bit) vector
struct uvec2_16 {
    uint16_t x;
    uint16_t y;
};
ASSERT_SIZE(struct uvec2_16, 4);

// a 2d short (16bit) vector
struct vec2_16 {
    int16_t x;
    int16_t y;
};
ASSERT_SIZE(struct vec2_16, 4);

// A slice in the usual programming sense: a pointer, length, and capacity.
// Used for the implementation of vsprintf(3), but maybe it's used elsewhere as well.
struct slice {
    void* data;      // Pointer to the data buffer
    size_t capacity; // How much space is available in total
    size_t length;   // How much space is currently filled
};
ASSERT_SIZE(struct slice, 12);

// Function to append data to a struct slice, and return a success flag.
typedef bool (*slice_append_fn_t)(struct slice* slice, const void* data, size_t data_len);

// 64-bit signed fixed-point number with 16 fraction bits.
// Represents the number ((upper << 16) + (lower >> 16) + (lower & 0xFFFF) * 2^-16)
struct fx64_16 {
    int32_t upper;  // sign bit, plus the 31 most significant integer bits
    uint32_t lower; // the 32 least significant bits (16 integer + 16 fraction)
};
ASSERT_SIZE(struct fx64_16, 8);

// Define custom types for fixed-point numbers
typedef int fx32_16;       // 32-bit signed fixed-point number with 16 fraction bits
typedef int fx32_12;       // 32-bit signed fixed-point number with 12 fraction bits
typedef int fx32_8;        // 32-bit signed fixed-point number with 8 fraction bits
typedef int16_t fx16_14;   // 16-bit signed fixed-point number with 14 fraction bits
typedef int16_t fx16_12;   // 16-bit signed fixed-point number with 12 fraction bits
typedef uint32_t ufx32_16; // 32-bit unsigned fixed-point number with 16 fraction bits
typedef uint32_t ufx32_8;  // 32-bit unsigned fixed-point number with 8 fraction bits

// A raw ARMv5 data-processing instruction, such as MOV, ADD, AND, CMP, etc.
// See the ARMv5 Architecture Reference Manual, Section A3.4.1
// https://developer.arm.com/documentation/ddi0100/latest/
struct data_processing_instruction {
    // second source operand, either a shifted immediate value or a register, see Section A5.1
    uint32_t shifter_operand : 12;
    uint32_t rd : 4;     // destination register
    uint32_t rn : 4;     // first source operand register
    uint32_t s : 1;      // status flag, set if the instruction updates the status registers
    uint32_t opcode : 4; // see Section A3.4, Table A3-2
    uint32_t i : 1;      // immediate flag, set if shifter_operand represents an immediate
    uint32_t _zero : 2;  // always 0
    uint32_t cond : 4;   // condition code, see Section A3.2
};
ASSERT_SIZE(struct data_processing_instruction, 4);

// 4x3 matrix for the 3D geometry engine, stored in row-major format.
// Each element is a signed fixed-point number with 12 fraction bits.
// See https://problemkaputt.de/gbatek.htm#ds3dmatrixtypes
struct matrix_4x3 {
    fx32_12 entry[4][3];
};
ASSERT_SIZE(struct matrix_4x3, 48);

// TRIG_TABLE entry containing the value of sine/cosine at some angle
// Each value is a signed fixed-point number with 12 fraction bits.
struct trig_values {
    fx16_12 sin;
    fx16_12 cos;
};
ASSERT_SIZE(struct trig_values, 4);

// Specifies an entry function for a thread's execution
typedef void (*thread_entry_fn_t)(void);
// Specifies a function called when a thread exits
typedef void (*thread_exit_fn_t)(void);

#pragma pack(push, 4)
struct cp_context {
    uint64_t div_numer;
    uint64_t div_denom;
    uint64_t sqrt;
    uint16_t div_mode;
    uint16_t sqrt_mode;
};
ASSERT_SIZE(struct cp_context, 28);
#pragma pack(pop)

struct os_context {
    uint32_t cpsr;
    uint32_t registers[13]; // Initialized to 0
    // 0x38: Points to the area of the allocated stack area that can actually be used to store data.
    // This is equal to stack_pointer - 0x44, with an additional - 4 if the resulting addess is not
    // aligned to 8 bytes.
    void* usable_stack_pointer;
    // 0x3C: Address of the function to return to once the thread exits. Usually ThreadExit.
    thread_exit_fn_t exit_function;
    void* function_address_plus_4; // 0x40: Pointer to the function to run + 4
    void* stack_pointer_minus_4;   // 0x44: Pointer to the start of the stack area - 4
    struct cp_context cp_context;
};
ASSERT_SIZE(struct os_context, 100);

typedef void (*os_alarm_handler)(void*);

#pragma pack(push, 4)
struct osi_alarm {
    os_alarm_handler handler;
    void* arg;

    uint32_t tag;
    uint64_t fire;
    struct osi_alarm* prev;
    struct osi_alarm* next;

    uint64_t period;
    uint64_t start;
};
ASSERT_SIZE(struct osi_alarm, 44);
#pragma pack(pop)

typedef void (*os_thread_destructor)(void*);

struct thread;
struct os_thread_queue;
struct os_thread_link;
struct os_mutex;
struct os_mutex_queue;
struct os_mutex_link;

struct os_thread_queue {
    struct thread* head; // Initialized to NULL
    struct thread* tail; // Initialized to NULL
};
ASSERT_SIZE(struct os_thread_queue, 8);

struct os_thread_link {
    struct thread* prev; // Initialized to NULL
    struct thread* next; // Initialized to NULL
};
ASSERT_SIZE(struct os_thread_link, 8);

struct os_mutex_link {
    struct os_mutex* next; // Initialized to NULL
    struct os_mutex* prev; // Initialized to NULL
};
ASSERT_SIZE(struct os_mutex_link, 8);

struct os_mutex_queue {
    struct os_mutex* head; // Initialized to NULL
    struct os_mutex* tail; // Initialized to NULL
};
ASSERT_SIZE(struct os_mutex_queue, 8);

struct os_mutex {
    struct os_thread_queue queue;
    struct thread* thread;     // Initialized to NULL
    int count;                 // Initialized to 0
    struct os_mutex_link link; // Initialized to NULL
};
ASSERT_SIZE(struct os_mutex, 24);

// Contains information about a running thread
struct thread {
    struct os_context context;
    enum os_thread_state state; // Initialized to OS_THREAD_STATE_WAITING
    // 0x68: Pointer to the next thread. This forms a linked list sorted in ascending order
    // according to sorting_order
    struct thread* next_thread;
    // 0x6C: Seems to be a thread ID that gets incremented for each new thread created.
    int thread_id;
    int sorting_order;             // 0x70: Used to sort threads.
    void* profiler;                // Initialized to NULL
    struct os_thread_queue* queue; // Initialized to NULL
    struct os_thread_link link;
    struct os_mutex* mutex; // Initialized to NULL
    struct os_mutex_queue mutex_queue;
    void* stack_end_pointer;       // 0x90: Pointer to the end of the stack area (exclusive)
    void* stack_pointer;           // 0x94: Pointer to the start of the stack area (inclusive)
    uint32_t stack_warning_offset; // Initialized to 0
    struct os_thread_queue join_queue;
    // Initialized to 0.
    void* specific[3];
    struct osi_alarm* alarm_for_sleep; // Initialized to 0
    os_thread_destructor destructor;   // Initialized to NULL
    void* user_parameter;
    uint32_t system_errno;
};
ASSERT_SIZE(struct thread, 192);

// Language and flags of the DS firmware user settings.
struct language_and_flags {
    uint8_t language : 3;
    bool gba_mode_screen : 1;
    uint8_t backlight_level : 2;
    bool bootmenu_disable : 1;
    undefined field_0x7 : 1;
};
ASSERT_SIZE(struct language_and_flags, 1);

// Various pieces of user settings originating from the DS firmware.
// See https://problemkaputt.de/gbatek.htm#dsfirmwareusersettings
struct user_settings {
    struct language_and_flags language_and_flags;
    uint8_t favorite_color;
    uint8_t birthday_month;
    uint8_t birthday_day;
    uint16_t nickname[10]; // UTF-16 string
    undefined2 field_0x18; // always 0; null terminator for nickname?
    uint16_t nickname_length;
    uint16_t message[26];  // UTF-16 string
    undefined2 field_0x50; // always 0; null terminator for message?
    uint16_t message_length;
};
ASSERT_SIZE(struct user_settings, 84);

// Fields of the DS system clock.
struct system_clock {
    undefined4 field_0x0; // always 0
    int second;
    int minute;
    int hour;
    int day;
    int month;
    int year;
};
ASSERT_SIZE(struct system_clock, 28);

// IPv4 Internet domain socket address.
struct sockaddr_in {
    uint8_t len; // always 8
    uint8_t family;
    uint16_t port;
    uint8_t ip[4];
};
ASSERT_SIZE(struct sockaddr_in, 8);



typedef void (*os_irq_function)(void);

typedef void (*lock_ctrl_funcp)(void);

typedef void (*os_switch_thread_callback)(struct thread* from, struct thread* to);

typedef void (*pxi_fifo_callback)(enum pxi_fifo_tag tag, uint32_t data, bool err);

struct os_lock_word {
    uint32_t lock_flag;
    uint16_t owner_id;
    uint16_t extension;
};
ASSERT_SIZE(struct os_lock_word, 8);

struct card_rom_stat {
    void (*read_func)(struct card_rom_stat*);
    uint32_t ctrl;
    uint8_t* cache_page;
    uint32_t dummy[5];
    uint8_t cache_buf[512];
};
ASSERT_SIZE(struct card_rom_stat, 544);

struct ctrdg_rom_cycle {
    enum mi_cartridge_rom_cycle_1st c1;
    enum mi_cartridge_rom_cycle_2nd c2;
};
ASSERT_SIZE(struct ctrdg_rom_cycle, 8);

struct ctrdg_lock_by_proc {
    bool locked;
    uint8_t dummy[3];
    enum os_intr_mode irq;
};
ASSERT_SIZE(struct ctrdg_lock_by_proc, 8);

struct cardi_common {
    struct cardi_command_arg *cmd;
    int command;
    int32_t card_owner;
    int32_t lock_ref;
    struct os_thread_queue lock_queue[1];
    int lock_target; // enum CARDTargetMode
    uint32_t src;
    uint32_t dst;
    uint32_t len;
    uint32_t dma;
    int req_type; // enum CARDRequest
    int req_retry;
    int req_mode;
    void *callback; // MIDmaCallback
    void *callback_arg;
    void *task_func_ptr;
    struct thread thread[1];
    struct thread *cur_th;
    uint32_t priority;
    struct os_thread_queue busy_q[1];
    uint32_t flag;
    uint32_t flush_threshold_ic;
    uint32_t flush_threshold_dc;
    uint8_t backup_cache_page_buf[256];
};
ASSERT_SIZE(struct cardi_common, 0x220);

struct cardi_spec {
    uint32_t total_size;
    uint32_t sect_size;
    uint32_t subsect_size;
    uint32_t page_size;
    uint32_t addr_width;
    uint32_t program_page;
    uint32_t write_page;
    uint32_t write_page_total;
    uint32_t erase_chip;
    uint32_t erase_chip_total;
    uint32_t erase_sector;
    uint32_t erase_sector_total;
    uint32_t erase_subsector;
    uint32_t erase_subsector_total;
    uint32_t erase_page;
    uint8_t initial_status;
    uint8_t padding1[3];
    uint32_t caps;
    uint8_t padding2[4];
};
ASSERT_SIZE(struct cardi_spec, 0x48);

struct cardi_command_arg {
    int result; // enum CARDResult
    int type; // enum CARDBackupType
    uint32_t id;
    uint32_t src;
    uint32_t dst;
    uint32_t len;
    struct cardi_spec spec;
};
ASSERT_SIZE(struct cardi_command_arg, 0x60);

struct pm_sleep_callback_info {
    void *pm_sleep_callback;
    void *arg;
    struct pm_sleep_callback_info *next;
};
ASSERT_SIZE(struct pm_sleep_callback_info, 12);

struct engine_2d {
    undefined2 bg0_control;
    undefined2 bg1_control;
    undefined2 bg2_control;
    undefined2 bg3_control;
    undefined2 bg0_xy_offsets[2];
    undefined2 bg1_xy_offsets[2];
    undefined2 bg2_xy_offsets[2];
    undefined2 bg3_xy_offsets[2];
    undefined2 bg2_rot_scale_params[4];
    undefined4 bg2_ref_points_xy[2];
    undefined2 bg3_rot_scale_params[4];
    undefined4 bg3_ref_points_xy[2];
    undefined2 win_0_x_dim;
    undefined2 win_1_x_dim;
    undefined2 win_0_y_dim;
    undefined2 win_1_y_dim;
    undefined2 win_0_1_inside;
    undefined2 win_out_obj;
    undefined2 mosaic_size;
    undefined field19_0x46;
    undefined field20_0x47;
    undefined2 color_sfx;
    undefined2 alpha_blending;
    undefined2 fade_brightness;
    undefined field24_0x4e;
    undefined field25_0x4f;
};

struct display_engine_a {
    undefined4 disp_cnt;
    undefined2 disp_stat;
    undefined2 v_count;
    struct engine_2d engine_2d_a;
    undefined field4_0x58;
    undefined field5_0x59;
    undefined field6_0x5a;
    undefined field7_0x5b;
    undefined field8_0x5c;
    undefined field9_0x5d;
    undefined field10_0x5e;
    undefined field11_0x5f;
    undefined2 disp_3d_cnt;
    undefined field13_0x62;
    undefined field14_0x63;
    undefined4 disp_cap_cnt;
    undefined4 disp_mmem_fifo;
    undefined2 master_bright_a_2d;
    undefined field18_0x6e;
    undefined field19_0x6f;
};


struct display_engine_b {
    undefined4 disp_cnt;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    struct engine_2d engine_b_2d;
    undefined field6_0x58;
    undefined field7_0x59;
    undefined field8_0x5a;
    undefined field9_0x5b;
    undefined field10_0x5c;
    undefined field11_0x5d;
    undefined field12_0x5e;
    undefined field13_0x5f;
    undefined field14_0x60;
    undefined field15_0x61;
    undefined field16_0x62;
    undefined field17_0x63;
    undefined field18_0x64;
    undefined field19_0x65;
    undefined field20_0x66;
    undefined field21_0x67;
    undefined field22_0x68;
    undefined field23_0x69;
    undefined field24_0x6a;
    undefined field25_0x6b;
    undefined2 master_bright_2d_b;
    undefined field27_0x6e;
    undefined field28_0x6f;
};


struct engine_3d {
    undefined1 rd_line_count_reg;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined2 edge_colors[8];
    undefined1 alpha_test_ref;
    undefined field18_0x21;
    undefined field19_0x22;
    undefined field20_0x23;
    undefined field21_0x24;
    undefined field22_0x25;
    undefined field23_0x26;
    undefined field24_0x27;
    undefined field25_0x28;
    undefined field26_0x29;
    undefined field27_0x2a;
    undefined field28_0x2b;
    undefined field29_0x2c;
    undefined field30_0x2d;
    undefined field31_0x2e;
    undefined field32_0x2f;
    undefined4 clear_color;
    undefined2 clear_depth;
    undefined2 clear_img_offset;
    undefined4 fog_color;
    undefined2 fog_depth_offset;
    undefined field38_0x3e;
    undefined field39_0x3f;
    undefined1 fog_density_table[32];
    undefined2 toon_table[32];
    undefined field42_0xa0;
    undefined field43_0xa1;
    undefined field44_0xa2;
    undefined field45_0xa3;
    undefined field46_0xa4;
    undefined field47_0xa5;
    undefined field48_0xa6;
    undefined field49_0xa7;
    undefined field50_0xa8;
    undefined field51_0xa9;
    undefined field52_0xaa;
    undefined field53_0xab;
    undefined field54_0xac;
    undefined field55_0xad;
    undefined field56_0xae;
    undefined field57_0xaf;
    undefined field58_0xb0;
    undefined field59_0xb1;
    undefined field60_0xb2;
    undefined field61_0xb3;
    undefined field62_0xb4;
    undefined field63_0xb5;
    undefined field64_0xb6;
    undefined field65_0xb7;
    undefined field66_0xb8;
    undefined field67_0xb9;
    undefined field68_0xba;
    undefined field69_0xbb;
    undefined field70_0xbc;
    undefined field71_0xbd;
    undefined field72_0xbe;
    undefined field73_0xbf;
    undefined field74_0xc0;
    undefined field75_0xc1;
    undefined field76_0xc2;
    undefined field77_0xc3;
    undefined field78_0xc4;
    undefined field79_0xc5;
    undefined field80_0xc6;
    undefined field81_0xc7;
    undefined field82_0xc8;
    undefined field83_0xc9;
    undefined field84_0xca;
    undefined field85_0xcb;
    undefined field86_0xcc;
    undefined field87_0xcd;
    undefined field88_0xce;
    undefined field89_0xcf;
    undefined field90_0xd0;
    undefined field91_0xd1;
    undefined field92_0xd2;
    undefined field93_0xd3;
    undefined field94_0xd4;
    undefined field95_0xd5;
    undefined field96_0xd6;
    undefined field97_0xd7;
    undefined field98_0xd8;
    undefined field99_0xd9;
    undefined field100_0xda;
    undefined field101_0xdb;
    undefined field102_0xdc;
    undefined field103_0xdd;
    undefined field104_0xde;
    undefined field105_0xdf;
    undefined1 gx_fifo[64];
    undefined4 gx_command_ports[112];
    undefined4 gx_stat;
    undefined4 gx_ram_count;
    undefined field110_0x2e8;
    undefined field111_0x2e9;
    undefined field112_0x2ea;
    undefined field113_0x2eb;
    undefined field114_0x2ec;
    undefined field115_0x2ed;
    undefined field116_0x2ee;
    undefined field117_0x2ef;
    undefined2 disp_1_dot_depth;
    undefined field119_0x2f2;
    undefined field120_0x2f3;
    undefined field121_0x2f4;
    undefined field122_0x2f5;
    undefined field123_0x2f6;
    undefined field124_0x2f7;
    undefined field125_0x2f8;
    undefined field126_0x2f9;
    undefined field127_0x2fa;
    undefined field128_0x2fb;
    undefined field129_0x2fc;
    undefined field130_0x2fd;
    undefined field131_0x2fe;
    undefined field132_0x2ff;
    undefined1 pos_test_results[16];
    undefined1 vec_test_results[6];
    undefined field135_0x316;
    undefined field136_0x317;
    undefined field137_0x318;
    undefined field138_0x319;
    undefined field139_0x31a;
    undefined field140_0x31b;
    undefined field141_0x31c;
    undefined field142_0x31d;
    undefined field143_0x31e;
    undefined field144_0x31f;
    undefined1 clipmtx_results[64];
    undefined1 vecmtx_results[36];
};



#endif
