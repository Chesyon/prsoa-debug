#ifndef HEADERS_TYPES_COMMON_FLYING_MENU_H_
#define HEADERS_TYPES_COMMON_FLYING_MENU_H_

#include "enums.h"

// At some point, the unfinished overlay_09 structs should be moved here.

struct fly_destination {
    struct room_id_16 room;
    int16_t coordinates[2];
    undefined2 unk_field_0x6; // Perhaps coordinates for the button on the map? Not entirely clear
    undefined2 unk_field_0x8;
    undefined1 unk_field_0xa;
    undefined1 unk_field_0xb; // This seems to be checked in GetSelectedFlyLocation
    undefined2 unk_field_0xc;
    undefined2 unk_msg_id; // This seems to be a message_id. Perhaps for the string on using fly?
};

ASSERT_SIZE(struct fly_destination, 16);

#endif