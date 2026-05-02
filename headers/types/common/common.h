// Shared types used throughout the game

#ifndef HEADERS_TYPES_COMMON_H_
#define HEADERS_TYPES_COMMON_H_

#include "enums.h"
// No Dependencies besides enums.h
#include "util.h"
#include "battle_extras.h"
#include "browser.h"
#include "clock.h"
#include "classes.h"
#include "display.h"
#include "file.h"
#include "flying_menu.h"
#include "glossary.h"
#include "pokemon_and_followers.h"
#include "settings_and_variables.h"
#include "styler.h"
// Requires some of the above dependencies
#include "audio.h"
#include "field_data.h"
#include "map.h"
#include "ranger_records.h"
#include "param_file.h"
#include "textbox.h"
#include "script.h"
// Requires some of the above dependencies
#include "mission_quest.h"

// Requires some of the above dependencies
#include "ranger_data.h"
// Requires common.h
#include "megastruct.h"

// Requires ranger_data.h
#include "save.h"

// Requires megastruct.h
#include "battle.h"
#include "options_menu.h"
#include "unfinished.h"

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

struct lcrng_state {
    int32_t current_state;
    int32_t mult;
    int32_t add;
};
ASSERT_SIZE(struct lcrng_state, 12);

#endif
