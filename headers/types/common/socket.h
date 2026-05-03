#ifndef HEADERS_TYPES_SOCKET_H_
#define HEADERS_TYPES_SOCKET_H_

// Someone who know what tf these are/mean can put these where they belong.
typedef ushort sa_family_t;
typedef uint __socklen_t;
typedef __socklen_t socklen_t;

struct sockaddr_in {
    uint8_t len;
    uint8_t family;
    uint16_t port;
    uint8_t ip[4];
};
ASSERT_SIZE(struct sockaddr_in, 8);

struct sockaddr {
    sa_family_t sa_family; // actually a "sa_family_t", whatever that means.
    char sa_data[14];
};
ASSERT_SIZE(struct sockaddr, 16);
#endif