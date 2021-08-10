typedef uint32_t in_addr_t;
typedef uint16_t in_port_t;
typedef unsigned short sa_family_t;

struct in_addr {
  in_addr_t s_addr;
};

struct sockaddr_in {
  uint8_t sin_len;
  sa_family_t sin_family;
  in_port_t sin_port;
  struct in_addr sin_addr;
  unsigned char sin_zero[8];
};

struct in6_addr {
  uint8_t s6_addr[16];
}

struct sockaddr_in6 {
  uint8_t sin6_len;
  sa_family_t sin6_family;
  in_port_t sin6_port;
  uint32_t sin6_flowinfo;
  struct in6_addr sin6_addr;
};

struct sockaddr {
  uint8_t sin6_len;
  sa_family_t sin6_family;
  char sin_data[14];
};