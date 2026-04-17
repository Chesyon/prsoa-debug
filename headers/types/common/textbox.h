#ifndef HEADERS_TYPES_COMMON_TEXTBOX_H_
#define HEADERS_TYPES_COMMON_TEXTBOX_H_

#include "file.h"

// Note: uncompressed .mes files store these as non-pointers after their header.
struct msg {
    int* len;  // Length of the message in characters
    char* str; //
};
ASSERT_SIZE(struct msg, 8);

struct msg_wrapper {
    uint32_t file_len;
    uint32_t num_strings;
    struct msg* msg_ptrs;
};
ASSERT_SIZE(struct msg_wrapper, 12);

struct group_msg_wrapper_table {
    struct msg_wrapper* pkmn_name_msg_wrapper;
    struct msg_wrapper* item_name_msg_wrapper;
    struct msg_wrapper* target_name_msg_wrapper;
    struct msg_wrapper* npc_name_msg_wrapper;
    struct msg_wrapper* field_move_name_msg_wrapper;
};
ASSERT_SIZE(struct group_msg_wrapper_table, 20);

struct unk_font_substruct {
    void* unk_struct_unsized_ptr; // Seems to be a larger struct, unknown in size
    void* unk_func_ptr;           // Seems to point to a function, called as one.
};
ASSERT_SIZE(struct unk_font_substruct, 8);

struct font_file_data {
    struct file_wrapper* font_file_wrapper_ptr;
    struct file_wrapper*
        font_lc_file_wrapper_ptr; // lc may stand for "lowercase" or "large characters"
    undefined field2_0x8;         // Seems entirely unused
    undefined field3_0x9;
    undefined field4_0xa;
    undefined field5_0xb;
    struct unk_font_substruct font_normal;
    struct unk_font_substruct font_lc;
};

struct textbox_subdata {
    undefined4 field0_0x0;
    undefined field1_0x4[128][10]; // Some kind of table. Maybe a table of structs?
    undefined field2_0x504[4352];
    undefined4 field4354_0x1604;
    int is_yes_no_menu_printing; // Seems to check if associated dialogue with a yes_no_menu is
                                 // active?
    int yes_no_result;           // Seems to store the result of a yes_no_menu.
    undefined4 field4357_0x1610;
    undefined4 field4358_0x1614;
    undefined4 field4359_0x1618;
    undefined4 field4360_0x161c;
    undefined4 field4361_0x1620[4];
    undefined4 field4362_0x1630;
    undefined4 field4363_0x1634;
    struct unk_font_substruct* unk_font_substruct_ptr;
};
ASSERT_SIZE(struct textbox_subdata, 5692);

struct textbox_data {
    struct group_msg_wrapper_table *group_msg_wrapper_table_ptr;
    struct msg_wrapper *system_msg_wrapper_ptr;
    struct msg_wrapper *area_msg_wrapper_ptr;
    struct msg_wrapper *chapter_msg_wrapper_ptr;
    struct msg_wrapper *quest_msg_wrapper_ptr;
    struct msg_wrapper *battle_msg_wrapper_ptr;
    int system_script_id;
    int area_script_id;
    int chapter_script_id;
    int quest_script_id;
    undefined4 battle_script_id;
    void* field11_0x2c;
    char unk_buffer[24];
    char* unk_string_ptr; // Certain interactions cause the string to also appear here.
    undefined4 field14_0x4c;
    // 0: Finished Printing, 1: Actively Printing, 2: Resuming From Page Transition, 3: Page
    // Transition, 5: Awaiting textbox close. 9: Yes-No Menu active
    int textbox_print_status;
    int is_custom_text_speed;
    int is_auto_advance_text_on;
    int auto_advance_text_delay;
    int auto_advance_text_timer;
    int is_auto_close_text_on;
    int auto_close_text_delay;
    int auto_close_text_timer;
    int window_setting;
    int default_text_speed;
    int text_size;        // 0 = normal, 1 = double-size, 2+ unknown
    char* current_string; // Increments to the last printed character!
    int field27_0x80;
    void* field28_0x84;
    struct controller_inputs* controller_inputs_ptr;
    struct touch_screen* touch_screen_ptr;
    void* field31_0x90;
    void* field32_0x94;
    undefined4 field33_0x98;
    int current_text_speed; // Pointer appears to be altered for varied text speeds.
    undefined4 field35_0xa0;
    int text_coordinates[2];
    int font_color; // Default is 0x4, red is 0x7, others unknown.
    int field38_0xb0;
    undefined4 field39_0xb4[16]; // Explicit Size not found, only references to start of the table
    struct unk_font_substruct* unk_font_substruct_ptr_1;
    void* field41_0xf8; // Not supported by live analysis, but see 0x200976C NA.
    undefined4 field42_0xfc;
    undefined4 field43_0x100;
    undefined4 field44_0x104;
    undefined4 field45_0x108;
    void* field46_0x10c;
    void* field47_0x110;
    struct unk_font_substruct* unk_font_substruct_ptr_2;
    undefined4 field49_0x118;
    undefined4 field50_0x11c;
    void* field51_0x120; // Not supported by live analysis, but see 0x200976C NA.
    undefined4 field52_0x124;
    undefined4 field53_0x128;
    undefined4 field54_0x12c;
    undefined4 field55_0x130;
    void* field56_0x134;
    void* field57_0x138;
    struct unk_font_substruct* unk_font_substruct_ptr_3;
    undefined4 field59_0x140;
    undefined4 field60_0x144;
    undefined4 field61_0x148;
    struct textbox_subdata* textbox_subdata_ptr;
    int script_kind; // 0 = SYS, 1 = AREA, 2 = CHAP, 3 = QUE, 4 = BAT
    int message_id;
};
ASSERT_SIZE(struct textbox_data, 344);

#endif