#include "enums.h"
#include "common.h"

struct mega_substruct_1 {
    undefined4 unk_field_0x0;
    void* unk_struct_ptr_0x4; // Pointer to a struct of unknown size.
    undefined2 unk_field_0x8;
    undefined2 unk_field_0xa;
    undefined2 unk_field_0xc;
    undefined2 unk_field_0xe;
};
ASSERT_SIZE(struct mega_substruct_1, 16);

struct megastruct {
    undefined4 field0_0x0;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    int field5_0x8;
    void* unk_struct_unsized_0xc; // Pointer to a struct of unknown size.
    int field7_0x10;
    void* unk_struct_size_0x2c; // Seems to handle button inputs.
    void* unk_struct_size_0x30; // Seems to handle touch screen inputs
    void* unk_struct_size_0x54;
    int field11_0x20;
    // Supposedly a set of caches. Unsure what type it uses, but they're 1024 bytes long.
    undefined1 unk_cashe_1[1024];
    undefined1 unk_cache_2[1024];
    undefined1
        unk_cache_3[1024];      // This one is initialized differently than the others. Not sue why.
    void* unk_struct_size_0x4c; // Seems related to 2D and 3D background (?) display (2D Engine A,
                                // B, and 3D engine)
    void* unk_struct_size_0x4c_1; // Seems related to 2D and 3D background (?) display (2D Engine A,
                                  // B, and 3D engine)
    void* unk_struct_size_0x80;
    void* unk_struct_size_0x80_1;
    // This is likely a table of substructs. Not a clue what they do though!
    struct mega_substruct_1 struct_table_0xc34[128];
    void* unk_struct_size_0x8;
    void* unk_struct_size_0x10;
    struct battle_combatants* battle_combatants_ptr;
    void* field3832_0x1440; // "Initialized" by 0x02010C3C, but isn't actually modified???
    struct battle_exports* battle_exports_ptr;
    int32_t unk_int_0x1234;
    undefined4 field3835_0x144c;
    undefined4 field3836_0x1450;
    undefined4 field3837_0x1454;
    undefined4 field3838_0x1458;
    undefined4 field3839_0x145c;
    undefined4 field3840_0x1460;
    undefined4 field3841_0x1464;
    undefined4 field3842_0x1468;
    undefined field3843_0x146c[32];
    void* unk_struct_size_0x1ac; // Very likely related to sound, bgm, or sfx.
    // A pointer to this is present in the mission_quest_footer. Looks to be related to the message
    // given before a quest is accepted. Has ties to "data/message/quest/quest%03d_mes"
    void* unk_struct_size_0x158;
    void* unk_struct_size_0x44;
    void* unk_struct_size_0x40;
    // A pointer to this is present in the mission_quest_footer. Might be related to quest script
    // files "data/Script/quest/q%03d.fsb"
    void* unk_struct_size_0x1881C;
    struct mission_quest_data* mission_quest_data_ptr;
    struct ranger_data_old* ranger_data_ptr;
    undefined4 field3882_0x14a8;
    struct font_file_data *font_data_ptr_size_0x1c;
    struct group_msg_wrapper_table *group_msg_wrapper_table;
    struct settings_and_variables* settings_vars_ptr;
    void* unk_struct_size_0x28;
    void* unk_struct_size_0x1c;   // Might be related to sound registers? See FUN_0200E2D4
    void* unk_struct_size_0x1c_1; // Might be related to sound registers? See FUN_0200E2D4
    void*
        unk_struct_size_0xc7c; // Seems related to 2D display (2D Engine A and B), See FUN_200E4A8.
    void* unk_struct_size_0xc7c_1; // Seems related to 2D display (2D Engine A and B), See
                                   // FUN_200E4A8.
    struct field_data *field_data_ptr;
    void* field3892_0x14d0[32];    // These appear to be functions for the below param_0s
    int field3893_0x1550[32];      // These appear to be param_0 for the above functions
    undefined4 field4021_0x15d0;
    undefined4 field4022_0x15d4;
    void* unk_struct_size_0x58;
    undefined field4024_0x15dc;
    undefined field4025_0x15dd;
    undefined field4026_0x15de;
    undefined field4027_0x15df;
    undefined4 field4028_0x15e0;
};

ASSERT_SIZE(struct megastruct, 5604);