#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef uint32_t in_addr_t;
typedef uint16_t in_port_t;
typedef unsigned short sa_family_t;

// IPv4
struct in_addr
{
  /* data */
  in_addr_t s_addr;
};

struct sockaddr_in 
{
  /* data */
  uint8_t sin_len; // 地址长度
  sa_family_t sin_family; // 地址类型
  int_port_t sin_port; // 端口
  struct in_addr sin_addr;
  char sin_zero[8];
};

// IPv6
struct in6_addr
{
  /* data */
  uint8_t s6_addr[16];
};

struct sockadd_in6 {
  uint8_t sin6_len; 
  sa_family_t sin6_family;
  in_addr_t sin6_port;
  uint32_t sin6_flowinfo;
  struct in6_addr sin6_addr;
};

// 通用套接字类型
struct sockaddr
{
  /* data */
  uint8_t sa_len;
  sa_family_t sa_family;
  char sa_data[14];
};
