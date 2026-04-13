// Shared types used throughout the game

#ifndef HEADERS_TYPES_COMMON_H_
#define HEADERS_TYPES_COMMON_H_

#include "util.h"
#include "enums.h"
#include "battle.h"
#include "flying_menu.h"
#include "options_menu.h"
#include "unfinished.h"
#include "textbox.h"

// Parameters used by the NitroSDK to read the ROM.
struct start_module_params {
    void* autoload_list;
    void* autoload_list_end;
    void* autoload_start;
    void* static_bss_start;
    void* static_bss_end;
    uint32_t compressed_static_end;
    uint32_t version_id;
    uint32_t nitrocode_be;
    uint32_t nitrocode_le;
};

// Individual entry in the quest table
struct quest_table_entry {
    int8_t is_available : 1; // bit 0
    int8_t is_cleared : 1;   // bit 1
    int8_t unk_bit_2 : 1;
    int8_t unk_bit_3 : 1;
    int8_t name_visible : 1; // bit 4
    int8_t unk_bit_5 : 1;
    int8_t unk_bit_6 : 1;
    int8_t unk_bit_7 : 1;
};

ASSERT_SIZE(struct quest_table_entry, 1);

// Tracks relevant mission and quest data
struct quest_body {
    bool has_active_mission;
    bool has_active_quest;
    int8_t active_mission_id; // Eventually make this an enum
    int8_t active_quest_id;   // Eventually make this an enum
    int8_t num_missions_cleared;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    int chapter_num;
    undefined field9_0xc;
    undefined field10_0xd;
    undefined field11_0xe;
    undefined field12_0xf;
    undefined field13_0x10;
    undefined field14_0x11;
    undefined field15_0x12;
    undefined field16_0x13;
    struct quest_table_entry quest_table[62]; // bitfield by quest id
    undefined field_0x52;
    undefined field_0x53;
};
ASSERT_SIZE(struct quest_body, 84);

struct quest_footer {
    undefined* unk_struct_size_0x158_ptr;
    struct script_manager* script_manager_ptr;
};
ASSERT_SIZE(struct quest_footer, 8);

// Tracks relevant mission and quest data
struct quest {
    struct quest_body body;
    struct quest_footer footer;
};

ASSERT_SIZE(struct quest, 92);

struct lcrng_state {
    int32_t current_state;
    int32_t mult;
    int32_t add;
};
ASSERT_SIZE(struct lcrng_state, 12);

// Contains critical player data, such as their gender, HP, position, and exp.
struct ranger_core_data {
    bool ranger_is_female;
    int8_t current_hp;
    int8_t max_hp;
    int8_t styler_rank : 4;
    enum styler_type styler_type : 4;
    int32_t partner_assist_gauge; // Maximum varies by partner. May contain other data as nibbles.
    undefined field8_0x8;
    int8_t partner_pokemon_moods[17]; // 0x0 normal, 0x1 happy, 0x2 very happy?
    struct room_id_16 room;
    int16_t player_coordinates[2];
    undefined field28_0x20;
    undefined field29_0x21;
    undefined field30_0x22;
    undefined field31_0x23;
    int16_t player_face_direction;
    // This seems to mess with pathing and collision when edited. Copied to caught pokemon?
    int16_t player_collision_data;
    int32_t current_styler_exp;
    int32_t current_player_exp;
};

ASSERT_SIZE(struct ranger_core_data, 48);

// Data type for befriended pokemon
struct pokemon_data {
    struct form_id_16 form;        // NOT natdex number!
    struct room_id_16 room_caught; // Used to determine if a pokemon was already caught here.
    int16_t room_caught_index;     // Index of this pokemon in room_caught's available pokemon.
    undefined field5_0x6;          // Seems to be padding
    undefined field6_0x7;
    // Bitfield of data that affects whether the pokemon exists, can use poke-assists, can be
    // released, etc. Requires more research to fully understand...
    undefined4 slot_status_fields;
    // These last 12 bytes change rapidly, and are likely related to pokemon motion.
    int x_coordinate;
    int y_coordinate;
    int16_t face_angle;
    int16_t collision_data; // This is copied from the field of the same name in ranger_core_data.
                            // It seems to mess with pathing and collision when edited.
};

ASSERT_SIZE(struct pokemon_data, 24);

// Statistics on seend and befriended pokemon.
struct ranger_pokedex {
    enum species_status unk_0001_status : 2; // Bulbasaur
    enum species_status unk_0002_status : 2; // Ivysaur
    enum species_status unk_0003_status : 2; // Venusaur
    enum species_status charmander_status : 2;
    enum species_status charmeleon_status : 2;
    enum species_status charizard_status : 2;
    enum species_status squirtle_status : 2;
    enum species_status wartortle_status : 2;
    enum species_status blastoise_status : 2;
    enum species_status unk_0010_status : 2; // Caterpie
    enum species_status unk_0011_status : 2; // Metapod
    enum species_status unk_0012_status : 2; // Butterfree
    enum species_status weedle_status : 2;
    enum species_status unk_0014_status : 2; // Kakuna
    enum species_status beedrill_status : 2;
    enum species_status unk_0016_status : 2; // Pidgey
    enum species_status unk_0017_status : 2; // Pidgeotto
    enum species_status unk_0018_status : 2; // Pidgeot
    enum species_status rattata_status : 2;
    enum species_status raticate_status : 2;
    enum species_status spearow_status : 2;
    enum species_status fearow_status : 2;
    enum species_status unk_0023_status : 2; // Ekans
    enum species_status unk_0024_status : 2; // Arbok
    enum species_status pikachu_status : 2;
    enum species_status raichu_status : 2;
    enum species_status sandshrew_status : 2;
    enum species_status sandslash_status : 2;
    enum species_status unk_0029_status : 2; // Nidoran_f
    enum species_status unk_0030_status : 2; // Nidorina
    enum species_status unk_0031_status : 2; // Nidoqueen
    enum species_status unk_0032_status : 2; // Nidoran_m
    enum species_status unk_0033_status : 2; // Nidorino
    enum species_status unk_0034_status : 2; // Nidoking
    enum species_status unk_0035_status : 2; // Clefairy
    enum species_status unk_0036_status : 2; // Clefable
    enum species_status vulpix_status : 2;
    enum species_status ninetales_status : 2;
    enum species_status jigglypuff_status : 2;
    enum species_status wigglytuff_status : 2;
    enum species_status zubat_status : 2;
    enum species_status golbat_status : 2;
    enum species_status oddish_status : 2;
    enum species_status gloom_status : 2;
    enum species_status vileplume_status : 2;
    enum species_status unk_0046_status : 2; // Paras
    enum species_status unk_0047_status : 2; // Parasect
    enum species_status unk_0048_status : 2; // Venonat
    enum species_status unk_0049_status : 2; // Venomoth
    enum species_status unk_0050_status : 2; // Diglett
    enum species_status unk_0051_status : 2; // Dugtrio
    enum species_status unk_0052_status : 2; // Meowth
    enum species_status unk_0053_status : 2; // Persian
    enum species_status unk_0054_status : 2; // Psyduck
    enum species_status unk_0055_status : 2; // Golduck
    enum species_status mankey_status : 2;
    enum species_status primeape_status : 2;
    enum species_status growlithe_status : 2;
    enum species_status arcanine_status : 2;
    enum species_status unk_0060_status : 2; // Poliwag
    enum species_status unk_0061_status : 2; // Poliwhirl
    enum species_status unk_0062_status : 2; // Poliwrath
    enum species_status abra_status : 2;
    enum species_status unk_0064_status : 2; // Kadabra
    enum species_status alakazam_status : 2;
    enum species_status machop_status : 2;
    enum species_status machoke_status : 2;
    enum species_status machamp_status : 2;
    enum species_status unk_0069_status : 2; // Bellsprout
    enum species_status unk_0070_status : 2; // Weepinbell
    enum species_status victreebel_status : 2;
    enum species_status unk_0072_status : 2; // Tentacool
    enum species_status tentacruel_status : 2;
    enum species_status geodude_status : 2;
    enum species_status graveler_status : 2;
    enum species_status golem_status : 2;
    enum species_status ponyta_status : 2;
    enum species_status rapidash_status : 2;
    enum species_status unk_0079_status : 2; // Slowpoke
    enum species_status unk_0080_status : 2; // Slowbro
    enum species_status magnemite_status : 2;
    enum species_status magneton_status : 2;
    enum species_status unk_0083_status : 2; // Farfetchd
    enum species_status doduo_status : 2;
    enum species_status dodrio_status : 2;
    enum species_status unk_0086_status : 2; // Seel
    enum species_status unk_0087_status : 2; // Dewgong
    enum species_status unk_0088_status : 2; // Grimer
    enum species_status muk_status : 2;
    enum species_status unk_0090_status : 2; // Shellder
    enum species_status unk_0091_status : 2; // Cloyster
    enum species_status gastly_status : 2;
    enum species_status haunter_status : 2;
    enum species_status gengar_status : 2;
    enum species_status unk_0095_status : 2; // Onix
    enum species_status drowzee_status : 2;
    enum species_status hypno_status : 2;
    enum species_status unk_0098_status : 2; // Krabby
    enum species_status unk_0099_status : 2; // Kingler
    enum species_status voltorb_status : 2;
    enum species_status electrode_status : 2;
    enum species_status unk_0102_status : 2; // Exeggcute
    enum species_status unk_0103_status : 2; // Exeggutor
    enum species_status unk_0104_status : 2; // Cubone
    enum species_status unk_0105_status : 2; // Marowak
    enum species_status unk_0106_status : 2; // Hitmonlee
    enum species_status unk_0107_status : 2; // Hitmonchan
    enum species_status unk_0108_status : 2; // Lickitung
    enum species_status koffing_status : 2;
    enum species_status weezing_status : 2;
    enum species_status rhyhorn_status : 2;
    enum species_status rhydon_status : 2;
    enum species_status unk_0113_status : 2; // Chansey
    enum species_status unk_0114_status : 2; // Tangela
    enum species_status kangaskhan_status : 2;
    enum species_status horsea_status : 2;
    enum species_status seadra_status : 2;
    enum species_status unk_0118_status : 2; // Goldeen
    enum species_status unk_0119_status : 2; // Seaking
    enum species_status staryu_status : 2;
    enum species_status starmie_status : 2;
    enum species_status mr_mime_status : 2;
    enum species_status scyther_status : 2;
    enum species_status jynx_status : 2;
    enum species_status electabuzz_status : 2;
    enum species_status magmar_status : 2;
    enum species_status pinsir_status : 2;
    enum species_status tauros_status : 2;
    enum species_status unk_0129_status : 2; // Magikarp
    enum species_status unk_0130_status : 2; // Gyarados
    enum species_status unk_0131_status : 2; // Lapras
    enum species_status unk_0132_status : 2; // Ditto
    enum species_status eevee_status : 2;
    enum species_status vaporeon_status : 2;
    enum species_status jolteon_status : 2;
    enum species_status flareon_status : 2;
    enum species_status unk_0137_status : 2; // Porygon
    enum species_status omanyte_status : 2;
    enum species_status omastar_status : 2;
    enum species_status unk_0140_status : 2; // Kabuto
    enum species_status unk_0141_status : 2; // Kabutops
    enum species_status aerodactyl_status : 2;
    enum species_status unk_0143_status : 2; // Snorlax
    enum species_status unk_0144_status : 2; // Articuno
    enum species_status unk_0145_status : 2; // Zapdos
    enum species_status unk_0146_status : 2; // Moltres
    enum species_status dratini_status : 2;
    enum species_status dragonair_status : 2;
    enum species_status unk_0149_status : 2; // Dragonite
    enum species_status unk_0150_status : 2; // Mewtwo
    enum species_status unk_0151_status : 2; // Mew
    enum species_status unk_0152_status : 2; // Chikorita
    enum species_status unk_0153_status : 2; // Bayleef
    enum species_status unk_0154_status : 2; // Meganium
    enum species_status unk_0155_status : 2; // Cyndaquil
    enum species_status unk_0156_status : 2; // Quilava
    enum species_status unk_0157_status : 2; // Typhlosion
    enum species_status unk_0158_status : 2; // Totodile
    enum species_status unk_0159_status : 2; // Croconaw
    enum species_status unk_0160_status : 2; // Feraligatr
    enum species_status unk_0161_status : 2; // Sentret
    enum species_status unk_0162_status : 2; // Furret
    enum species_status unk_0163_status : 2; // Hoothoot
    enum species_status unk_0164_status : 2; // Noctowl
    enum species_status unk_0165_status : 2; // Ledyba
    enum species_status unk_0166_status : 2; // Ledian
    enum species_status spinarak_status : 2;
    enum species_status ariados_status : 2;
    enum species_status crobat_status : 2;
    enum species_status chinchou_status : 2;
    enum species_status lanturn_status : 2;
    enum species_status pichu_status : 2;
    enum species_status unk_0173_status : 2; // Cleffa
    enum species_status unk_0174_status : 2; // Igglybuff
    enum species_status unk_0175_status : 2; // Togepi
    enum species_status unk_0176_status : 2; // Togetic
    enum species_status unk_0177_status : 2; // Natu
    enum species_status unk_0178_status : 2; // Xatu
    enum species_status mareep_status : 2;
    enum species_status flaaffy_status : 2;
    enum species_status ampharos_status : 2;
    enum species_status bellossom_status : 2;
    enum species_status unk_0183_status : 2; // Marill
    enum species_status unk_0184_status : 2; // Azumarill
    enum species_status sudowoodo_status : 2;
    enum species_status unk_0186_status : 2; // Politoed
    enum species_status unk_0187_status : 2; // Hoppip
    enum species_status unk_0188_status : 2; // Skiploom
    enum species_status unk_0189_status : 2; // Jumpluff
    enum species_status aipom_status : 2;
    enum species_status unk_0191_status : 2; // Sunkern
    enum species_status unk_0192_status : 2; // Sunflora
    enum species_status yanma_status : 2;
    enum species_status unk_0194_status : 2; // Wooper
    enum species_status unk_0195_status : 2; // Quagsire
    enum species_status espeon_status : 2;
    enum species_status umbreon_status : 2;
    enum species_status murkrow_status : 2;
    enum species_status unk_0199_status : 2; // Slowking
    enum species_status misdreavus_status : 2;
    enum species_status unk_0201_status : 2; // Unown
    enum species_status unk_0202_status : 2; // Wobbuffet
    enum species_status girafarig_status : 2;
    enum species_status pineco_status : 2;
    enum species_status forretress_status : 2;
    enum species_status unk_0206_status : 2; // Dunsparce
    enum species_status gligar_status : 2;
    enum species_status unk_0208_status : 2; // Steelix
    enum species_status unk_0209_status : 2; // Snubbull
    enum species_status unk_0210_status : 2; // Granbull
    enum species_status qwilfish_status : 2;
    enum species_status scizor_status : 2;
    enum species_status unk_0213_status : 2; // Shuckle
    enum species_status unk_0214_status : 2; // Heracross
    enum species_status sneasel_status : 2;
    enum species_status unk_0216_status : 2; // Teddiursa
    enum species_status unk_0217_status : 2; // Ursaring
    enum species_status slugma_status : 2;
    enum species_status magcargo_status : 2;
    enum species_status swinub_status : 2;
    enum species_status piloswine_status : 2;
    enum species_status corsola_status : 2;
    enum species_status unk_0223_status : 2; // Remoraid
    enum species_status unk_0224_status : 2; // Octillery
    enum species_status delibird_status : 2;
    enum species_status mantine_status : 2;
    enum species_status skarmory_status : 2;
    enum species_status houndour_status : 2;
    enum species_status houndoom_status : 2;
    enum species_status kingdra_status : 2;
    enum species_status unk_0231_status : 2; // Phanpy
    enum species_status unk_0232_status : 2; // Donphan
    enum species_status unk_0233_status : 2; // Porygon2
    enum species_status unk_0234_status : 2; // Stantler
    enum species_status unk_0235_status : 2; // Smeargle
    enum species_status tyrogue_status : 2;
    enum species_status unk_0237_status : 2; // Hitmontop
    enum species_status unk_0238_status : 2; // Smoochum
    enum species_status elekid_status : 2;
    enum species_status magby_status : 2;
    enum species_status miltank_status : 2;
    enum species_status unk_0242_status : 2; // Blissey
    enum species_status unk_0243_status : 2; // Raikou
    enum species_status unk_0244_status : 2; // Entei
    enum species_status unk_0245_status : 2; // Suicune
    enum species_status larvitar_status : 2;
    enum species_status pupitar_status : 2;
    enum species_status tyranitar_status : 2;
    enum species_status unk_0249_status : 2; // Lugia
    enum species_status unk_0250_status : 2; // Ho-Oh
    enum species_status celebi_status : 2;
    enum species_status unk_0252_status : 2; // Treecko
    enum species_status unk_0253_status : 2; // Grovyle
    enum species_status sceptile_status : 2;
    enum species_status unk_0255_status : 2; // Torchic
    enum species_status unk_0256_status : 2; // Combusken
    enum species_status blaziken_status : 2;
    enum species_status unk_0258_status : 2; // Mudkip
    enum species_status unk_0259_status : 2; // Marshtomp
    enum species_status unk_0260_status : 2; // Swampert
    enum species_status unk_0261_status : 2; // Poochyena
    enum species_status unk_0262_status : 2; // Mightyena
    enum species_status unk_0263_status : 2; // Zigzagoon
    enum species_status unk_0264_status : 2; // Linoone
    enum species_status unk_0265_status : 2; // Wurmple
    enum species_status unk_0266_status : 2; // Silcoon
    enum species_status unk_0267_status : 2; // Beautifly
    enum species_status unk_0268_status : 2; // Cascoon
    enum species_status unk_0269_status : 2; // Dustox
    enum species_status unk_0270_status : 2; // Lotad
    enum species_status unk_0271_status : 2; // Lombre
    enum species_status unk_0272_status : 2; // Ludicolo
    enum species_status seedot_status : 2;
    enum species_status nuzleaf_status : 2;
    enum species_status shiftry_status : 2;
    enum species_status taillow_status : 2;
    enum species_status swellow_status : 2;
    enum species_status wingull_status : 2;
    enum species_status pelipper_status : 2;
    enum species_status ralts_status : 2;
    enum species_status kirlia_status : 2;
    enum species_status gardevoir_status : 2;
    enum species_status unk_0283_status : 2; // Surskit
    enum species_status unk_0284_status : 2; // Masquerain
    enum species_status unk_0285_status : 2; // Shroomish
    enum species_status unk_0286_status : 2; // Breloom
    enum species_status slakoth_status : 2;
    enum species_status unk_0288_status : 2; // Vigoroth
    enum species_status unk_0289_status : 2; // Slaking
    enum species_status unk_0290_status : 2; // Nincada
    enum species_status ninjask_status : 2;
    enum species_status unk_0292_status : 2; // Shedinja
    enum species_status unk_0293_status : 2; // Whismur
    enum species_status unk_0294_status : 2; // Loudred
    enum species_status unk_0295_status : 2; // Exploud
    enum species_status makuhita_status : 2;
    enum species_status hariyama_status : 2;
    enum species_status unk_0298_status : 2; // Azurill
    enum species_status nosepass_status : 2;
    enum species_status unk_0300_status : 2; // Skitty
    enum species_status unk_0301_status : 2; // Delcatty
    enum species_status sableye_status : 2;
    enum species_status mawile_status : 2;
    enum species_status aron_status : 2;
    enum species_status lairon_status : 2;
    enum species_status aggron_status : 2;
    enum species_status unk_0307_status : 2; // Meditite
    enum species_status unk_0308_status : 2; // Medicham
    enum species_status unk_0309_status : 2; // Electrike
    enum species_status unk_0310_status : 2; // Manectric
    enum species_status unk_0311_status : 2; // Plusle
    enum species_status unk_0312_status : 2; // Minun
    enum species_status unk_0313_status : 2; // Volbeat
    enum species_status unk_0314_status : 2; // Illumise
    enum species_status roselia_status : 2;
    enum species_status unk_0316_status : 2; // Gulpin
    enum species_status unk_0317_status : 2; // Swalot
    enum species_status unk_0318_status : 2; // Carvanha
    enum species_status sharpedo_status : 2;
    enum species_status wailmer_status : 2;
    enum species_status wailord_status : 2;
    enum species_status numel_status : 2;
    enum species_status camerupt_status : 2;
    enum species_status torkoal_status : 2;
    enum species_status unk_0325_status : 2; // Spoink
    enum species_status unk_0326_status : 2; // Grumpig
    enum species_status unk_0327_status : 2; // Spinda
    enum species_status unk_0328_status : 2; // Trapinch
    enum species_status unk_0329_status : 2; // Vibrava
    enum species_status flygon_status : 2;
    enum species_status cacnea_status : 2;
    enum species_status cacturne_status : 2;
    enum species_status unk_0333_status : 2; // Swablu
    enum species_status altaria_status : 2;
    enum species_status unk_0335_status : 2; // Zangoose
    enum species_status unk_0336_status : 2; // Seviper
    enum species_status unk_0337_status : 2; // Lunatone
    enum species_status unk_0338_status : 2; // Solrock
    enum species_status unk_0339_status : 2; // Barboach
    enum species_status unk_0340_status : 2; // Whiscash
    enum species_status unk_0341_status : 2; // Corphish
    enum species_status unk_0342_status : 2; // Crawdaunt
    enum species_status unk_0343_status : 2; // Baltoy
    enum species_status claydol_status : 2;
    enum species_status unk_0345_status : 2; // Lileep
    enum species_status unk_0346_status : 2; // Cradily
    enum species_status unk_0347_status : 2; // Anorith
    enum species_status unk_0348_status : 2; // Armaldo
    enum species_status unk_0349_status : 2; // Feebas
    enum species_status unk_0350_status : 2; // Milotic
    enum species_status unk_0351_status : 2; // Castform
    enum species_status unk_0352_status : 2; // Kecleon
    enum species_status shuppet_status : 2;
    enum species_status banette_status : 2;
    enum species_status duskull_status : 2;
    enum species_status dusclops_status : 2;
    enum species_status unk_0357_status : 2; // Tropius
    enum species_status unk_0358_status : 2; // Chimecho
    enum species_status absol_status : 2;
    enum species_status unk_0360_status : 2; // Wynaut
    enum species_status snorunt_status : 2;
    enum species_status glalie_status : 2;
    enum species_status spheal_status : 2;
    enum species_status sealeo_status : 2;
    enum species_status walrein_status : 2;
    enum species_status unk_0366_status : 2; // Clamperl
    enum species_status huntail_status : 2;
    enum species_status gorebyss_status : 2;
    enum species_status unk_0369_status : 2; // Relicanth
    enum species_status unk_0370_status : 2; // Luvdisc
    enum species_status bagon_status : 2;
    enum species_status shelgon_status : 2;
    enum species_status salamence_status : 2;
    enum species_status unk_0374_status : 2; // Beldum
    enum species_status unk_0375_status : 2; // Metang
    enum species_status unk_0376_status : 2; // Metagross
    enum species_status regirock_status : 2;
    enum species_status regice_status : 2;
    enum species_status registeel_status : 2;
    enum species_status unk_0380_status : 2; // Latias
    enum species_status unk_0381_status : 2; // Latios
    enum species_status unk_0382_status : 2; // Kyogre
    enum species_status unk_0383_status : 2; // Groudon
    enum species_status unk_0384_status : 2; // Rayquaza
    enum species_status unk_0385_status : 2; // Jirachi
    enum species_status unk_0386_status : 2; // Deoxys
    enum species_status turtwig_status : 2;
    enum species_status grotle_status : 2;
    enum species_status torterra_status : 2;
    enum species_status chimchar_status : 2;
    enum species_status monferno_status : 2;
    enum species_status infernape_status : 2;
    enum species_status piplup_status : 2;
    enum species_status prinplup_status : 2;
    enum species_status empoleon_status : 2;
    enum species_status starly_status : 2;
    enum species_status staravia_status : 2;
    enum species_status staraptor_status : 2;
    enum species_status bidoof_status : 2;
    enum species_status bibarel_status : 2;
    enum species_status kricketot_status : 2;
    enum species_status kricketune_status : 2;
    enum species_status shinx_status : 2;
    enum species_status luxio_status : 2;
    enum species_status luxray_status : 2;
    enum species_status budew_status : 2;
    enum species_status roserade_status : 2;
    enum species_status cranidos_status : 2;
    enum species_status rampardos_status : 2;
    enum species_status shieldon_status : 2;
    enum species_status bastiodon_status : 2;
    enum species_status unk_0412_status : 2; // Burmy
    enum species_status unk_0413_status : 2; // Wormadam
    enum species_status mothim_status : 2;
    enum species_status combee_status : 2;
    enum species_status vespiquen_status : 2;
    enum species_status pachirisu_status : 2;
    enum species_status buizel_status : 2;
    enum species_status floatzel_status : 2;
    enum species_status cherubi_status : 2;
    enum species_status cherrim_status : 2;
    enum species_status shellos_status : 2;
    enum species_status gastrodon_status : 2;
    enum species_status ambipom_status : 2;
    enum species_status drifloon_status : 2;
    enum species_status drifblim_status : 2;
    enum species_status buneary_status : 2;
    enum species_status lopunny_status : 2;
    enum species_status mismagius_status : 2;
    enum species_status honchkrow_status : 2;
    enum species_status glameow_status : 2;
    enum species_status purugly_status : 2;
    enum species_status chingling_status : 2;
    enum species_status stunky_status : 2;
    enum species_status skuntank_status : 2;
    enum species_status bronzor_status : 2;
    enum species_status bronzong_status : 2;
    enum species_status bonsly_status : 2;
    enum species_status mime_jr_status : 2;
    enum species_status happiny_status : 2;
    enum species_status chatot_status : 2;
    enum species_status spiritomb_status : 2;
    enum species_status gible_status : 2;
    enum species_status gabite_status : 2;
    enum species_status garchomp_status : 2;
    enum species_status munchlax_status : 2;
    enum species_status riolu_status : 2;
    enum species_status lucario_status : 2;
    enum species_status hippopotas_status : 2;
    enum species_status hippowdon_status : 2;
    enum species_status skorupi_status : 2;
    enum species_status drapion_status : 2;
    enum species_status croagunk_status : 2;
    enum species_status toxicroak_status : 2;
    enum species_status carnivine_status : 2;
    enum species_status finneon_status : 2;
    enum species_status lumineon_status : 2;
    enum species_status mantyke_status : 2;
    enum species_status snover_status : 2;
    enum species_status abomasnow_status : 2;
    enum species_status weavile_status : 2;
    enum species_status magnezone_status : 2;
    enum species_status lickilicky_status : 2;
    enum species_status rhyperior_status : 2;
    enum species_status tangrowth_status : 2;
    enum species_status electivire_status : 2;
    enum species_status magmortar_status : 2;
    enum species_status togekiss_status : 2;
    enum species_status yanmega_status : 2;
    enum species_status leafeon_status : 2;
    enum species_status glaceon_status : 2;
    enum species_status gliscor_status : 2;
    enum species_status mamoswine_status : 2;
    enum species_status porygon_z_status : 2;
    enum species_status gallade_status : 2;
    enum species_status probopass_status : 2;
    enum species_status dusknoir_status : 2;
    enum species_status froslass_status : 2;
    enum species_status unk_0479_status : 2; // Rotom
    enum species_status unk_0480_status : 2; // Uxie
    enum species_status unk_0481_status : 2; // Mesprit
    enum species_status unk_0482_status : 2; // Azelf
    enum species_status dialga_status : 2;
    enum species_status palkia_status : 2;
    enum species_status heatran_status : 2;
    enum species_status regigigas_status : 2;
    enum species_status unk_0487_status : 2; // Giratina
    enum species_status cresselia_status : 2;
    enum species_status unk_0489_status : 2; // Phione
    enum species_status unk_0490_status : 2; // Manaphy
    enum species_status darkrai_status : 2;
    enum species_status shaymin_status : 2;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    int8_t lifetime_caught_table[492]; // one byte per species
    undefined field_0x26c;
    undefined field_0x26d;
    undefined field_0x26e;
    undefined field_0x26f;
    undefined field_0x270;
    undefined field_0x271;
    undefined field_0x272;
    undefined field_0x273;
    enum capture_rank unk_0001_rank : 2; // Bulbasaur
    enum capture_rank unk_0002_rank : 2; // Ivysaur
    enum capture_rank unk_0003_rank : 2; // Venusaur
    enum capture_rank charmander_rank : 2;
    enum capture_rank charmeleon_rank : 2;
    enum capture_rank charizard_rank : 2;
    enum capture_rank squirtle_rank : 2;
    enum capture_rank wartortle_rank : 2;
    enum capture_rank blastoise_rank : 2;
    enum capture_rank unk_0010_rank : 2; // Caterpie
    enum capture_rank unk_0011_rank : 2; // Metapod
    enum capture_rank unk_0012_rank : 2; // Butterfree
    enum capture_rank weedle_rank : 2;
    enum capture_rank unk_0014_rank : 2; // Kakuna
    enum capture_rank beedrill_rank : 2;
    enum capture_rank unk_0016_rank : 2; // Pidgey
    enum capture_rank unk_0017_rank : 2; // Pidgeotto
    enum capture_rank unk_0018_rank : 2; // Pidgeot
    enum capture_rank rattata_rank : 2;
    enum capture_rank raticate_rank : 2;
    enum capture_rank spearow_rank : 2;
    enum capture_rank fearow_rank : 2;
    enum capture_rank unk_0023_rank : 2; // Ekans
    enum capture_rank unk_0024_rank : 2; // Arbok
    enum capture_rank pikachu_rank : 2;
    enum capture_rank raichu_rank : 2;
    enum capture_rank sandshrew_rank : 2;
    enum capture_rank sandslash_rank : 2;
    enum capture_rank unk_0029_rank : 2; // Nidoran_f
    enum capture_rank unk_0030_rank : 2; // Nidorina
    enum capture_rank unk_0031_rank : 2; // Nidoqueen
    enum capture_rank unk_0032_rank : 2; // Nidoran_m
    enum capture_rank unk_0033_rank : 2; // Nidorino
    enum capture_rank unk_0034_rank : 2; // Nidoking
    enum capture_rank unk_0035_rank : 2; // Clefairy
    enum capture_rank unk_0036_rank : 2; // Clefable
    enum capture_rank vulpix_rank : 2;
    enum capture_rank ninetales_rank : 2;
    enum capture_rank jigglypuff_rank : 2;
    enum capture_rank wigglytuff_rank : 2;
    enum capture_rank zubat_rank : 2;
    enum capture_rank golbat_rank : 2;
    enum capture_rank oddish_rank : 2;
    enum capture_rank gloom_rank : 2;
    enum capture_rank vileplume_rank : 2;
    enum capture_rank unk_0046_rank : 2; // Paras
    enum capture_rank unk_0047_rank : 2; // Parasect
    enum capture_rank unk_0048_rank : 2; // Venonat
    enum capture_rank unk_0049_rank : 2; // Venomoth
    enum capture_rank unk_0050_rank : 2; // Diglett
    enum capture_rank unk_0051_rank : 2; // Dugtrio
    enum capture_rank unk_0052_rank : 2; // Meowth
    enum capture_rank unk_0053_rank : 2; // Persian
    enum capture_rank unk_0054_rank : 2; // Psyduck
    enum capture_rank unk_0055_rank : 2; // Golduck
    enum capture_rank mankey_rank : 2;
    enum capture_rank primeape_rank : 2;
    enum capture_rank growlithe_rank : 2;
    enum capture_rank arcanine_rank : 2;
    enum capture_rank unk_0060_rank : 2; // Poliwag
    enum capture_rank unk_0061_rank : 2; // Poliwhirl
    enum capture_rank unk_0062_rank : 2; // Poliwrath
    enum capture_rank abra_rank : 2;
    enum capture_rank unk_0064_rank : 2; // Kadabra
    enum capture_rank alakazam_rank : 2;
    enum capture_rank machop_rank : 2;
    enum capture_rank machoke_rank : 2;
    enum capture_rank machamp_rank : 2;
    enum capture_rank unk_0069_rank : 2; // Bellsprout
    enum capture_rank unk_0070_rank : 2; // Weepinbell
    enum capture_rank victreebel_rank : 2;
    enum capture_rank unk_0072_rank : 2; // Tentacool
    enum capture_rank tentacruel_rank : 2;
    enum capture_rank geodude_rank : 2;
    enum capture_rank graveler_rank : 2;
    enum capture_rank golem_rank : 2;
    enum capture_rank ponyta_rank : 2;
    enum capture_rank rapidash_rank : 2;
    enum capture_rank unk_0079_rank : 2; // Slowpoke
    enum capture_rank unk_0080_rank : 2; // Slowbro
    enum capture_rank magnemite_rank : 2;
    enum capture_rank magneton_rank : 2;
    enum capture_rank unk_0083_rank : 2; // Farfetchd
    enum capture_rank doduo_rank : 2;
    enum capture_rank dodrio_rank : 2;
    enum capture_rank unk_0086_rank : 2; // Seel
    enum capture_rank unk_0087_rank : 2; // Dewgong
    enum capture_rank unk_0088_rank : 2; // Grimer
    enum capture_rank muk_rank : 2;
    enum capture_rank unk_0090_rank : 2; // Shellder
    enum capture_rank unk_0091_rank : 2; // Cloyster
    enum capture_rank gastly_rank : 2;
    enum capture_rank haunter_rank : 2;
    enum capture_rank gengar_rank : 2;
    enum capture_rank unk_0095_rank : 2; // Onix
    enum capture_rank drowzee_rank : 2;
    enum capture_rank hypno_rank : 2;
    enum capture_rank unk_0098_rank : 2; // Krabby
    enum capture_rank unk_0099_rank : 2; // Kingler
    enum capture_rank voltorb_rank : 2;
    enum capture_rank electrode_rank : 2;
    enum capture_rank unk_0102_rank : 2; // Exeggcute
    enum capture_rank unk_0103_rank : 2; // Exeggutor
    enum capture_rank unk_0104_rank : 2; // Cubone
    enum capture_rank unk_0105_rank : 2; // Marowak
    enum capture_rank unk_0106_rank : 2; // Hitmonlee
    enum capture_rank unk_0107_rank : 2; // Hitmonchan
    enum capture_rank unk_0108_rank : 2; // Lickitung
    enum capture_rank koffing_rank : 2;
    enum capture_rank weezing_rank : 2;
    enum capture_rank rhyhorn_rank : 2;
    enum capture_rank rhydon_rank : 2;
    enum capture_rank unk_0113_rank : 2; // Chansey
    enum capture_rank unk_0114_rank : 2; // Tangela
    enum capture_rank kangaskhan_rank : 2;
    enum capture_rank horsea_rank : 2;
    enum capture_rank seadra_rank : 2;
    enum capture_rank unk_0118_rank : 2; // Goldeen
    enum capture_rank unk_0119_rank : 2; // Seaking
    enum capture_rank staryu_rank : 2;
    enum capture_rank starmie_rank : 2;
    enum capture_rank mr_mime_rank : 2;
    enum capture_rank scyther_rank : 2;
    enum capture_rank jynx_rank : 2;
    enum capture_rank electabuzz_rank : 2;
    enum capture_rank magmar_rank : 2;
    enum capture_rank pinsir_rank : 2;
    enum capture_rank tauros_rank : 2;
    enum capture_rank unk_0129_rank : 2; // Magikarp
    enum capture_rank unk_0130_rank : 2; // Gyarados
    enum capture_rank unk_0131_rank : 2; // Lapras
    enum capture_rank unk_0132_rank : 2; // Ditto
    enum capture_rank eevee_rank : 2;
    enum capture_rank vaporeon_rank : 2;
    enum capture_rank jolteon_rank : 2;
    enum capture_rank flareon_rank : 2;
    enum capture_rank unk_0137_rank : 2; // Porygon
    enum capture_rank omanyte_rank : 2;
    enum capture_rank omastar_rank : 2;
    enum capture_rank unk_0140_rank : 2; // Kabuto
    enum capture_rank unk_0141_rank : 2; // Kabutops
    enum capture_rank aerodactyl_rank : 2;
    enum capture_rank unk_0143_rank : 2; // Snorlax
    enum capture_rank unk_0144_rank : 2; // Articuno
    enum capture_rank unk_0145_rank : 2; // Zapdos
    enum capture_rank unk_0146_rank : 2; // Moltres
    enum capture_rank dratini_rank : 2;
    enum capture_rank dragonair_rank : 2;
    enum capture_rank unk_0149_rank : 2; // Dragonite
    enum capture_rank unk_0150_rank : 2; // Mewtwo
    enum capture_rank unk_0151_rank : 2; // Mew
    enum capture_rank unk_0152_rank : 2; // Chikorita
    enum capture_rank unk_0153_rank : 2; // Bayleef
    enum capture_rank unk_0154_rank : 2; // Meganium
    enum capture_rank unk_0155_rank : 2; // Cyndaquil
    enum capture_rank unk_0156_rank : 2; // Quilava
    enum capture_rank unk_0157_rank : 2; // Typhlosion
    enum capture_rank unk_0158_rank : 2; // Totodile
    enum capture_rank unk_0159_rank : 2; // Croconaw
    enum capture_rank unk_0160_rank : 2; // Feraligatr
    enum capture_rank unk_0161_rank : 2; // Sentret
    enum capture_rank unk_0162_rank : 2; // Furret
    enum capture_rank unk_0163_rank : 2; // Hoothoot
    enum capture_rank unk_0164_rank : 2; // Noctowl
    enum capture_rank unk_0165_rank : 2; // Ledyba
    enum capture_rank unk_0166_rank : 2; // Ledian
    enum capture_rank spinarak_rank : 2;
    enum capture_rank ariados_rank : 2;
    enum capture_rank crobat_rank : 2;
    enum capture_rank chinchou_rank : 2;
    enum capture_rank lanturn_rank : 2;
    enum capture_rank pichu_rank : 2;
    enum capture_rank unk_0173_rank : 2; // Cleffa
    enum capture_rank unk_0174_rank : 2; // Igglybuff
    enum capture_rank unk_0175_rank : 2; // Togepi
    enum capture_rank unk_0176_rank : 2; // Togetic
    enum capture_rank unk_0177_rank : 2; // Natu
    enum capture_rank unk_0178_rank : 2; // Xatu
    enum capture_rank mareep_rank : 2;
    enum capture_rank flaaffy_rank : 2;
    enum capture_rank ampharos_rank : 2;
    enum capture_rank bellossom_rank : 2;
    enum capture_rank unk_0183_rank : 2; // Marill
    enum capture_rank unk_0184_rank : 2; // Azumarill
    enum capture_rank sudowoodo_rank : 2;
    enum capture_rank unk_0186_rank : 2; // Politoed
    enum capture_rank unk_0187_rank : 2; // Hoppip
    enum capture_rank unk_0188_rank : 2; // Skiploom
    enum capture_rank unk_0189_rank : 2; // Jumpluff
    enum capture_rank aipom_rank : 2;
    enum capture_rank unk_0191_rank : 2; // Sunkern
    enum capture_rank unk_0192_rank : 2; // Sunflora
    enum capture_rank yanma_rank : 2;
    enum capture_rank unk_0194_rank : 2; // Wooper
    enum capture_rank unk_0195_rank : 2; // Quagsire
    enum capture_rank espeon_rank : 2;
    enum capture_rank umbreon_rank : 2;
    enum capture_rank murkrow_rank : 2;
    enum capture_rank unk_0199_rank : 2; // Slowking
    enum capture_rank misdreavus_rank : 2;
    enum capture_rank unk_0201_rank : 2; // Unown
    enum capture_rank unk_0202_rank : 2; // Wobbuffet
    enum capture_rank girafarig_rank : 2;
    enum capture_rank pineco_rank : 2;
    enum capture_rank forretress_rank : 2;
    enum capture_rank unk_0206_rank : 2; // Dunsparce
    enum capture_rank gligar_rank : 2;
    enum capture_rank unk_0208_rank : 2; // Steelix
    enum capture_rank unk_0209_rank : 2; // Snubbull
    enum capture_rank unk_0210_rank : 2; // Granbull
    enum capture_rank qwilfish_rank : 2;
    enum capture_rank scizor_rank : 2;
    enum capture_rank unk_0213_rank : 2; // Shuckle
    enum capture_rank unk_0214_rank : 2; // Heracross
    enum capture_rank sneasel_rank : 2;
    enum capture_rank unk_0216_rank : 2; // Teddiursa
    enum capture_rank unk_0217_rank : 2; // Ursaring
    enum capture_rank slugma_rank : 2;
    enum capture_rank magcargo_rank : 2;
    enum capture_rank swinub_rank : 2;
    enum capture_rank piloswine_rank : 2;
    enum capture_rank corsola_rank : 2;
    enum capture_rank unk_0223_rank : 2; // Remoraid
    enum capture_rank unk_0224_rank : 2; // Octillery
    enum capture_rank delibird_rank : 2;
    enum capture_rank mantine_rank : 2;
    enum capture_rank skarmory_rank : 2;
    enum capture_rank houndour_rank : 2;
    enum capture_rank houndoom_rank : 2;
    enum capture_rank kingdra_rank : 2;
    enum capture_rank unk_0231_rank : 2; // Phanpy
    enum capture_rank unk_0232_rank : 2; // Donphan
    enum capture_rank unk_0233_rank : 2; // Porygon2
    enum capture_rank unk_0234_rank : 2; // Stantler
    enum capture_rank unk_0235_rank : 2; // Smeargle
    enum capture_rank tyrogue_rank : 2;
    enum capture_rank unk_0237_rank : 2; // Hitmontop
    enum capture_rank unk_0238_rank : 2; // Smoochum
    enum capture_rank elekid_rank : 2;
    enum capture_rank magby_rank : 2;
    enum capture_rank miltank_rank : 2;
    enum capture_rank unk_0242_rank : 2; // Blissey
    enum capture_rank unk_0243_rank : 2; // Raikou
    enum capture_rank unk_0244_rank : 2; // Entei
    enum capture_rank unk_0245_rank : 2; // Suicune
    enum capture_rank larvitar_rank : 2;
    enum capture_rank pupitar_rank : 2;
    enum capture_rank tyranitar_rank : 2;
    enum capture_rank unk_0249_rank : 2; // Lugia
    enum capture_rank unk_0250_rank : 2; // Ho-Oh
    enum capture_rank celebi_rank : 2;
    enum capture_rank unk_0252_rank : 2; // Treecko
    enum capture_rank unk_0253_rank : 2; // Grovyle
    enum capture_rank sceptile_rank : 2;
    enum capture_rank unk_0255_rank : 2; // Torchic
    enum capture_rank unk_0256_rank : 2; // Combusken
    enum capture_rank blaziken_rank : 2;
    enum capture_rank unk_0258_rank : 2; // Mudkip
    enum capture_rank unk_0259_rank : 2; // Marshtomp
    enum capture_rank unk_0260_rank : 2; // Swampert
    enum capture_rank unk_0261_rank : 2; // Poochyena
    enum capture_rank unk_0262_rank : 2; // Mightyena
    enum capture_rank unk_0263_rank : 2; // Zigzagoon
    enum capture_rank unk_0264_rank : 2; // Linoone
    enum capture_rank unk_0265_rank : 2; // Wurmple
    enum capture_rank unk_0266_rank : 2; // Silcoon
    enum capture_rank unk_0267_rank : 2; // Beautifly
    enum capture_rank unk_0268_rank : 2; // Cascoon
    enum capture_rank unk_0269_rank : 2; // Dustox
    enum capture_rank unk_0270_rank : 2; // Lotad
    enum capture_rank unk_0271_rank : 2; // Lombre
    enum capture_rank unk_0272_rank : 2; // Ludicolo
    enum capture_rank seedot_rank : 2;
    enum capture_rank nuzleaf_rank : 2;
    enum capture_rank shiftry_rank : 2;
    enum capture_rank taillow_rank : 2;
    enum capture_rank swellow_rank : 2;
    enum capture_rank wingull_rank : 2;
    enum capture_rank pelipper_rank : 2;
    enum capture_rank ralts_rank : 2;
    enum capture_rank kirlia_rank : 2;
    enum capture_rank gardevoir_rank : 2;
    enum capture_rank unk_0283_rank : 2; // Surskit
    enum capture_rank unk_0284_rank : 2; // Masquerain
    enum capture_rank unk_0285_rank : 2; // Shroomish
    enum capture_rank unk_0286_rank : 2; // Breloom
    enum capture_rank slakoth_rank : 2;
    enum capture_rank unk_0288_rank : 2; // Vigoroth
    enum capture_rank unk_0289_rank : 2; // Slaking
    enum capture_rank unk_0290_rank : 2; // Nincada
    enum capture_rank ninjask_rank : 2;
    enum capture_rank unk_0292_rank : 2; // Shedinja
    enum capture_rank unk_0293_rank : 2; // Whismur
    enum capture_rank unk_0294_rank : 2; // Loudred
    enum capture_rank unk_0295_rank : 2; // Exploud
    enum capture_rank makuhita_rank : 2;
    enum capture_rank hariyama_rank : 2;
    enum capture_rank unk_0298_rank : 2; // Azurill
    enum capture_rank nosepass_rank : 2;
    enum capture_rank unk_0300_rank : 2; // Skitty
    enum capture_rank unk_0301_rank : 2; // Delcatty
    enum capture_rank sableye_rank : 2;
    enum capture_rank mawile_rank : 2;
    enum capture_rank aron_rank : 2;
    enum capture_rank lairon_rank : 2;
    enum capture_rank aggron_rank : 2;
    enum capture_rank unk_0307_rank : 2; // Meditite
    enum capture_rank unk_0308_rank : 2; // Medicham
    enum capture_rank unk_0309_rank : 2; // Electrike
    enum capture_rank unk_0310_rank : 2; // Manectric
    enum capture_rank unk_0311_rank : 2; // Plusle
    enum capture_rank unk_0312_rank : 2; // Minun
    enum capture_rank unk_0313_rank : 2; // Volbeat
    enum capture_rank unk_0314_rank : 2; // Illumise
    enum capture_rank roselia_rank : 2;
    enum capture_rank unk_0316_rank : 2; // Gulpin
    enum capture_rank unk_0317_rank : 2; // Swalot
    enum capture_rank unk_0318_rank : 2; // Carvanha
    enum capture_rank sharpedo_rank : 2;
    enum capture_rank wailmer_rank : 2;
    enum capture_rank wailord_rank : 2;
    enum capture_rank numel_rank : 2;
    enum capture_rank camerupt_rank : 2;
    enum capture_rank torkoal_rank : 2;
    enum capture_rank unk_0325_rank : 2; // Spoink
    enum capture_rank unk_0326_rank : 2; // Grumpig
    enum capture_rank unk_0327_rank : 2; // Spinda
    enum capture_rank unk_0328_rank : 2; // Trapinch
    enum capture_rank unk_0329_rank : 2; // Vibrava
    enum capture_rank flygon_rank : 2;
    enum capture_rank cacnea_rank : 2;
    enum capture_rank cacturne_rank : 2;
    enum capture_rank unk_0333_rank : 2; // Swablu
    enum capture_rank altaria_rank : 2;
    enum capture_rank unk_0335_rank : 2; // Zangoose
    enum capture_rank unk_0336_rank : 2; // Seviper
    enum capture_rank unk_0337_rank : 2; // Lunatone
    enum capture_rank unk_0338_rank : 2; // Solrock
    enum capture_rank unk_0339_rank : 2; // Barboach
    enum capture_rank unk_0340_rank : 2; // Whiscash
    enum capture_rank unk_0341_rank : 2; // Corphish
    enum capture_rank unk_0342_rank : 2; // Crawdaunt
    enum capture_rank unk_0343_rank : 2; // Baltoy
    enum capture_rank claydol_rank : 2;
    enum capture_rank unk_0345_rank : 2; // Lileep
    enum capture_rank unk_0346_rank : 2; // Cradily
    enum capture_rank unk_0347_rank : 2; // Anorith
    enum capture_rank unk_0348_rank : 2; // Armaldo
    enum capture_rank unk_0349_rank : 2; // Feebas
    enum capture_rank unk_0350_rank : 2; // Milotic
    enum capture_rank unk_0351_rank : 2; // Castform
    enum capture_rank unk_0352_rank : 2; // Kecleon
    enum capture_rank shuppet_rank : 2;
    enum capture_rank banette_rank : 2;
    enum capture_rank duskull_rank : 2;
    enum capture_rank dusclops_rank : 2;
    enum capture_rank unk_0357_rank : 2; // Tropius
    enum capture_rank unk_0358_rank : 2; // Chimecho
    enum capture_rank absol_rank : 2;
    enum capture_rank unk_0360_rank : 2; // Wynaut
    enum capture_rank snorunt_rank : 2;
    enum capture_rank glalie_rank : 2;
    enum capture_rank spheal_rank : 2;
    enum capture_rank sealeo_rank : 2;
    enum capture_rank walrein_rank : 2;
    enum capture_rank unk_0366_rank : 2; // Clamperl
    enum capture_rank huntail_rank : 2;
    enum capture_rank gorebyss_rank : 2;
    enum capture_rank unk_0369_rank : 2; // Relicanth
    enum capture_rank unk_0370_rank : 2; // Luvdisc
    enum capture_rank bagon_rank : 2;
    enum capture_rank shelgon_rank : 2;
    enum capture_rank salamence_rank : 2;
    enum capture_rank unk_0374_rank : 2; // Beldum
    enum capture_rank unk_0375_rank : 2; // Metang
    enum capture_rank unk_0376_rank : 2; // Metagross
    enum capture_rank regirock_rank : 2;
    enum capture_rank regice_rank : 2;
    enum capture_rank registeel_rank : 2;
    enum capture_rank unk_0380_rank : 2; // Latias
    enum capture_rank unk_0381_rank : 2; // Latios
    enum capture_rank unk_0382_rank : 2; // Kyogre
    enum capture_rank unk_0383_rank : 2; // Groudon
    enum capture_rank unk_0384_rank : 2; // Rayquaza
    enum capture_rank unk_0385_rank : 2; // Jirachi
    enum capture_rank unk_0386_rank : 2; // Deoxys
    enum capture_rank turtwig_rank : 2;
    enum capture_rank grotle_rank : 2;
    enum capture_rank torterra_rank : 2;
    enum capture_rank chimchar_rank : 2;
    enum capture_rank monferno_rank : 2;
    enum capture_rank infernape_rank : 2;
    enum capture_rank piplup_rank : 2;
    enum capture_rank prinplup_rank : 2;
    enum capture_rank empoleon_rank : 2;
    enum capture_rank starly_rank : 2;
    enum capture_rank staravia_rank : 2;
    enum capture_rank staraptor_rank : 2;
    enum capture_rank bidoof_rank : 2;
    enum capture_rank bibarel_rank : 2;
    enum capture_rank kricketot_rank : 2;
    enum capture_rank kricketune_rank : 2;
    enum capture_rank shinx_rank : 2;
    enum capture_rank luxio_rank : 2;
    enum capture_rank luxray_rank : 2;
    enum capture_rank budew_rank : 2;
    enum capture_rank roserade_rank : 2;
    enum capture_rank cranidos_rank : 2;
    enum capture_rank rampardos_rank : 2;
    enum capture_rank shieldon_rank : 2;
    enum capture_rank bastiodon_rank : 2;
    enum capture_rank unk_0412_rank : 2; // Burmy
    enum capture_rank unk_0413_rank : 2; // Wormadam
    enum capture_rank mothim_rank : 2;
    enum capture_rank combee_rank : 2;
    enum capture_rank vespiquen_rank : 2;
    enum capture_rank pachirisu_rank : 2;
    enum capture_rank buizel_rank : 2;
    enum capture_rank floatzel_rank : 2;
    enum capture_rank cherubi_rank : 2;
    enum capture_rank cherrim_rank : 2;
    enum capture_rank shellos_rank : 2;
    enum capture_rank gastrodon_rank : 2;
    enum capture_rank ambipom_rank : 2;
    enum capture_rank drifloon_rank : 2;
    enum capture_rank drifblim_rank : 2;
    enum capture_rank buneary_rank : 2;
    enum capture_rank lopunny_rank : 2;
    enum capture_rank mismagius_rank : 2;
    enum capture_rank honchkrow_rank : 2;
    enum capture_rank glameow_rank : 2;
    enum capture_rank purugly_rank : 2;
    enum capture_rank chingling_rank : 2;
    enum capture_rank stunky_rank : 2;
    enum capture_rank skuntank_rank : 2;
    enum capture_rank bronzor_rank : 2;
    enum capture_rank bronzong_rank : 2;
    enum capture_rank bonsly_rank : 2;
    enum capture_rank mime_jr_rank : 2;
    enum capture_rank happiny_rank : 2;
    enum capture_rank chatot_rank : 2;
    enum capture_rank spiritomb_rank : 2;
    enum capture_rank gible_rank : 2;
    enum capture_rank gabite_rank : 2;
    enum capture_rank garchomp_rank : 2;
    enum capture_rank munchlax_rank : 2;
    enum capture_rank riolu_rank : 2;
    enum capture_rank lucario_rank : 2;
    enum capture_rank hippopotas_rank : 2;
    enum capture_rank hippowdon_rank : 2;
    enum capture_rank skorupi_rank : 2;
    enum capture_rank drapion_rank : 2;
    enum capture_rank croagunk_rank : 2;
    enum capture_rank toxicroak_rank : 2;
    enum capture_rank carnivine_rank : 2;
    enum capture_rank finneon_rank : 2;
    enum capture_rank lumineon_rank : 2;
    enum capture_rank mantyke_rank : 2;
    enum capture_rank snover_rank : 2;
    enum capture_rank abomasnow_rank : 2;
    enum capture_rank weavile_rank : 2;
    enum capture_rank magnezone_rank : 2;
    enum capture_rank lickilicky_rank : 2;
    enum capture_rank rhyperior_rank : 2;
    enum capture_rank tangrowth_rank : 2;
    enum capture_rank electivire_rank : 2;
    enum capture_rank magmortar_rank : 2;
    enum capture_rank togekiss_rank : 2;
    enum capture_rank yanmega_rank : 2;
    enum capture_rank leafeon_rank : 2;
    enum capture_rank glaceon_rank : 2;
    enum capture_rank gliscor_rank : 2;
    enum capture_rank mamoswine_rank : 2;
    enum capture_rank porygon_z_rank : 2;
    enum capture_rank gallade_rank : 2;
    enum capture_rank probopass_rank : 2;
    enum capture_rank dusknoir_rank : 2;
    enum capture_rank froslass_rank : 2;
    enum capture_rank unk_0479_rank : 2; // Rotom
    enum capture_rank unk_0480_rank : 2; // Uxie
    enum capture_rank unk_0481_rank : 2; // Mesprit
    enum capture_rank unk_0482_rank : 2; // Azelf
    enum capture_rank dialga_rank : 2;
    enum capture_rank palkia_rank : 2;
    enum capture_rank heatran_rank : 2;
    enum capture_rank regigigas_rank : 2;
    enum capture_rank unk_0487_rank : 2; // Giratina
    enum capture_rank cresselia_rank : 2;
    enum capture_rank unk_0489_rank : 2; // Phione
    enum capture_rank unk_0490_rank : 2; // Manaphy
    enum capture_rank darkrai_rank : 2;
    enum capture_rank shaymin_rank : 2;
    undefined field_0x2ef;
    undefined field_0x2f0;
    undefined field_0x2f1;
    undefined field_0x2f2;
    undefined field_0x2f3;
};
ASSERT_SIZE(struct ranger_pokedex, 756);

// Stored the time played in hours, minutes, and seconds.
struct play_time {
    int hours;
    int8_t minutes; // Created by retype action
    int8_t seconds;
    bool has_max_play_time;
    int8_t styler_level; // This is suspicious, but the alternative is that this struct is size 0x7.
};
ASSERT_SIZE(struct play_time, 8);

// Records for various things the player can do.
struct ranger_records {
    int32_t max_steps_record;
    int32_t conversations_record;
    int32_t targets_checked_record;
    int32_t game_saves_record;
    int32_t pokemon_rides_record;
    // This seems to determine the obscure "Best Partner" Ranger Record in-game. It increments by
    // one at the end of each battle where the partner used a poke-assist. Cannot exceed 9,999,999.
    int32_t best_partner_record_table[17];
    int32_t capture_line_len_record;
    int32_t num_loops_record;
    int16_t pokemon_captured_record;
    int16_t pokemon_fled_record;
    int16_t poke_assists_used_record;
    undefined field78_0x66;
    int8_t timer_type_active; // 0 = no timer, 1 = timer counting down, 2 = unknown
    int32_t timer_1_frames_left;
    int32_t timer_2_frames_left; // May count upwards. More clarification needed.
    // This seems to be the internal order used by the partners.
    enum partner_unlock_flag munchlax_met : 1;
    enum partner_unlock_flag chimchar_met : 1;
    enum partner_unlock_flag piplup_met : 1;
    enum partner_unlock_flag turtwig_met : 1;
    enum partner_unlock_flag pachirisu_met : 1;
    enum partner_unlock_flag snorunt_met : 1;
    enum partner_unlock_flag machop_met : 1;
    enum partner_unlock_flag croagunk_met : 1;
    enum partner_unlock_flag hippopotas_met : 1;
    enum partner_unlock_flag starly_met : 1;
    enum partner_unlock_flag mime_jr_met : 1;
    enum partner_unlock_flag kricketot_met : 1;
    enum partner_unlock_flag cranidos_met : 1;
    enum partner_unlock_flag misdreavus_met : 1;
    enum partner_unlock_flag gible_met : 1;
    enum partner_unlock_flag sneasel_met : 1;
    enum partner_unlock_flag shieldon_met : 1;
    enum partner_unlock_flag unused_flags : 15;
    struct play_time last_play_time;
    struct play_time current_play_time;
};
ASSERT_SIZE(struct ranger_records, 132);

struct ranger_glossary {
    // Start of the "Field" glossary bitfield
    enum glossary_table_entry friend_pokemon_entry : 2;
    enum glossary_table_entry partner_pokemon_entry : 2;
    enum glossary_table_entry partner_energy_entry : 2;
    enum glossary_table_entry happy_mood_entry : 2;
    enum glossary_table_entry release_entry : 2;
    enum glossary_table_entry partner_farm_entry : 2;
    enum glossary_table_entry field_moves_and_targets_entry : 2;
    enum glossary_table_entry target_clear_entry : 2;
    enum glossary_table_entry map_moves_entry : 2;
    enum glossary_table_entry recharge_entry : 2;
    enum glossary_table_entry agility_entry : 2;
    enum glossary_table_entry fly_entry : 2;
    enum glossary_table_entry teleport_entry : 2;
    enum glossary_table_entry area_moves_entry : 2;
    enum glossary_table_entry missions_entry : 2;
    enum glossary_table_entry quests_entry : 2;
    enum glossary_table_entry field_damage_entry : 2;
    enum glossary_table_entry change_screen_button_entry : 2;
    enum glossary_table_entry unk_entry_0 : 2;
    enum glossary_table_entry unk_entry_1 : 2;
    // Presumed to be padding.
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    undefined field_0x8;
    undefined field_0x9;
    undefined field_0xa;
    undefined field_0xb;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    // Start of the "Capture" glossary bitfield
    enum glossary_table_entry capture_disc_entry : 2;
    enum glossary_table_entry capture_line_entry : 2;
    enum glossary_table_entry capture_entry : 2;
    enum glossary_table_entry capture_results_entry : 2;
    enum glossary_table_entry styler_energy_entry : 2;
    enum glossary_table_entry styler_damage_entry : 2;
    enum glossary_table_entry styler_level_entry : 2;
    enum glossary_table_entry flee_entry : 2;
    enum glossary_table_entry power_charge_entry : 2;
    enum glossary_table_entry styler_status_entry : 2;
    enum glossary_table_entry power_up_data_entry : 2;
    enum glossary_table_entry poke_assists_entry : 2;
    enum glossary_table_entry poke_assist_matchups_entry : 2;
    enum glossary_table_entry poke_assist_grass_entry : 2;
    enum glossary_table_entry poke_assist_flying_entry : 2;
    enum glossary_table_entry poke_assist_normal_entry : 2;
    enum glossary_table_entry poke_assist_recharge_entry : 2;
    enum glossary_table_entry poke_assist_water_entry : 2;
    enum glossary_table_entry poke_assist_rock_entry : 2;
    enum glossary_table_entry poke_assist_electric_entry : 2;
    enum glossary_table_entry poke_assist_bug_entry : 2;
    enum glossary_table_entry poke_assist_fire_entry : 2;
    enum glossary_table_entry poke_assist_fighting_entry : 2;
    enum glossary_table_entry poke_assist_ground_entry : 2;
    enum glossary_table_entry poke_assist_steel_entry : 2;
    enum glossary_table_entry poke_assist_poison_entry : 2;
    enum glossary_table_entry poke_assist_ghost_entry : 2;
    enum glossary_table_entry poke_assist_psychic_entry : 2;
    enum glossary_table_entry poke_assist_dark_entry : 2;
    enum glossary_table_entry poke_assist_ice_entry : 2;
    enum glossary_table_entry poke_assist_dragon_entry : 2;
    enum glossary_table_entry poke_assist_special_effects_entry : 2;
    // Presumed to be padding.
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    // Start of the "Terms" header glossary bitfield
    enum glossary_table_entry pokemon_rangers_entry : 2;
    enum glossary_table_entry student_rangers_entry : 2;
    enum glossary_table_entry top_rangers_entry : 2;
    enum glossary_table_entry ranger_union_entry : 2;
    enum glossary_table_entry ranger_base_entry : 2;
    enum glossary_table_entry ranger_depot_entry : 2;
    enum glossary_table_entry ranger_rank_entry : 2;
    enum glossary_table_entry school_styler_entry : 2;
    enum glossary_table_entry capture_styler_entry : 2;
    enum glossary_table_entry fine_styler_entry : 2;
    enum glossary_table_entry vatonage_styler_entry : 2;
    enum glossary_table_entry ranger_record_entry : 2;
    enum glossary_table_entry capture_arena_entry : 2;
    enum glossary_table_entry ranger_school_entry : 2;
    enum glossary_table_entry chicole_village_entry : 2;
    enum glossary_table_entry vientown_entry : 2;
    enum glossary_table_entry vien_forest_entry : 2;
    enum glossary_table_entry pueltown_entry : 2;
    enum glossary_table_entry puel_sea_entry : 2;
    enum glossary_table_entry altru_park_entry : 2;
    enum glossary_table_entry altru_inc_entry : 2;
    enum glossary_table_entry peril_cliffs_entry : 2;
    enum glossary_table_entry boyleland_entry : 2;
    enum glossary_table_entry boyle_volcano_entry : 2;
    enum glossary_table_entry cargo_ship_entry : 2;
    enum glossary_table_entry chroma_highlands_entry : 2;
    enum glossary_table_entry chroma_ruins_entry : 2;
    enum glossary_table_entry altru_ruins_entry : 2;
    enum glossary_table_entry hia_valley_entry : 2;
    enum glossary_table_entry shiver_camp_entry : 2;
    enum glossary_table_entry ice_lake_entry : 2;
    enum glossary_table_entry almia_castle_entry : 2;
    enum glossary_table_entry sea_of_wailord_entry : 2;
    enum glossary_table_entry oil_field_hideout_entry : 2;
    enum glossary_table_entry haruba_village_entry : 2;
    enum glossary_table_entry hippowdon_temple_entry : 2;
    enum glossary_table_entry altru_tower_entry : 2;
    enum glossary_table_entry unk_entry_02 : 2;
    enum glossary_table_entry unk_entry_03 : 2;
    enum glossary_table_entry unk_entry_04 : 2;
    // Presumed to be padding.
    undefined field_0x2a;
    undefined field_0x2b;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
};

ASSERT_SIZE(struct ranger_glossary, 48);

struct following_npc {
    int is_valid; // 0x0: If true, an NPC is following the player.
    undefined4 unk_field0_0x4;
    int16_t sprite_id; // 0x8: Determines which sprite the following NPC will have.
    int16_t
        face_angle;   // 0xA: Continuous, Right = 0x0000, Down = 0x4000, Left = 0x8000, Up = 0xC000.
    int x_coordinate; // 0xC
    int y_coordinate; // 0x10
    char talk_script_func_name[32]; // 0x14: Unknown how long this actually is. Name of the script
                                    // function called when NPC is tapped.
    int16_t unk_field1_0x34;        // 0x34
    undefined unk_field1_0x36;      // 0x36
    undefined unk_field1_0x37;      // 0x37
};

ASSERT_SIZE(struct following_npc, 56);
/*
struct styler_upgrades {
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
};

ASSERT_SIZE(struct styler_upgrades, 6);
*/

// Most interactions with these values seem to treat them as tables of ints, rather than individual
// fields. For ghidra analysis in the short term, this struct will be a simple table for now, even
// though we know what some of these values mean.
struct settings_and_variables {
    // Generally, the event_variable_table can be thought of as chapter-specific scratch paper.
    int32_t event_variable_table[21];
    // Used to track in-game settings, and has a byte to play the unlock cutscene for a styler
    // upgrade.
    int32_t settings_variable_table[31];
    // Unknown, but debug prints seem to suggest these relate to quests. Or something else that
    // begins with q...
    int32_t quest_variable_table[11];
};

ASSERT_SIZE(struct settings_and_variables, 252);

// This struct is equivalent the the above event_variable_table, but with definitions instead of
// being an arbitrary table of ints.
struct event_variables {
    int32_t subchapter_progression; // 0x00: Seems to increase linearly, or to the nearest multiple
                                    // of 10. Sub-sub-chapters perhaps?
    int32_t scrach_paper[20];       // 0x04: Varies wildly by subchapter.
};

ASSERT_SIZE(struct event_variables, 84);

// This struct is equivalent the the above settings_variable_table, but with definitions instead of
// being an arbitrary table of ints.
struct settings_variables {
    int32_t unk_setting_0x0;
    int32_t window_border; // 0x4: Determines what color the textbox border will be.
    int32_t text_speed; // 0x8: 0x03 for slow, 0x02 for medium, 0x01 for fast. No other values seem
                        // to have an impact. :(
    // If non-zero, opening the styler upgrade menu will unlock a new styler upgrade.
    enum styler_unlock_upgrade_type styler_upgrade_interrupt; // 0xC
    // Incremented by the cutscene produced by the above field!
    int32_t num_styler_upgrades; // 0x10
    int32_t unk_settings[26];    // 0x14
};

ASSERT_SIZE(struct settings_variables, 124);

// This struct is equivalent the the above quest_variable_table, but with definitions instead of
// being an arbitrary table of ints.
struct quest_variables {
    // 0x0: Enabled when the Breeze Hill sign is repaired, disabled when starting a quest?
    // Either this is a bitflag of some kind, or it's actually used as a subquest progression
    // marker, and only starting a quest resets it?
    int32_t maybe_quest_progression;
    int32_t unk_quest_vars[10]; // 0x4: So far no use observed, but likely scratch paper to be used
                                // individually by quest.
};

ASSERT_SIZE(struct quest_variables, 44);

// This is populated in an unknown way before starting any battle.
struct battle_init {
    undefined unk_fields[2048];
};

ASSERT_SIZE(struct battle_init, 2048);

// This is primarily used to export battle data between overlays. Overlay_02 frequently reads this
// struct from the megastruct.
struct battle_exports {
    void* unk_fun_ptr_0x0;
    int8_t current_player_hp;
    undefined field2_0x5; // Likely padding
    undefined field3_0x6;
    undefined field4_0x7;
    int battle_result; // 1 = loss, 3 = flee, 2 and 4 still unknown. Will continue to research.
    int8_t
        invincibility_frame_mode; // When 0 or 2, seems normal. If 1, collision is active the
                                  // instant the battle ends. May be used for battles in cutscenes
    undefined field7_0xd;         // Likely padding
    undefined field8_0xe;
    undefined field9_0xf;
    int partner_assist_gauge;
    int8_t num_pokemon_encountered; // Created by Rename Structure Field action
    undefined field12_0x15;         // Likely padding
    undefined field13_0x16;
    undefined field14_0x17;
    int unk_enemy_fields_0x18[2][8]; // might be room_id and something else smooshed together?
    int8_t num_pokemon_caught;       // Created by Rename Structure Field action
    undefined field17_0x59;          // Likely padding
    int16_t caught_form_ids[8];
    struct capture_rank_8 current_capture_rank;
    undefined1 can_partner_poke_assist; // Created by Rename Structure Field action
    int8_t party_pokemon;
    int8_t poke_assists_used[8];
    undefined field23_0x75; // Likely padding
    undefined field24_0x76;
    undefined field25_0x77;
    int total_lines_made;
    int total_loops_made;
    int exp_gained;
};
ASSERT_SIZE(struct battle_exports, 132);

struct battle_combatants {
    int* unk_struct_ptr_0x0;
    int8_t current_hp;
    int8_t styler_level;
    bool partner_assist_unlocked;
    undefined field4_0x7;
    int partner_gauge_current;
    int partner_gauge_max;
    int partner_gauge_fill_rate;
    int8_t num_party_pokemon;
    undefined field9_0x15;
    int16_t party_form_ids[8];
    int8_t party_slot_statuses_table[8];
    int8_t num_enemy_forms;
    undefined field13_0x2f;
    int16_t enemy_form_ids[4];
    int8_t unk_enemy_data_0x38[4];
    int8_t unk_enemy_data_0x3C[4];
    int8_t num_enemy_pokemon;      // Created by Rename Structure Field action
    int8_t unk_enemy_data_0x41[8]; // Might be related to enemy catch status?
    int8_t arena_graphic_id;
    int8_t weather_graphic_id;
    int8_t sequence_script_id; // runs "data/script/battle/sequence/s%03d.fsb" with this id.
    int8_t tutorial_script_id; // runs "data/script/battle/tutorial/s%03d.fsb" with this id.
    int8_t start_script_id;    // runs "data/script/battle/start/s%03d.fsb" with this id.
    int8_t bgm_id;
    bool can_view_party;
    bool can_flee;
    bool show_boss_health_bar;
    int8_t field28_0x52;
    undefined field29_0x53;
    int8_t field30_0x54;
    undefined field31_0x55;
    int16_t gender_and_uniform; // bit 0: ranger_gender. bit 1+ styler_type, aka uniform
    int8_t field_alloc_bits;    // bit 0: , bit 1: , bit 2: field_0x56.
    undefined field34_0x59;
    undefined field35_0x5a;
    undefined field36_0x5b;
    // May be larger than this!
};

ASSERT_SIZE(struct battle_combatants, 92);

struct trigger_spawn_nibbles {
    enum map_nibble trigger_00 : 4;
    enum map_nibble trigger_01 : 4;
    enum map_nibble trigger_02 : 4;
    enum map_nibble trigger_03 : 4;
    enum map_nibble trigger_04 : 4;
    enum map_nibble trigger_05 : 4;
    enum map_nibble trigger_06 : 4;
    enum map_nibble trigger_07 : 4;
    enum map_nibble trigger_08 : 4;
    enum map_nibble trigger_09 : 4;
    enum map_nibble trigger_10 : 4;
    enum map_nibble trigger_11 : 4;
    enum map_nibble trigger_12 : 4;
    enum map_nibble trigger_13 : 4;
    enum map_nibble trigger_14 : 4;
    enum map_nibble trigger_15 : 4;
    enum map_nibble trigger_16 : 4;
    enum map_nibble trigger_17 : 4;
    enum map_nibble trigger_18 : 4;
    enum map_nibble trigger_19 : 4;
    enum map_nibble trigger_20 : 4;
    enum map_nibble trigger_21 : 4;
    enum map_nibble trigger_22 : 4;
    enum map_nibble trigger_23 : 4;
    enum map_nibble trigger_24 : 4;
    enum map_nibble trigger_25 : 4;
    enum map_nibble trigger_26 : 4;
    enum map_nibble trigger_27 : 4;
    enum map_nibble trigger_28 : 4;
    enum map_nibble trigger_29 : 4;
    enum map_nibble trigger_30 : 4;
    enum map_nibble trigger_31 : 4;
    enum map_nibble trigger_32 : 4;
    enum map_nibble trigger_33 : 4;
    enum map_nibble trigger_34 : 4;
    enum map_nibble trigger_35 : 4;
    enum map_nibble trigger_36 : 4;
    enum map_nibble trigger_37 : 4;
    enum map_nibble trigger_38 : 4;
    enum map_nibble trigger_39 : 4;
    enum map_nibble trigger_40 : 4;
    enum map_nibble trigger_41 : 4;
    enum map_nibble trigger_42 : 4;
    enum map_nibble trigger_43 : 4;
    enum map_nibble trigger_44 : 4;
    enum map_nibble trigger_45 : 4;
    enum map_nibble trigger_46 : 4;
    enum map_nibble trigger_47 : 4;
};

ASSERT_SIZE(struct trigger_spawn_nibbles, 24);

struct pokemon_spawn_nibbles {
    enum map_nibble pokemon_00 : 4;
    enum map_nibble pokemon_01 : 4;
    enum map_nibble pokemon_02 : 4;
    enum map_nibble pokemon_03 : 4;
    enum map_nibble pokemon_04 : 4;
    enum map_nibble pokemon_05 : 4;
    enum map_nibble pokemon_06 : 4;
    enum map_nibble pokemon_07 : 4;
    enum map_nibble pokemon_08 : 4;
    enum map_nibble pokemon_09 : 4;
    enum map_nibble pokemon_10 : 4;
    enum map_nibble pokemon_11 : 4;
    enum map_nibble pokemon_12 : 4;
    enum map_nibble pokemon_13 : 4;
    enum map_nibble pokemon_14 : 4;
    enum map_nibble pokemon_15 : 4;
    enum map_nibble pokemon_16 : 4;
    enum map_nibble pokemon_17 : 4;
    enum map_nibble pokemon_18 : 4;
    enum map_nibble pokemon_19 : 4;
    enum map_nibble pokemon_20 : 4;
    enum map_nibble pokemon_21 : 4;
    enum map_nibble pokemon_22 : 4;
    enum map_nibble pokemon_23 : 4;
    enum map_nibble pokemon_24 : 4;
    enum map_nibble pokemon_25 : 4;
    enum map_nibble pokemon_26 : 4;
    enum map_nibble pokemon_27 : 4;
    enum map_nibble pokemon_28 : 4;
    enum map_nibble pokemon_29 : 4;
    enum map_nibble pokemon_30 : 4;
    enum map_nibble pokemon_31 : 4;
};

ASSERT_SIZE(struct pokemon_spawn_nibbles, 16);

struct npc_spawn_nibbles {
    enum map_nibble npc_00 : 4;
    enum map_nibble npc_01 : 4;
    enum map_nibble npc_02 : 4;
    enum map_nibble npc_03 : 4;
    enum map_nibble npc_04 : 4;
    enum map_nibble npc_05 : 4;
    enum map_nibble npc_06 : 4;
    enum map_nibble npc_07 : 4;
    enum map_nibble npc_08 : 4;
    enum map_nibble npc_09 : 4;
    enum map_nibble npc_10 : 4;
    enum map_nibble npc_11 : 4;
    enum map_nibble npc_12 : 4;
    enum map_nibble npc_13 : 4;
    enum map_nibble npc_14 : 4;
    enum map_nibble npc_15 : 4;
    enum map_nibble npc_16 : 4;
    enum map_nibble npc_17 : 4;
    enum map_nibble npc_18 : 4;
    enum map_nibble npc_19 : 4;
    enum map_nibble npc_20 : 4;
    enum map_nibble npc_21 : 4;
    enum map_nibble npc_22 : 4;
    enum map_nibble npc_23 : 4;
    enum map_nibble npc_24 : 4;
    enum map_nibble npc_25 : 4;
    enum map_nibble npc_26 : 4;
    enum map_nibble npc_27 : 4;
    enum map_nibble npc_28 : 4;
    enum map_nibble npc_29 : 4;
    enum map_nibble npc_30 : 4;
    enum map_nibble npc_31 : 4;
};

ASSERT_SIZE(struct npc_spawn_nibbles, 16);

struct target_destroyed_nibbles {
    enum map_nibble target_00 : 4;
    enum map_nibble target_01 : 4;
    enum map_nibble target_02 : 4;
    enum map_nibble target_03 : 4;
    enum map_nibble target_04 : 4;
    enum map_nibble target_05 : 4;
    enum map_nibble target_06 : 4;
    enum map_nibble target_07 : 4;
    enum map_nibble target_08 : 4;
    enum map_nibble target_09 : 4;
    enum map_nibble target_10 : 4;
    enum map_nibble target_11 : 4;
    enum map_nibble target_12 : 4;
    enum map_nibble target_13 : 4;
    enum map_nibble target_14 : 4;
    enum map_nibble target_15 : 4;
    enum map_nibble target_16 : 4;
    enum map_nibble target_17 : 4;
    enum map_nibble target_18 : 4;
    enum map_nibble target_19 : 4;
    enum map_nibble target_20 : 4;
    enum map_nibble target_21 : 4;
    enum map_nibble target_22 : 4;
    enum map_nibble target_23 : 4;
    enum map_nibble target_24 : 4;
    enum map_nibble target_25 : 4;
    enum map_nibble target_26 : 4;
    enum map_nibble target_27 : 4;
    enum map_nibble target_28 : 4;
    enum map_nibble target_29 : 4;
    enum map_nibble target_30 : 4;
    enum map_nibble target_31 : 4;
};

ASSERT_SIZE(struct target_destroyed_nibbles, 16);

struct field_data {
    struct file_wrapper* field_data_file_wrapper;
    void* npc_data;   // Not currently understood, but described as such by field_data.bin
    void* enemy_data; // Not currently understood, but described as such by field_data.bin
    void* tobj_data;  // Not currently understood, but described as such by field_data.bin
    void* map_data;   // Not currently understood, but described as such by field_data.bin
};
ASSERT_SIZE(struct field_data, 20);

#include "ranger_data.h"

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
    struct pokemon_data party_group_0[8]; // 0x8804
    struct pokemon_data party_group_1[8]; // 0x88C4
    struct pokemon_data party_group_2[8]; // 0x8984
    struct following_npc follower_1;      // 0x8A44
    struct following_npc follower_2;      // 0x8A7C
    struct quest_body quest_body;         // 0x8AB4
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

#endif
