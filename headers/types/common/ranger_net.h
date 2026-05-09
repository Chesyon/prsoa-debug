#ifndef HEADERS_TYPES_COMMON_RANGER_NET_H_
#define HEADERS_TYPES_COMMON_RANGER_NET_H_

// Not sure what this does yet. Might be in need of a rename.
struct ranger_net_data {
    undefined2 mission_completion_bits;
    undefined field1_0x2;
    undefined field2_0x3;
    struct unk_save_struct_0x74* unk_save_struct_0x74;
};

struct ranger_net_header {
    char dsprs_string[8];
    uint32_t save_file_offset; // number of bytes into the save file this block should live
    int unk_field_0xc;         // Always -1?
    undefined field3_0x10;
    undefined field4_0x11;
    undefined field5_0x12;
    undefined field6_0x13;
    undefined field7_0x14;
    undefined field8_0x15;
    undefined field9_0x16;
    undefined field10_0x17;
    undefined field11_0x18;
    undefined field12_0x19;
    undefined field13_0x1a;
    undefined field14_0x1b;
    undefined field15_0x1c;
    undefined field16_0x1d;
    undefined field17_0x1e;
    undefined field18_0x1f;
};
ASSERT_SIZE(struct ranger_net_header, 0x20);

struct ranger_net_body {
    int8_t rc4_compressed_script[12288];
};
ASSERT_SIZE(struct ranger_net_body, 0x3000);

struct ranger_net_bin {
    struct ranger_net_header header;
    struct ranger_net_body body;
};
ASSERT_SIZE(struct ranger_net_bin, 0x3020);

struct ranger_net_0x3004 {
    struct unk_save_struct_0x74* save_struct_0x74_ptr;
    struct ranger_net_body ranger_net_body;
};
ASSERT_SIZE(struct ranger_net_0x3004, 0x3004);

#endif