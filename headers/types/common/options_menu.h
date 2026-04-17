#ifndef HEADERS_TYPES_COMMON_OPTIONS_MENU_H_
#define HEADERS_TYPES_COMMON_OPTIONS_MENU_H_

#include "enums.h"
#include "common.h"
#include "battle.h"
#include "textbox.h"

// All ov_06 functions that take parameters seem to take this as param_1.
struct options_menu {
    void* unk_fun_ptr;
    undefined* unk_struct_size_0x44_ptr_1;
    undefined* unk_struct_size_0x44_ptr_2;
    undefined*
        text_speed_button_struct_ptr[4]; // When poked, the text speed buttons lose functionality
    undefined*
        window_type_button_struct_ptr[8]; // When poked, the window buttons lose functionality
    undefined* back_button_struct_ptr;    // When poked, the back button stops working.
    int icon_types_text_speed[3]; // Determines the which icons should be used for the text speed
                                  // slots.
    int icon_types_windows[8];    // Determines the which icons should be used for the window option
                                  // slots.
    int cursor_icon_pos; // Determines which icon hovers over the most recently selected option.
    struct megastruct* megastruct_ptr;
    int screen_fadeout_timer; // If not zero, counts down the number of frames until the overlay
                              // should be exited.
    undefined field11_0x78;
    undefined field12_0x79;
    undefined field13_0x7a;
    undefined field14_0x7b;
    int window_setting;
    int text_speed_setting;
    undefined4* unk_struct_size_0xc_ptr_1;    // When poked, the entire menu freezes. Presumed to
                                              // handle idle animations?
    struct msg_wrapper* menu_msg_wrapper_ptr; // When poked, the back button causes a freeze.
};

ASSERT_SIZE(struct options_menu, 140);

#endif