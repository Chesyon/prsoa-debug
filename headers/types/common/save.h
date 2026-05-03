#ifndef HEADERS_TYPES_COMMON_SAVE_H_
#define HEADERS_TYPES_COMMON_SAVE_H_

struct c_backup {
    void **c_backup_vftable_ptr;
    undefined4 card_lock_id;
    undefined4 lock_id;
    undefined4 card_available;
    undefined4 field4_0x10;
};
ASSERT_SIZE(struct c_backup, 20);

struct c_backup_sync {
    struct c_backup c_backup;
    undefined field1_0x14;
    undefined field2_0x15;
    undefined field3_0x16;
    undefined field4_0x17;
    undefined field5_0x18;
    undefined field6_0x19;
    undefined field7_0x1a;
    undefined field8_0x1b;
    undefined field9_0x1c;
    undefined field10_0x1d;
    undefined field11_0x1e;
    undefined field12_0x1f;
    undefined field13_0x20;
    undefined field14_0x21;
    undefined field15_0x22;
    undefined field16_0x23;
    undefined field17_0x24;
    undefined field18_0x25;
    undefined field19_0x26;
    undefined field20_0x27;
};
ASSERT_SIZE(struct c_backup_sync, 40);

struct save_pokemon_field {
    struct pokemon_data *pointer;
    unsigned int size; // Always 0x18
};
ASSERT_SIZE(struct save_pokemon_field, 8);

struct save_follower_field {
    struct following_npc *pointer;
    unsigned int size; // Always 0x38
};
ASSERT_SIZE(struct save_follower_field, 8);

struct save_ranger_data_field {
    struct ranger_data *pointer;
    unsigned int size; // Always 0x8804
};
ASSERT_SIZE(struct save_ranger_data_field, 8);

struct save_mission_quest_header_field {
    struct mission_quest_header *pointer; // points to the header!!!
    unsigned int size; // Always size 0x54
};
ASSERT_SIZE(struct save_mission_quest_header_field, 8);

struct save_settings_variables_field {
    struct settings_and_variables *pointer;
    unsigned int size; // Always size 0xFC
};
ASSERT_SIZE(struct save_settings_variables_field, 8);

// For unknown save field types.
struct save_field {
    void *field_ptr;
    unsigned int field_size;
};
ASSERT_SIZE(struct save_field, 8);

struct save_block_fields {
    struct save_ranger_data_field ranger_data;
    struct save_pokemon_field land_pokemon[8]; // Excludes slots 9 and 10
    struct save_pokemon_field ocean_pokemon[8]; // Excludes slots 9 and 10
    struct save_pokemon_field capture_zone_pokemon[8]; // Excludes slots 9 and 10
    struct save_follower_field following_npcs[2];
    struct save_mission_quest_header_field mission_quest_header;
    struct save_settings_variables_field settings_and_variables;
    struct save_field field7_0xe8;
    struct save_field field8_0xf0;
    struct save_field field9_0xf8;
    struct save_field field10_0x100;
    struct save_field field11_0x108[2];
    struct save_field field12_0x118;
    struct save_field field13_0x120;
};
ASSERT_SIZE(struct save_field, 8);

struct save_header {
    char game_mark[0x8];    // 0x0: For this game, is DSPRS
    int main_save_0_offset; // 0x8: Should be 0x1C
    int main_save_1_offset; // 0xC: Should be 0x949E
    int checksum;           // 0x10
    int newest_save_index;  // 0x14: 00 = main_save_0, 01 = main_save_1, 02+ unknown.
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
};

ASSERT_SIZE(struct save_header, 28);

struct save_data {
    struct ranger_data ranger_data_struct; // 0x0
    // Of the 30 pokemon slots, only the first 8 of each group are stored in the save file...
    struct pokemon_data party_group_0[8];           // 0x8804
    struct pokemon_data party_group_1[8];           // 0x88C4
    struct pokemon_data party_group_2[8];           // 0x8984
    struct following_npc follower_1;                // 0x8A44
    struct following_npc follower_2;                // 0x8A7C
    struct mission_quest_header mission_quest_data; // 0x8AB4
    // Consists of event flags,
    struct settings_and_variables settings_and_variables; // 0x8B08
    undefined unk_field_0x8c04[96];                       // 0x8C04: Permanent home is 0x210C1C0
    struct battle_init battle_init;                       // 0x8C64: Permanent home is 0x210C228
    // 0x9464: Seems to always be 0x1F2E3D4C. If it isn't, the save file is treated as corrupt!
    int unk_field_0x9464;
    undefined unk_field_0x9468[8];      // 0x9468: Permanent home is 0x20AF5E4
    undefined unk_field_0x9470[8];      // 0x9470: Permanent home is 0x20AF5F8
    undefined unk_field_0x9478[8];      // 0x9478: Permanent home is 0x20AF60C
    int16_t ranger_net_completion_bits; // 0x9480
    undefined unk_field_0x9482;
    undefined unk_field_0x9483;
};

ASSERT_SIZE(struct save_data, 38020);

struct save_file {
    struct save_header main_save_header;  // 0x0
    struct save_data main_save_0;         // 0x1C
    struct save_data main_save_1;         // 0x94A0
    struct save_header quick_save_header; // 0x12924: Should be zeroed if quicksave not active.
    struct save_data quick_save; // 0x12940: So far, no reason to believe different from main save.
    int8_t ranger_net_mission1[0x3020]; // 0x1BDC4
    int8_t ranger_net_mission2[0x3020]; // 0x1EDE4
    int8_t ranger_net_mission3[0x3020]; // 0x21E04
    int8_t ranger_net_mission4[0x3020]; // 0x24E24
    int8_t ranger_net_mission5[0x3020]; // 0x27E44
    int8_t ranger_net_mission6[0x3020]; // 0x2AE64
};
ASSERT_SIZE(struct save_file, 188036);

struct unk_save_struct_0x74 {
    struct c_backup *field0_0x0;
    struct c_backup c_backup;
    struct c_backup_sync c_backup_sync;
    int field3_0x40;
    undefined field4_0x44;
    undefined field5_0x45;
    undefined field6_0x46;
    undefined field7_0x47;
    undefined field8_0x48;
    undefined field9_0x49;
    undefined field10_0x4a;
    undefined field11_0x4b;
    uint16_t field12_0x4c;
    undefined2 field13_0x4e;
    uint16_t field14_0x50;
    undefined2 field15_0x52;
    int field16_0x54;
    struct file_wrapper *unk_file_wrapper_ptr;
    int field18_0x5c;
    int field19_0x60;
    byte field20_0x64;
    undefined field21_0x65;
    uint16_t field22_0x66;
    void *field23_0x68;
    int field24_0x6c;
    int field25_0x70;
};
ASSERT_SIZE(struct unk_save_struct_0x74, 116);

struct unk_save_struct_0x8 {
    int16_t field0_0x0; // Usually 0x6C8F
    int16_t field1_0x2;
    int16_t field2_0x4;
    int16_t field3_0x6; // Usually 0xE97C
};
ASSERT_SIZE(struct unk_save_struct_0x8, 8);

struct unk_save_struct_0x14 {
    struct unk_save_struct_0x8 field0_0x0;
    undefined2 field1_0x8;
    undefined field2_0xa;
    undefined field3_0xb;
    undefined field4_0xc;
    undefined field5_0xd;
    undefined field6_0xe;
    undefined field7_0xf;
    undefined4 field8_0x10;
};
ASSERT_SIZE(struct unk_save_struct_0x14, 20);

#endif