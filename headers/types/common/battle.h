#ifndef HEADERS_TYPES_BATTLE_H_
#define HEADERS_TYPES_BATTLE_H_

#include "common.h"
#include "megastruct.h"
// Seems to be stored on the stack for the duration of the battle.
struct battle_struct {
    undefined4* function_ptr_0x0;
    struct megastruct* megastruct_ptr;
    int16_t field2_0x8;
    int16_t field3_0xa;
    unsigned int capture_rank_bit_field;
    int* field5_0x10;
    undefined field6_0x14;
    undefined field7_0x15;
    undefined field8_0x16;
    undefined field9_0x17;
    int field10_0x18;
    struct battle_combatants* battle_combatants_ptr;
    int current_battle_state;
    int previous_battle_state;
    int time_in_battle_frames;
    int16_t field15_0x2c;
    int16_t field16_0x2e;
    int16_t maybe_styler_power; // This quantity is boosted by styler upgrade 0x16.
    undefined field18_0x32;
    undefined field19_0x33;
    int num_new_lines_drawn;
    int num_times_taken_damage;
    int consecutive_loops_made;
    int field23_0x40;
    int8_t num_caught_pokemon;
    undefined field25_0x45;
    int16_t caught_form_ids[8];
    int16_t field27_0x56;
    int total_loops_made;
    undefined field29_0x5c;
    int8_t unk_table_0x5e_index;
    int16_t unk_table_0x5e[4];
    undefined field32_0x66;
    undefined field33_0x67;
    int field34_0x68;
    int16_t fight_end_animation_timer;
    undefined field36_0x6e;
    undefined field37_0x6f;
    int field38_0x70;
    int partner_assist_gauge_current;
    int partner_assist_gauge_max;
    int maybe_partner_assist_gauge_increment;
    int8_t partner_something_1;
    int8_t styler_charge_amount;
    int16_t party_form_ids[8];
    bool poke_assists_available[8];
    bool poke_assists_used[8];
    undefined field47_0xa2;
    undefined field48_0xa3;
    int8_t* poke_assists_used_ptrs[8];
    int* unk_struct_size_0x3C_ptrs[3]; // May live at +0x2468 from the start of this struct!
    int8_t* field51_0xd0;
    int field52_0xd4;
    int* field53_0xd8;
    undefined4* mystery_struct_ptrs[8];
    int field55_0xfc[4];
    int field56_0x10c[8];
    int* field57_0x12c;
    int* field58_0x130[96]; // Mostly size 0x7DC, but the first few aren't...
    int* field59_0x2b0[18];
    int* field60_0x2f8[32]; // Mostly size 0x7DC, but the first few aren't...
    int field61_0x378[3];
    int* partner_something_ptr;
    int* recruit_something_ptrs[8];
    int* unk_struct_size_0xC4_ptrs[512]; // May live at +0x4B6C from the start of this struct!
    int field65_0xba8;
    undefined4 field66_0xbac;
    int* field67_0xbb0;
    int* field68_0xbb4;
    int field69_0xbb8;
    int* field70_0xbbc;
    int field71_0xbc0;
    int* unk_struct_size_0x24_ptrs[8];
    undefined field73_0xbe4;
    undefined field74_0xbe5;
    undefined field75_0xbe6;
    undefined field76_0xbe7;
    int field77_0xbe8;
    int field78_0xbec;
    int field79_0xbf0;
    int field80_0xbf4;
    int field81_0xbf8;
    int field82_0xbfc;
    int field83_0xc00;
    int field84_0xc04;
    int field85_0xc08;
    int field86_0xc0c;
    undefined4* battle_graphic_struct_ptr;
    int field88_0xc14;
    int* unk_struct_size_0x18_ptrs[3];
    int field90_0xc24;
    int field91_0xc28;
    int* field92_0xc2c;
    int field93_0xc30;
    int field94_0xc34;
    int field95_0xc38;
    undefined field96_0xc3c;
    undefined field97_0xc3d;
    undefined field98_0xc3e;
    undefined field99_0xc3f;
    int field100_0xc40;
    int* field101_0xc44;
    int* field102_0xc48;
    // Not confirmed to be a continuous field
    undefined fields1_0xc4c[516];
    int field619_0xe50;
    // Not confirmed to be a continuous field
    undefined fields2_0xe54[28];
    int* field648_0xe70;
    int field649_0xe74;
    // Not confirmed to be a continuous field
    undefined fields3_0xc4c[516];
    int field1166_0x107c;
    // Not confirmed to be a continuous field
    undefined fields4_0x1080[28];
    int* field1195_0x109c;
    int field1196_0x10a0;
    // Not confirmed to be a continuous field
    undefined field1197_0x10a4[516];
    int field1713_0x12a8;
    // Not confirmed to be a continuous field
    undefined field1714_0x12ac[28];
    int field1742_0x12c8;
    int field1743_0x12cc;
    int field1744_0x12d0;
    int field1745_0x12d4;
    int field1746_0x12d8;
    int field1747_0x12dc;
    int field1748_0x12e0;
    int field1749_0x12e4;
    // May be larger!
};

ASSERT_SIZE(struct battle_struct, 4840);

#endif