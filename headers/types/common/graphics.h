#ifndef HEADERS_TYPES_GRAPHICS_H_
#define HEADERS_TYPES_GRAPHICS_H_

struct nns_g2d_image_palette_proxy {
    uint fmt; // enum GXTexFmt
    bool b_extended_plt;
    uint32_t nns_g2d_vram_location[3]; // NNSG2dVRamLocation, size assumed
};
// Not confident in size. No Assert.

struct nns_gfd_vram_transfer_task {
    int type;
    void *source_ptr;
    uint32_t dst_addr;
    uint32_t sz_byte;
};
ASSERT_SIZE(struct nns_gfd_vram_transfer_task, 16);

#endif