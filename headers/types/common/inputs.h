#ifndef HEADERS_TYPES_COMMON_INPUTS_H_
#define HEADERS_TYPES_COMMON_INPUTS_H_

struct controller_inputs {
    int16_t held_buttons_bitfield;
    int16_t pressed_buttons_bitfield;
    int16_t buttons_bitfield_0x4;
    int16_t buttons_bitfield_0x6;
    int8_t field_0x8;
    int8_t unk_timer_max;
    int16_t unk_timers[16];
    bool set_unk_timer_16_to_0xFF;
    undefined field_0x2b;
};
ASSERT_SIZE(struct controller_inputs, 44);

struct ts_calibrations {
    undefined2 field0_0x0;
    int16_t x0;
    int16_t y0;
    int16_t xDotSize;
    int16_t yDotSize;
    undefined2 field_1_0xa;
};
ASSERT_SIZE(struct ts_calibrations, 12);

struct touch_screen {
    undefined *field0_0x0;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    undefined field5_0x8;
    undefined field6_0x9;
    undefined2 field7_0xa;
    undefined2 field8_0xc;
    undefined2 field9_0xe;
    undefined2 field10_0x10;
    undefined2 field11_0x12;
    undefined2 field12_0x14;
    undefined field13_0x16;
    undefined field14_0x17;
    undefined field15_0x18;
    undefined field16_0x19;
    undefined field17_0x1a;
    undefined field18_0x1b;
    undefined field19_0x1c;
    undefined field20_0x1d;
    undefined2 field21_0x1e;
    undefined2 field22_0x20;
    undefined2 field23_0x22;
    undefined2 field24_0x24;
    struct ts_calibrations field25_0x26;
};
ASSERT_SIZE(struct touch_screen, 48);

struct touch_screen_wrapper {
    struct touch_screen touch_screen;
    undefined field1_0x30;
    undefined field2_0x31;
    undefined field3_0x32;
    undefined field4_0x33;
    undefined field5_0x34;
    undefined field6_0x35;
    undefined field7_0x36;
    undefined field8_0x37;
    undefined field9_0x38;
    undefined field10_0x39;
    undefined field11_0x3a;
    undefined field12_0x3b;
    undefined field13_0x3c;
    undefined field14_0x3d;
    undefined field15_0x3e;
    undefined field16_0x3f;
    undefined field17_0x40;
    undefined field18_0x41;
    undefined field19_0x42;
    undefined field20_0x43;
    undefined field21_0x44;
    undefined field22_0x45;
    undefined field23_0x46;
    undefined field24_0x47;
    undefined field25_0x48;
    undefined field26_0x49;
    undefined field27_0x4a;
    undefined field28_0x4b;
    undefined field29_0x4c;
    undefined field30_0x4d;
    undefined field31_0x4e;
    undefined field32_0x4f;
    undefined field33_0x50;
    undefined field34_0x51;
    undefined field35_0x52;
    undefined field36_0x53;
};
ASSERT_SIZE(struct touch_screen_wrapper, 84);

#endif