#ifndef HEADERS_TYPES_COMMON_SCRIPT_H_
#define HEADERS_TYPES_COMMON_SCRIPT_H_

#include "file.h"

// Seems to be a decompressed .fsb script file. Maybe someone else has researched this topic? :P
struct script_file {
    int unk_pointer_0x0;
    void* unk_ptr_0x4;
    void* unk_ptr_0x8;
    char* unk_ptr_0xC;
    int zero;
};
ASSERT_SIZE(struct script_file, 20);

struct script_data {
    char script_file_name[12];
    undefined field1_0xc;
    undefined field2_0xd;
    undefined field3_0xe;
    undefined field4_0xf;
    undefined field5_0x10;
    undefined field6_0x11;
    undefined field7_0x12;
    undefined field8_0x13;
    undefined field9_0x14;
    undefined field10_0x15;
    undefined field11_0x16;
    undefined field12_0x17;
    undefined field13_0x18;
    undefined field14_0x19;
    undefined field15_0x1a;
    undefined field16_0x1b;
    undefined field17_0x1c;
    undefined field18_0x1d;
    undefined field19_0x1e;
    undefined field20_0x1f;
    struct script_file* script_file_ptr;
    int script_file_offset;
    struct file_wrapper* script_file_wrapper;
    char subroutine_1_name[12]; // Not sure how subroutines 1 and 2 differ yet...
    undefined field25_0x38[552];
    int subroutine_1_is_active;
    char subroutine_2_name[12];
    undefined field28_0x270;
    undefined field29_0x271;
    undefined field30_0x272;
    undefined field31_0x273;
    int is_subroutine_2_active;
    int script_index;
};
ASSERT_SIZE(struct script_data, 636);

struct script_manager {
    undefined4* megastruct_field_0x14a8_ptr;
    struct script_data* system_script_data_ptr;
    struct script_data* area_script_data_ptr;
    struct script_data* chapter_script_data_ptr;
    struct script_data* quest_script_data_ptr;
    undefined4 unk_riding_pokemon_data;
    undefined4 field6_0x18;
    struct script_file
        chx_script_file; // Seems to be a raw script_file struct. What makes chx### so special?
    undefined field27_0x30;
    undefined field28_0x31;
    undefined field29_0x32;
    undefined field30_0x33;
    undefined field31_0x34;
    undefined field32_0x35;
    undefined field33_0x36;
    undefined field34_0x37;
    void* unk_struct_0x3c_ptr;
    undefined field36_0x3c[100320];
};
ASSERT_SIZE(struct script_manager, 100380);

#endif