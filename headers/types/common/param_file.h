#ifndef HEADERS_TYPES_COMMON_PARAM_FILE_H_
#define HEADERS_TYPES_COMMON_PARAM_FILE_H_

struct param_file_header {
    int file_size;
    int param_encoding_size;
    int table_size_file;
    int table_size_ram;
};
ASSERT_SIZE(struct param_file_header, 16);

struct param_file_data {
    struct file_wrapper* file_wrapper_ptr;
    struct param_file_header* param_file_header_ptr;
    undefined4 unk_megastruct_field_0x14a8;
    struct param_encoding_8* param_encoding_ptr;
    undefined4* ram_table_expanded_ptr;
    int param_encoding_size;
    int ram_table_size;
    int ram_table_entry_size;
};
ASSERT_SIZE(struct param_file_data, 32);

// Only field sizes are currently known.
struct battle_assist_entry_ram {
    undefined2 field0_0x0;
    undefined2 field1_0x2;
    undefined2 field2_0x4;
    undefined2 field3_0x6;
    undefined2 field4_0x8;
    undefined2 field5_0xa;
    undefined2 field6_0xc;
    undefined2 field7_0xe;
    undefined2 field8_0x10;
    undefined2 field9_0x12;
    undefined2 field10_0x14;
    undefined2 field11_0x16;
    undefined2 field12_0x18;
    undefined2 field13_0x1a;
    undefined2 field14_0x1c;
    undefined2 field15_0x1e;
    undefined2 field16_0x20;
    undefined2 field17_0x22;
    undefined2 field18_0x24;
    undefined2 field19_0x26;
    undefined2 field20_0x28;
    undefined2 field21_0x2a;
    undefined2 field22_0x2c;
    undefined2 field23_0x2e;
    undefined2 field24_0x30;
};
ASSERT_SIZE(struct battle_assist_entry_ram, 50);

// Initialized in overlay_01.
struct battle_assist_table_wrapper {
    uint16_t ram_table_entry_size;
    undefined field1_0x2;
    undefined field2_0x3;
    struct battle_assist_entry_ram* entry_table_ptr;
};
ASSERT_SIZE(struct battle_assist_table_wrapper, 8);

// Only field sizes are currently known.
// May be the same as battle_assist_entry_ram. More research needed.
struct battle_assist_entry_rom {
    undefined2 field0_0x0;
    undefined2 field1_0x2;
    undefined2 field2_0x4;
    undefined2 field3_0x6;
    undefined2 field4_0x8;
    undefined2 field5_0xa;
    undefined2 field6_0xc;
    undefined2 field7_0xe;
    undefined2 field8_0x10;
    undefined2 field9_0x12;
    undefined2 field10_0x14;
    undefined2 field11_0x16;
    undefined2 field12_0x18;
    undefined2 field13_0x1a;
    undefined2 field14_0x1c;
    undefined2 field15_0x1e;
    undefined2 field16_0x20;
    undefined2 field17_0x22;
    undefined2 field18_0x24;
    undefined2 field19_0x26;
    undefined2 field20_0x28;
    undefined2 field21_0x2a;
    undefined2 field22_0x2c;
    undefined2 field23_0x2e;
    undefined2 field24_0x30;
};
ASSERT_SIZE(struct battle_assist_entry_rom, 50);

// File structure of "param/BattleAssist.bin" and "param/BattleAssistPartner.bin"
#pragma pack(push, 1) // This is usually stored as a 5042 byte struct.
struct battle_assist_bin {
    struct param_file_header header; // 0x0
    struct param_encoding_8 encodings[26]; // 0x10
    struct battle_assist_entry_rom battle_assist_entries[100]; // 0x2A
};
ASSERT_SIZE(struct battle_assist_bin, 5042);
#pragma pack(pop) // Restore alignment

// Only field sizes are currently known.
struct battle_effect_entry_ram {
    undefined2 field0_0x0;
    undefined2 field1_0x2;
    undefined4 field2_0x4;
    undefined1 field3_0x8;
    undefined field4_0x9; // Padding
    undefined field5_0xa; // Padding
    undefined field6_0xb; // Padding
    undefined4 field7_0xc;
    undefined1 field8_0x10;
    undefined1 field9_0x11;
    undefined1 field10_0x12;
    undefined1 field11_0x13;
    undefined1 field12_0x14;
    undefined1 field13_0x15;
    undefined1 field14_0x16;
    undefined1 field15_0x17;
    undefined1 field16_0x18;
    undefined1 field17_0x19;
    undefined1 field18_0x1a;
    undefined1 field19_0x1b;
};
ASSERT_SIZE(struct battle_effect_entry_ram, 28);

// Initialized in overlay_01.
struct battle_effect_table_wrapper {
    uint16_t table_entry_size;
    undefined field1_0x2;
    undefined field2_0x3;
    struct battle_effect_entry_ram* entry_table_ptr;
};
ASSERT_SIZE(struct battle_effect_table_wrapper, 8);

// Only field sizes are currently known.
#pragma pack(push, 1) // This is usually stored as a 17 byte struct.
struct battle_effect_entry_rom {
    undefined2 field0_0x0;
    undefined1 field1_0x2;
    undefined1 field2_0x3;
    undefined1 field3_0x4;
    undefined1 field4_0x5;
    undefined1 field5_0x6;
    undefined1 field6_0x7;
    undefined1 field7_0x8;
    undefined1 field8_0x9;
    undefined1 field9_0xa;
    undefined1 field10_0xb;
    undefined1 field11_0xc;
    undefined1 field12_0xd;
    undefined1 field13_0xe;
    undefined1 field14_0xf;
    undefined1 field15_0x10;
};
#pragma pack(pop) // Restore alignment
ASSERT_SIZE(struct battle_effect_entry_rom, 17);

#pragma pack(push, 1) // This is usually stored as a 4929 byte struct.
// File structure of "param/BattleEffect.bin"
struct battle_effect_bin {
    struct param_file_header header;
    struct param_encoding_8 encodings[17];
    struct battle_effect_entry_rom battle_effect_entries[288];
};
#pragma pack(pop) // Restore alignment
ASSERT_SIZE(struct battle_effect_bin, 4929);

struct battle_pokemon_entry_ram {
    int16_t friendship_gauge;
    undefined2 field1_0x2;
    undefined1 field2_0x4;
    undefined1 field3_0x5;
    undefined1 field4_0x6;
    undefined1 field5_0x7;
    undefined1 field6_0x8;
    undefined1 field7_0x9;
    undefined1 field8_0xa;
    undefined1 field9_0xb;
    undefined2 field10_0xc;
    undefined1 field11_0xe;
    undefined1 field12_0xf;
    undefined1 field13_0x10;
    undefined1 field14_0x11;
    undefined1 field15_0x12;
    undefined1 field16_0x13;
    undefined1 field17_0x14;
    undefined1 field18_0x15;
    undefined1 field19_0x16;
    undefined1 field20_0x17;
};
ASSERT_SIZE(struct battle_pokemon_entry_ram, 24);

// Initialized in overlay_01.
struct battle_pokemon_table_wrapper {
    uint16_t table_entry_size;
    undefined field1_0x2;
    undefined field2_0x3;
    struct battle_pokemon_entry_ram* entry_table_ptr;
};
ASSERT_SIZE(struct battle_pokemon_table_wrapper, 8);

#pragma pack(push, 1) // This struct has intentionally bad alignment.
struct battle_pokemon_entry_rom {
    int8_t field0_0x0;
    int16_t friendship_gauge;
    int16_t field2_0x3;
    int8_t field3_0x5;
    int8_t field4_0x6;
    int8_t field5_0x7;
    int8_t field6_0x8;
    int8_t field7_0x9;
    int8_t field8_0xa;
    int8_t field9_0xb;
    int16_t field10_0xc;
    int8_t field11_0xe;
    int8_t field12_0xf;
    int8_t field13_0x10;
    int8_t field14_0x11;
    int8_t field15_0x12;
    int8_t field16_0x13;
    int8_t field17_0x14;
    int8_t field18_0x15;
    int8_t field19_0x16;
    int8_t field20_0x17;
};
#pragma pack(pop) // Restore alignment
ASSERT_SIZE(struct battle_pokemon_entry_rom, 24);

#pragma pack(push, 1) // This struct has intentionally bad alignment.
// File structure of "param/BattlePokemon.bin"
struct battle_pokemon_bin {
    struct param_file_header header;
    struct param_encoding_8 encodings[22];
    struct battle_pokemon_entry_rom battle_pokemon_entries[500];
};
#pragma pack(pop) // Restore alignment
ASSERT_SIZE(struct battle_pokemon_bin, 12038);

// Lives in megastruct.
struct disk_hp_table_wrapper {
    int8_t ram_table_entry_size;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    // Unlike the others, this is NOT a disk_hp_entry_ram pointer!
    // See poke_id_table_wrapper for reference, which has a poke_id_entry_ram pointer at this address.
    int8_t* unk_byte_a_table_0x4;
    int16_t* unk_hword_b_table_0x8;
    int16_t* unk_hword_c_table_0xC;
};
ASSERT_SIZE(struct disk_hp_table_wrapper, 16);

#pragma pack(push, 1) // This is usually stored as a 5 byte struct.
struct disk_hp_entry_rom {
    int8_t unk_byte_a_0x0;
    int16_t unk_hword_b_0x1;
    int16_t unk_hword_c_0x3;
};
ASSERT_SIZE(struct disk_hp_entry_rom, 5);
#pragma pack(pop) // Restore alignment

// File structure of "param/DiskHp.bin"
struct disk_hp_bin {
    struct param_file_header disk_hp_header;
    struct param_encoding_8 encodings[4];
    struct disk_hp_entry_rom disk_hp_entries[100];
};
ASSERT_SIZE(struct disk_hp_bin, 520);

struct poke_id_entry_ram {
    int16_t name_string_id;
    int8_t form_index;
    int8_t species_type;
    int8_t poke_assist_type;
    int8_t field_move_id;
    int8_t field_move_level;
    int8_t field6_0x7;
    int8_t field7_0x8;
    int8_t field8_0x9;
    int8_t field9_0xa;
    int8_t field10_0xb;
    int8_t field11_0xc;
    int8_t field12_0xd;
    int8_t field13_0xe;
    int8_t field14_0xf;
    int16_t field15_0x10;
    int16_t field16_0x12;
    int32_t field17_0x14;
};
ASSERT_SIZE(struct poke_id_entry_ram, 24);

// Lives in megastruct.
struct poke_id_table_wrapper {
    uint16_t entry_table_size;
    undefined field1_0x2;
    undefined field2_0x3;
    struct poke_id_entry_ram* entry_table_ptr;
};
ASSERT_SIZE(struct poke_id_table_wrapper, 8);

struct poke_id_entry_rom {
    int16_t name_string_id;
    int8_t form_index; // Index of the alternate form of this pokemon (IE: Sunny/Shaded Cherrim)
    int8_t species_type;
    int8_t poke_assist_type;
    int8_t field_move_id;
    int8_t field_move_level;
    undefined1 field5_0x7;
    undefined1 field6_0x8;
    undefined1 field7_0x9;
    undefined1 field8_0xa;
    undefined1 field9_0xb;
    int8_t shadow_width;
    int8_t shadow_height;
    undefined1 field12_0xe;
    undefined1 field13_0xf;
    undefined1 field14_0x10;
    undefined1 field15_0x11;
    undefined1 field16_0x12;
    undefined1 field17_0x13;
    undefined2 field18_0x14;
    undefined2 field19_0x16;
    undefined4 field20_0x18;
};
ASSERT_SIZE(struct poke_id_entry_rom, 28);

// File structure of "param/PokeId.bin"
struct poke_id_bin {
    struct param_file_header header;
    struct param_encoding_8 encodings[24];
    struct poke_id_entry_rom poke_id_entries[500];
};
ASSERT_SIZE(struct poke_id_bin, 14040);

#endif