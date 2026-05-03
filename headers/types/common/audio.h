#ifndef HEADERS_TYPES_AUDIO_H_
#define HEADERS_TYPES_AUDIO_H_


struct nnsi_gfd_lnk_vram_block {
    uint32_t addr;
    uint32_t sz_bytes;
    struct nnsi_gfd_lnk_vram_block *blk_prev_ptr;
    struct nnsi_gfd_lnk_vram_block *blk_next_ptr;
};
ASSERT_SIZE(struct nnsi_gfd_lnk_vram_block, 16);

struct snd_binary_block_file_header {
    uint32_t kind;
    uint32_t size;
};
ASSERT_SIZE(struct snd_binary_block_file_header, 8);

struct snd_bin_block_file_header {
    uint32_t kind;
    uint32_t size;
};
ASSERT_SIZE(struct snd_bin_block_file_header, 8);

struct nns_snd_arc_info {
    struct snd_bin_block_file_header block_header;
    uint32_t seq_offset;
    uint32_t seq_arc_offset;
    uint32_t bank_offset;
    uint32_t wave_arc_offset;
    uint32_t player_info_offset;
    uint32_t group_info_offset;
    uint32_t strm_player_info_offset;
    uint32_t strm_offset;
};
ASSERT_SIZE(struct nns_snd_arc_info, 40);

struct nns_snd_strm_handle {
    void *player; // NNSSndStrmPlayer
};
ASSERT_SIZE(struct nns_snd_strm_handle, 4);

struct nns_snd_seq_handle {
    void *player;
};
ASSERT_SIZE(struct nns_snd_seq_handle, 4);

struct snd_binary_file_header {
    char signature[4];
    uint16_t byte_order;
    uint16_t version;
    uint32_t file_size;
    uint16_t header_size;
    uint16_t data_blocks;
};
ASSERT_SIZE(struct snd_binary_file_header, 16);

struct nns_snd_arc_header {
    struct snd_binary_file_header file_header;
    uint32_t symbol_data_offset;
    uint32_t symbol_data_size;
    uint32_t info_offset;
    uint32_t info_size;
    uint32_t fat_offset;
    uint32_t fat_size;
    uint32_t file_image_offset;
    uint32_t file_image_size;
};
ASSERT_SIZE(struct nns_snd_arc_header, 48);

struct nns_snd_arc_file_info {
    uint32_t offset;
    uint32_t size;
    void *mem;
    uint32_t reserved;
};
ASSERT_SIZE(struct nns_snd_arc_file_info, 16);


struct nns_snd_arc_fat {
    struct snd_binary_block_file_header block_header;
    uint32_t count;
    struct nns_snd_arc_file_info files[0];
};
// No ASSERT_SIZE, this expands as files are added!


struct nns_snd_arc_symbol {
    struct snd_bin_block_file_header block_header;
    uint32_t seq_offset;
    uint32_t seq_arc_offset;
    uint32_t bank_offset;
    uint32_t wave_arc_offset;
    uint32_t player_info_offset;
    uint32_t group_info_offset;
    uint32_t strm_player_info_offset;
    uint32_t strm_offset;
};
ASSERT_SIZE(struct nns_snd_arc_symbol, 40);


struct nns_snd_arc {
    struct nns_snd_arc_header header;
    bool file_open;
    struct fs_file file;
    struct fs_file_id file_id;
    struct nns_snd_arc_fat *fat;
    struct nns_snd_arc_symbol *symbol;
    struct nns_snd_arc_info *info;
};
ASSERT_SIZE(struct nns_snd_arc, 144);

struct audio_engine {
    void *unk_heap_1_ptr; // Size 0x64000
    void *unk_heap_2_ptr; // Size 0x30000
    void *strm_buffer_heap_ptr; // Size 0xc000
    struct nns_snd_arc snd_archive;
    void *unk_heap_1_handle_ptr;
    void *unk_heap_2_handle_ptr;
    void *strm_buffer_heap_handle_ptr;
    struct nns_snd_strm_handle snd_strm_handle_table[2];
    struct nns_snd_seq_handle snd_seq_handle_table[5];
    uint32_t current_arc_group_num;
    uint32_t next_arc_group_num;
    int unk_settings_var_field_0xcc;
    uint32_t current_seq_num;
    uint32_t next_seq_num;
    undefined4 field19_0xd8;
    undefined4 field20_0xdc;
    undefined4 field21_0xe0;
    undefined4 unk_field_for_processed_struct_0x64000;
    undefined4 field23_0xe8;
    undefined4 field24_0xec;
    int unk_settings_var_field_0xf0;
    undefined4 field26_0xf4;
    int field27_0xf8;
    undefined4 field28_0xfc;
    undefined field29_0x100;
    undefined field30_0x101;
    undefined field31_0x102;
    undefined field32_0x103;
    undefined field33_0x104;
    undefined field34_0x105;
    undefined field35_0x106;
    undefined field36_0x107;
    undefined field37_0x108;
    undefined field38_0x109;
    undefined field39_0x10a;
    undefined field40_0x10b;
    undefined field41_0x10c;
    undefined field42_0x10d;
    undefined field43_0x10e;
    undefined field44_0x10f;
    undefined field45_0x110;
    undefined field46_0x111;
    undefined field47_0x112;
    undefined field48_0x113;
    undefined field49_0x114;
    undefined field50_0x115;
    undefined field51_0x116;
    undefined field52_0x117;
    undefined field53_0x118;
    undefined field54_0x119;
    undefined field55_0x11a;
    undefined field56_0x11b;
    undefined field57_0x11c;
    undefined field58_0x11d;
    undefined field59_0x11e;
    undefined field60_0x11f;
    undefined field61_0x120;
    undefined field62_0x121;
    undefined field63_0x122;
    undefined field64_0x123;
    void *unk_struct_off_0x124;
    undefined field66_0x128;
    undefined field67_0x129;
    undefined field68_0x12a;
    undefined field69_0x12b;
    undefined field70_0x12c;
    undefined field71_0x12d;
    undefined field72_0x12e;
    undefined field73_0x12f;
    undefined field74_0x130;
    undefined field75_0x131;
    undefined field76_0x132;
    undefined field77_0x133;
    undefined field78_0x134;
    undefined field79_0x135;
    undefined field80_0x136;
    undefined field81_0x137;
    undefined field82_0x138;
    undefined field83_0x139;
    undefined field84_0x13a;
    undefined field85_0x13b;
    undefined field86_0x13c;
    undefined field87_0x13d;
    undefined field88_0x13e;
    undefined field89_0x13f;
    undefined field90_0x140;
    undefined field91_0x141;
    undefined field92_0x142;
    undefined field93_0x143;
    undefined field94_0x144;
    undefined field95_0x145;
    undefined field96_0x146;
    undefined field97_0x147;
    undefined field98_0x148;
    undefined field99_0x149;
    undefined field100_0x14a;
    undefined field101_0x14b;
    undefined field102_0x14c;
    undefined field103_0x14d;
    undefined field104_0x14e;
    undefined field105_0x14f;
    undefined field106_0x150;
    undefined field107_0x151;
    undefined field108_0x152;
    undefined field109_0x153;
    undefined field110_0x154;
    undefined field111_0x155;
    undefined field112_0x156;
    undefined field113_0x157;
    undefined field114_0x158;
    undefined field115_0x159;
    undefined field116_0x15a;
    undefined field117_0x15b;
    undefined field118_0x15c;
    undefined field119_0x15d;
    undefined field120_0x15e;
    undefined field121_0x15f;
    undefined field122_0x160;
    undefined field123_0x161;
    undefined field124_0x162;
    undefined field125_0x163;
    undefined field126_0x164;
    undefined field127_0x165;
    undefined field128_0x166;
    undefined field129_0x167;
    undefined field130_0x168;
    undefined field131_0x169;
    undefined field132_0x16a;
    undefined field133_0x16b;
    undefined field134_0x16c;
    undefined field135_0x16d;
    undefined field136_0x16e;
    undefined field137_0x16f;
    undefined field138_0x170;
    undefined field139_0x171;
    undefined field140_0x172;
    undefined field141_0x173;
    undefined field142_0x174;
    undefined field143_0x175;
    undefined field144_0x176;
    undefined field145_0x177;
    undefined field146_0x178;
    undefined field147_0x179;
    undefined field148_0x17a;
    undefined field149_0x17b;
    undefined field150_0x17c;
    undefined field151_0x17d;
    undefined field152_0x17e;
    undefined field153_0x17f;
    undefined field154_0x180;
    undefined field155_0x181;
    undefined field156_0x182;
    undefined field157_0x183;
    undefined field158_0x184;
    undefined field159_0x185;
    undefined field160_0x186;
    undefined field161_0x187;
    undefined field162_0x188;
    undefined field163_0x189;
    undefined field164_0x18a;
    undefined field165_0x18b;
    undefined field166_0x18c;
    undefined field167_0x18d;
    undefined field168_0x18e;
    undefined field169_0x18f;
    undefined field170_0x190;
    undefined field171_0x191;
    undefined field172_0x192;
    undefined field173_0x193;
    undefined field174_0x194;
    undefined field175_0x195;
    undefined field176_0x196;
    undefined field177_0x197;
    undefined field178_0x198;
    undefined field179_0x199;
    undefined field180_0x19a;
    undefined field181_0x19b;
    undefined field182_0x19c;
    undefined field183_0x19d;
    undefined field184_0x19e;
    undefined field185_0x19f;
    int seq_3_volume;
    undefined field187_0x1a4;
    undefined field188_0x1a5;
    undefined field189_0x1a6;
    undefined field190_0x1a7;
    int unk_heap_1_state;
};
ASSERT_SIZE(struct audio_engine, 428);

#endif