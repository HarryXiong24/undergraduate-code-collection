
#include <Winsock2.h>
#include "stdafx.h"
#include <string.h>
#define _W64
#define HAVE_REMOTE
#include "pcap.h"

typedef struct tcp_segment
{
  unsigned short src_port;
  unsigned short dst_port;
  unsigned int seq;
  unsigned int ack_seq;
  // unsigned short doff:4,hlen:4,fin:1,syn:1,rst:1,psh:1,ack:1,urg:1,ece:1,cwr:1;
  unsigned short headandother;
  unsigned short window;
  unsigned short check;
  unsigned short urg_ptr;
} tcp;

// TODO struct tcp_segment tcp;
struct ip_packt
{
  unsigned char verion_header_len;
  unsigned char ip_tos;    /* type of service */
  unsigned short ip_len;   /* total length */
  unsigned short ip_id;    /* identification */
  unsigned short ip_off;   /* fragment offset field */
  unsigned char ip_ttl;    /* time to live */
  unsigned char ip_p;      /* protocol */
  unsigned short ip_sum;   /* checksum */
  unsigned char ip_src[4]; /* source address */
  unsigned char ip_dst[4]; /* dest address */
};

struct eth_frame
{
  unsigned char dst_mac[6];
  unsigned char src_mac[6];
  unsigned char protol[2];
  // ip
  struct ip_packt ip;
};

/* packet handler 函数原型 */
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main()
{
  pcap_if_t *alldevs;
  pcap_if_t *d;
  int inum;
  int i = 0;
  pcap_t *adhandle;
  char errbuf[PCAP_ERRBUF_SIZE];

  // printf("\nsizeof ip_packet: %d, sizeof eth_frame: %d\n", sizeof(ip_packt), sizeof(eth_frame));

  /* 获取本机设备列表 */
  if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL, &alldevs, errbuf) == -1)
  {
    fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
    exit(1);
  }

  /* 打印列表 */
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
    printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
    return -1;
  }

  printf("Enter the interface number (1-%d):", i);
  scanf("%d", &inum);

  if (inum < 1 || inum > i)
  {
    printf("\nInterface number out of range.\n");
    /* 释放设备列表 */
    pcap_freealldevs(alldevs);
    return -1;
  }

  /* 跳转到选中的适配器 */
  for (d = alldevs, i = 0; i < inum - 1; d = d->next, i++)
    ;

  /* 打开设备 */
  if ((adhandle = pcap_open(d->name,                   // 设备名
                            65536,                     // 65535保证能捕获到不同数据链路层上的每个数据包的全部内容
                            PCAP_OPENFLAG_PROMISCUOUS, // 混杂模式
                            1000,                      // 读取超时时间
                            NULL,                      // 远程机器验证
                            errbuf                     // 错误缓冲池
                            )) == NULL)
  {
    fprintf(stderr, "\nUnable to open the adapter. %s is not supported by WinPcap\n", d->name);
    /* 释放设备列表 */
    pcap_freealldevs(alldevs);
    return -1;
  }

  printf("\nlistening on %s...\n", d->description);

  /* 释放设备列表 */
  pcap_freealldevs(alldevs);

  /* 开始捕获 */
  pcap_loop(adhandle, 0, packet_handler, NULL);

  return 0;
}

/* 每次捕获到数据包时，libpcap都会自动调用这个回调函数 */
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{

  eth_frame *my_eth = (eth_frame *)pkt_data;

  if (my_eth->protol[0] == 0x08 && my_eth->protol[1] == 0)
  {
    printf("\nDst MAC:");
    for (int i = 0; i < 6; i++)
    {
      printf("%02X ", ((eth_frame *)pkt_data)->dst_mac[i]);
    }
    printf("\nSrc MAC: ");
    for (i = 0; i < 6; i++)
    {
      printf("%02X ", ((eth_frame *)pkt_data)->src_mac[i]);
    }
    printf("\n Protocl: ");
    printf("%02X %02X\n", ((eth_frame *)pkt_data)->protol[0], ((eth_frame *)pkt_data)->protol[1]);

    printf("版本: %02X \nIP首部长度: %02d Byte\n", (((eth_frame *)pkt_data)->ip.verion_header_len & 0xf0) >> 4,
           (((eth_frame *)pkt_data)->ip.verion_header_len & 0x0f) * 4);

    unsigned short ip_len_to_be_swapped = ((eth_frame *)pkt_data)->ip.ip_len;
    unsigned short ip_id_to_be_swapped = ((eth_frame *)pkt_data)->ip.ip_id;
    unsigned short ip_off_to_be_swapped = ((eth_frame *)pkt_data)->ip.ip_off;
    unsigned short ip_off_swapped = (ip_off_to_be_swapped >> 8 | ip_off_to_be_swapped << 8) & 0xffff;
    unsigned short ip_sum_to_be_swapped = ((eth_frame *)pkt_data)->ip.ip_sum;

    printf("ip总长度: %d Byte\n", (ip_len_to_be_swapped >> 8 | ip_len_to_be_swapped << 8) & 0xffff);
    printf("id : %d\n", (ip_id_to_be_swapped >> 8 | ip_id_to_be_swapped << 8) & 0xffff);

    int MF, DF;
    if (ip_off_swapped & 0x4000)
    {
      DF = 1;
    }
    else
    {
      DF = 0;
    }

    if (ip_off_swapped & 0x2000)
    {
      MF = 1;
    }
    else
    {
      MF = 0;
    }

    unsigned short off = ip_off_swapped & 0x1fff;
    printf("DF = %d\n", DF);
    printf("MF = %d\n", MF);

    unsigned char p = (((eth_frame *)pkt_data)->ip).ip_p;
    if (p == 0x11)
    {
      printf("UDP");
    }
    if (p == 0x06)
    {
      printf("\nTCP\n");
      tcp *ptcp = (tcp *)(&((((eth_frame *)pkt_data)->ip).ip_dst) + 1);
      unsigned short tcp_srcport_to_be_swapped = ptcp->src_port;
      unsigned short tcp_dstport_to_be_swapped = ptcp->dst_port;

      printf("src端口：%d\n", (tcp_srcport_to_be_swapped >> 8 | tcp_srcport_to_be_swapped << 8) & 0xffff);
      printf("dst端口：%d\n", (tcp_dstport_to_be_swapped >> 8 | tcp_dstport_to_be_swapped << 8) & 0xffff);

      //首部长度
      unsigned short headandother_swapped;
      headandother_swapped = ntohs(ptcp->headandother);
      printf("首部长度：%d\n", ((headandother_swapped >> 12) & 0x000f) * 4);

      //urgent
      if ((headandother_swapped >> 5) & 0x0001 == 0x0001)
      {
        printf("Urgent: 1\n");
      }
      else
      {
        printf("Urgent: 0\n");
      }

      //ACK
      if ((headandother_swapped >> 4) & 0x0001 == 0x0001)
      {
        printf("ACK: 1\n");
      }
      else
      {
        printf("ACK: 0\n");
      }

      //Push
      if ((headandother_swapped >> 3) & 0x0001 == 0x0001)
      {
        printf("Push: 1\n");
      }
      else
      {
        printf("Push: 0\n");
      }

      //Reset
      if ((headandother_swapped >> 2) & 0x0001 == 0x0001)
      {
        printf("Reset: 1\n");
      }
      else
      {
        printf("Reset: 0\n");
      }

      //SYN
      if ((headandother_swapped >> 1) & 0x0001 == 0x0001)
      {
        printf("SYN: 1\n");
      }
      else
      {
        printf("SYN: 0\n");
      }

      //Fin
      if (headandother_swapped & 0x0001 == 0x0001)
      {
        printf("SYN: 1\n");
      }
      else
      {
        printf("SYN: 0\n");
      }

      //window
      printf("窗口: %u\n", ntohs(ptcp->window));

      //checksum
      printf("TCP校验和：%04X\n", ntohs(ptcp->check));

      //紧急指针
      printf("紧急指针：%u\n", ntohs(ptcp->urg_ptr));
    }

    printf("源地址：");
    for (i = 0; i < 3; i++)
    {
      printf("%d.", (((eth_frame *)pkt_data)->ip).ip_src[i]);
    }
    printf("%d", (((eth_frame *)pkt_data)->ip).ip_src[3]);

    printf("\n目的地址：");
    for (i = 0; i < 3; i++)
    {
      printf("%d.", (((eth_frame *)pkt_data)->ip).ip_dst[i]);
    }
    printf("%d", (((eth_frame *)pkt_data)->ip).ip_dst[3]);
  }
}
