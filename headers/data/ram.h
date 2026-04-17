#ifndef HEADERS_DATA_RAM_H_
#define HEADERS_DATA_RAM_H_

extern struct mission_quest_data* MISSION_QUEST_DATA_PTR;
extern struct megastruct* MEGASTRUCT_PTR_RAM;
extern undefined4 RANGER_NET_MISSION_COMPLETION_BITS;
extern struct mission_quest_data MISSION_QUEST_DATA;
extern struct ranger_data RANGER_DATA;
extern struct pokemon_data PARTY_POKEMON_TABLES[3][10];
extern struct following_npc FOLLOWING_NPC_TABLE[2];
int ARENA_GRAPHIC_ID;
extern struct settings_and_variables SETTINGS_AND_VARIABLES;
extern struct lcrng_state LCRNG_STATE;
extern void** SYSCALL_PAGE_PTRS[64];
#endif
