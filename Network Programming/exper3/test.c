#include "pcap.h"
#include <remote-ext.h>
#include <stdio.h>

/* 4字节的IP地址*/
typedef struct ip_address
{
  u_char byte1;
  u_char byte2;
  u_char byte3;
  u_char byte4;
} ip_address;

/* IPv4 首部*/
#define IPPROTO_TCP 6
#define IPPROTO_UDP 17
#define IPPROTO_ICMP 1
#define IPPROTO_IGMP 2
typedef struct ip_header
{
  u_char ver_ihl;         // 版本(4 bits) + 首部长度(4 bits)
  u_char tos;             // 服务类型(Type of service)
  u_short tlen;           // 总长(Total length)
  u_short identification; // 标识(Identification)
  u_short flags_fo;       // 标志位(Flags) (3 bits) + 段偏移量(Fragment offset) (13 bits)
  u_char ttl;             // 存活时间(Time to live)
  u_char proto;           // 协议(Protocol)
  u_short crc;            // 首部校验和(Header checksum)
  ip_address saddr;       // 源地址(Source address)
  ip_address daddr;       // 目的地址(Destination address)
  u_int op_pad;           // 选项与填充(Option + Padding)
} ip_header;
/*tcp 首部*/
typedef struct tcp_header
{
  u_short th_sport; //16位源端口
  u_short th_dport; //16位目的端口
  u_int th_seq;     //32位序列号
  u_int th_ack;     //32位确认号
                    // byte th_lenres;    //4位首部长度/6位保留字
  u_short th_offx2; /* data offset, rsvd */
#define TH_OFF(th) (((th)->th_offx2 & 0xf0) >> 4)
  byte th_flag;   //6位标志位
  u_short th_win; //16位窗口大小
  u_short th_sum; //16位校验和
  u_short th_urp; //16位紧急数据偏移量
} tcp_header;

/* UDP 首部*/
typedef struct udp_header
{
  u_short sport; // 源端口(Source port)
  u_short dport; // 目的端口(Destination port)
  u_short len;   // UDP数据包长度(Datagram length)
  u_short crc;   // 校验和(Checksum)
} udp_header;
/*TLS首部*/
#define Change_Cipher_Spec 20
#define Alert 21
#define Handshake 22
#define Application_Data 23
typedef struct ProtocolVersion
{
  u_short major, minor;
} ProtocolVersion;

ProtocolVersion version = {3, 1}; /* TLS v1.0 */
typedef struct TLSPlaintext
{
  u_char ContentType;
  ProtocolVersion version;
  u_short length;
  // opaque fragment[TLSPlaintext.length];
} TLSPlaintext;

/* 回调函数原型*/

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

main()
{
  pcap_if_t *alldevs;
  pcap_if_t *d;
  int inum;
  int i = 0;
  pcap_t *adhandle;
  char errbuf[PCAP_ERRBUF_SIZE];
  u_int netmask;
  char packet_filter[] = "ip and tcp";
  struct bpf_program fcode;

  /* 获得设备列表*/
  if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL, &alldevs, errbuf) == -1)
  {
    fprintf(stderr, "Error in pcap_findalldevs: %sn", errbuf);
    exit(1);
  }

  /* 打印列表*/
  for (d = alldevs; d; d = d->next)
  {
    printf("%d. %s", ++i, d->name);
    if (d->description)
      printf(" (%s)\n", d->description);
    else
      printf(" (No description available)\n");
  }

  if (i == 0)
  {
    printf("nNo interfaces found! Make sure WinPcap is installed.\n");
    return -1;
  }

  printf("Enter the interface number (1-%d):", i);
  scanf("%d", &inum);

  if (inum < 1 || inum > i)
  {
    printf("nInterface number out of range.\n");
    /* 释放设备列表*/
    pcap_freealldevs(alldevs);
    return -1;
  }

  /* 跳转到已选设备*/
  for (d = alldevs, i = 0; i < inum - 1; d = d->next, i++)
    ;

  /* 打开适配器*/
  if ((adhandle = pcap_open(d->name, // 设备名
                            65536,   // 要捕捉的数据包的部分
                            // 65535保证能捕获到不同数据链路层上的每个数据包的全部内容
                            PCAP_OPENFLAG_PROMISCUOUS, // 混杂模式
                            1000,                      // 读取超时时间
                            NULL,                      // 远程机器验证
                            errbuf                     // 错误缓冲池
                            )) == NULL)
  {
    fprintf(stderr, "nUnable to open the adapter. %s is not supported by WinPcapn");
    /* 释放设备列表*/
    pcap_freealldevs(alldevs);
    return -1;
  }

  /* 检查数据链路层，为了简单，我们只考虑以太网*/
  if (pcap_datalink(adhandle) != DLT_EN10MB)
  {
    fprintf(stderr, "nThis program works only on Ethernet networks.\n");
    /* 释放设备列表*/
    pcap_freealldevs(alldevs);
    return -1;
  }

  if (d->addresses != NULL)
    /* 获得接口第一个地址的掩码*/
    netmask = ((struct sockaddr_in *)(d->addresses->netmask))->sin_addr.S_un.S_addr;
  else
    /* 如果接口没有地址，那么我们假设一个C类的掩码*/
    netmask = 0xffffff;

  //编译过滤器
  if (pcap_compile(adhandle, &fcode, packet_filter, 1, netmask) < 0)
  {
    fprintf(stderr, "nUnable to compile the packet filter. Check the syntax.\n");
    /* 释放设备列表*/
    pcap_freealldevs(alldevs);
    return -1;
  }

  //设置过滤器
  if (pcap_setfilter(adhandle, &fcode) < 0)
  {
    fprintf(stderr, "nError setting the filter.\n");
    /* 释放设备列表*/
    pcap_freealldevs(alldevs);
    return -1;
  }
  printf("nlistening on %s...\n", d->description);
  /* 释放设备列表*/
  pcap_freealldevs(alldevs);
  /* 开始捕捉*/
  pcap_loop(adhandle, 0, packet_handler, NULL);
  return 0;
}
/* 回调函数，当收到每一个数据包时会被libpcap所调用*/
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
  struct tm *ltime;
  char timestr[16];
  ip_header *ih;
  tcp_header *th;
  TLSPlaintext *tlsh;
  u_int ip_len;
  u_int size_tcp;
  u_short sport, dport;
  time_t local_tv_sec;
  /* 将时间戳转换成可识别的格式*/
  local_tv_sec = header->ts.tv_sec;
  ltime = localtime(&local_tv_sec);
  strftime(timestr, sizeof timestr, "%H:%M:%S", ltime);
  /* 获得IP数据包头部的位置*/
  ih = (ip_header *)(pkt_data + 14); //以太网头部长度
  switch (ih->proto)
  {
  case IPPROTO_TCP:
    printf(" Protocol: TCP\n");
    break;
  case IPPROTO_UDP:
    printf("Protocol: UDP\n");
    break;
  case IPPROTO_ICMP:
    printf(" Protocol: ICMP\n");
    break;
  case IPPROTO_IGMP:
    printf("Protocol:IGMP\n");
    break;
  default:
    printf(" Protocol: unknown\n");
    break;
  }

  /* 获得tcP首部的位置*/
  ip_len = (ih->ver_ihl & 0xf) * 4;
  //printf("%d\n",ip_len);
  th = (tcp_header *)((u_char *)ih + ip_len);
  /* 将网络字节序列转换成主机字节序列*/
  sport = ntohs(th->th_sport);
  dport = ntohs(th->th_dport);
  size_tcp = TH_OFF(th) * 4;
  tlsh = (TLSPlaintext *)((u_char *)th + size_tcp);
  switch (tlsh->ContentType)
  {
  case Change_Cipher_Spec:
    printf("%s.%.6d len:%d \n", timestr, header->ts.tv_usec, header->len);
    printf("%d.%d.%d.%d.%d -> %d.%d.%d.%d.%d\n",
           ih->saddr.byte1,
           ih->saddr.byte2,
           ih->saddr.byte3,
           ih->saddr.byte4,
           sport,
           ih->daddr.byte1,
           ih->daddr.byte2,
           ih->daddr.byte3,
           ih->daddr.byte4,
           dport);
    printf("USE TLS Encode\n");
    printf(" ContentType is: Change Cipher Spec\n");
    break;
  case Alert:
    printf("%s.%.6d len:%d \n", timestr, header->ts.tv_usec, header->len);
    printf("%d.%d.%d.%d.%d -> %d.%d.%d.%d.%d\n",
           ih->saddr.byte1,
           ih->saddr.byte2,
           ih->saddr.byte3,
           ih->saddr.byte4,
           sport,
           ih->daddr.byte1,
           ih->daddr.byte2,
           ih->daddr.byte3,
           ih->daddr.byte4,
           dport);
    printf("USE TLS Encode\n");
    printf("ContentType is: Alert\n");
    break;
  case Handshake:
    printf("%s.%.6d len:%d \n", timestr, header->ts.tv_usec, header->len);
    printf("%d.%d.%d.%d.%d -> %d.%d.%d.%d.%d\n",
           ih->saddr.byte1,
           ih->saddr.byte2,
           ih->saddr.byte3,
           ih->saddr.byte4,
           sport,
           ih->daddr.byte1,
           ih->daddr.byte2,
           ih->daddr.byte3,
           ih->daddr.byte4,
           dport);
    printf("USE TLS Encode\n");
    printf(" ContentType is: Handshake\n");
    break;
  case Application_Data:
    printf("%s.%.6d len:%d \n", timestr, header->ts.tv_usec, header->len);
    printf("%d.%d.%d.%d.%d -> %d.%d.%d.%d.%d\n",
           ih->saddr.byte1,
           ih->saddr.byte2,
           ih->saddr.byte3,
           ih->saddr.byte4,
           sport,
           ih->daddr.byte1,
           ih->daddr.byte2,
           ih->daddr.byte3,
           ih->daddr.byte4,
           dport);
    printf("USE TLS Encode\n");
    printf("ContentType is:Application Data\n");
    break;
  }
}
