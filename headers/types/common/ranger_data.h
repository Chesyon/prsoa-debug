#ifndef HEADERS_TYPES_COMMON_RANGER_DATA_H_
#define HEADERS_TYPES_COMMON_RANGER_DATA_H_

#include "enums.h"
#include "common.h"

struct ranger_data {
    struct ranger_core_data core_data;
    struct trigger_spawn_nibbles
        map_triggers[441]; // This is really 441 sets of 48 nibbles. One for each map!
    struct pokemon_spawn_nibbles pokemon_spawns[441]; // This is really 441 sets of 32 nibbles!
    struct npc_spawn_nibbles npc_spawns[441];         // This is really 441 sets of 32 nibbles!
    struct target_destroyed_nibbles
        targets_destroyed[441]; // This is really 441 sets of 32 nibbles!
    undefined4 field4_0x7c38;   // Related to battle result somehow...
    struct ranger_pokedex pokedex;
    struct ranger_glossary glossary;
    long long map_and_fly_bitfield; // Seems to handle world map unlocks as a bitfield. Something
                                    // like 37 bits long? More research needed.
    // This block of fields seems to be related to wandering enemies. More research needed.
    undefined4 field7_0x7f68;
    undefined2 field8_0x7f6c;
    undefined2 field9_0x7f6e[63];
    undefined2 field10_0x7fec[10];
    undefined4 field11_0x8000[27];
    undefined2 field12_0x806c[64];
    undefined2 field13_0x80ec[32];
    undefined2 field14_0x812c[32];
    undefined2 field15_0x816c[32];
    undefined4 field16_0x81ac;
    undefined4 field17_0x81b0;
    undefined4 field18_0x81b4;
    undefined4 field19_0x81b8[31];
    undefined4 field20_0x8234[48];
    undefined2 field21_0x82f4[160];
    undefined2 field22_0x8434;
    undefined2 field23_0x8436[32];
    undefined2 field24_0x8476[48];
    undefined2 field25_0x84d6[32];
    undefined2 field26_0x8516[48];
    undefined2 field27_0x8576[32];
    undefined2 field28_0x85b6[48];
    undefined2 field29_0x8616[32];
    undefined2 field30_0x8656[48];
    undefined2 field31_0x86b6[32];
    undefined2 field32_0x86f6[48];
    undefined1 field33_0x8756;
    int8_t player_language; // 0 if JP/NA. EU: eng = 1 fre = 2 ger = 3, ita = 4 spa = 5
    struct ranger_records records;
    // struct styler_upgrades styler_upgrades;
    enum styler_upgrade_level grass_defense : 2;
    enum styler_upgrade_level water_defense : 2;
    enum styler_upgrade_level electric_defense : 2;
    enum styler_upgrade_level fire_defense : 2;

    enum styler_upgrade_level fighting_defense : 2;
    enum styler_upgrade_level poison_defense : 2;
    enum styler_upgrade_level psychic_defense : 2;
    enum styler_upgrade_level bug_defense : 2;

    enum styler_upgrade_level ground_defense : 2;
    enum styler_upgrade_level flying_defense : 2;
    enum styler_upgrade_level dark_defense : 2;
    enum styler_upgrade_level rock_defense : 2;

    enum styler_upgrade_level ghost_defense : 2;
    enum styler_upgrade_level ice_defense : 2;
    enum styler_upgrade_level normal_defense : 2;
    enum styler_upgrade_level steel_defense : 2;

    enum styler_upgrade_level dragon_defense : 2;
    enum styler_upgrade_level time_assist : 2;
    enum styler_upgrade_level latent_power : 2;
    enum styler_upgrade_level combo_bonus : 2;

    enum styler_upgrade_level recovery : 2;
    enum styler_upgrade_level energy_plus : 2;
    enum styler_upgrade_level power_plus : 2;
    enum styler_upgrade_level long_line : 2;
    undefined field_0x88e2;
    char player_name[7];
    undefined1 field38_0x87ea[22];
    undefined1 field33832_0x8800[2];
    struct mount_species_8 current_mount;
    bool can_partner_poke_assist; // Needs more testing.
};

ASSERT_SIZE(struct ranger_data, 34820);

// I have reason to doubt this struct is as long as it is. I may be splitting it, but until I'm sure
// I want it split, it's going to be ranger_data_old... That said, Ghidra has a better time
// recognizing these fields as one large struct. Occasionally the game references this struct with a
// large offset, when referring what I believe to to a completely different struct in all other
// ways. This is my solution to that problem...
struct ranger_data_old {
    struct ranger_data ranger_data_new;
    // There appear to be 3 tables of recruited pokemon, each with 10 entries. Of those, only 8 per
    // table are actually stored in the save file.
    struct pokemon_data recruited_pokemon_tables[3][10];
    struct following_npc follower_1;
    struct following_npc follower_2;
    char debug_string_buffer[32]; // Seems to hold the contents of various debug text.
    struct battle_result_8 battle_result;
    undefined field48_0x8b65;
    undefined field49_0x8b66;
    undefined field50_0x8b67;
    undefined4 field51_0x8b68;
    undefined4 field52_0x8b6c;
    undefined4 field53_0x8b70;
    undefined4 unk_battle_value;
    undefined2 field55_0x8b78;
    undefined2 field56_0x8b7a;
    undefined4 field57_0x8b7c;
    undefined4 field58_0x8b80;
    undefined4 field59_0x8b84;
    undefined4 field60_0x8b88;
    undefined4 field61_0x8b8c;
    undefined4 field62_0x8b90;
    undefined4 field63_0x8b94;
    undefined4 field64_0x8b98;
    undefined4 field65_0x8b9c;
    undefined4 field66_0x8ba0;
    undefined field67_0x8ba4[44];
    struct pokemon_data recruited_pokemon_tables_backup[3][10];
    struct following_npc follower_1_backup;
    struct following_npc follower_2_backup;
    char debug_string_buffer_backup[32]; // Seems to hold the contents of various debug text.
    struct battle_result_8 battle_result_backup;
    undefined field67_0x8f31;
    undefined field68_0x8f32;
    undefined field69_0x8f33;
    undefined4 field70_0x8f34;
    undefined4 field71_0x8f38;
    undefined4 field72_0x8f3c;
    undefined4 unk_battle_value_backup;
    undefined2 field73_0x8f40;
    undefined2 field74_0x8f42;
    undefined4 field75_0x8f44;
    undefined4 field76_0x8f48;
    undefined4 field77_0x8f4c;
    undefined4 field78_0x8f50;
    undefined4 field79_0x8f54;
    undefined4 field80_0x8f58;
    undefined4 field81_0x8f5c;
    undefined4 field82_0x8f60;
    undefined4 field83_0x8f64;
    undefined4 field84_0x8f68;
    undefined field84_0x8f70[330384];
    int field330536_0x59a00;
    int field330537_0x59a04[63];
    // 0x2017AA4 NA says it's this big at least. It might be larger!
};
ASSERT_SIZE(struct ranger_data_old, 367360);

#endif