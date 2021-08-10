// wpcap_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//#include <stdlib.h>
//#include <stdio.h>

#define _W64
#include <pcap.h>

void main(int argc, char **argv)
{
  pcap_t *fp;
  char errbuf[PCAP_ERRBUF_SIZE];
  u_char packet[100];
  FILE *fg;
  int i;
  int count = 0;
  int flag = 0;
  char continueOrNot;
  char filename[30];
  char filePath[34] = "D://";

  /* 检查命令行参数的合法性 */
  if (argc != 2)
  {
    printf("usage: %s interface (e.g., rpcap://DEVICENAME. DEVICENAME can be obtained through pcap_findalldevs_ex())\n",
           argv[0]);
    return;
  }

  printf("please input the MAC address of the target host to which you want to send your message: \n");
  for (i = 0; i < 6; i++)
  {
    scanf("%x", &packet[i]);
  }
  printf("The MAC address you've enetered is: \n");
  for (i = 0; i < 6; i++)
  {
    printf("%x ", packet[i]);
  }
  printf("\n");

  /* 打开输出设备 */
  if ((fp = pcap_open(argv[1], // 设备名
                      100,     // 要捕获的部分 (只捕获前100个字节)
                      0,       // 不是混杂模式
                      1000,    // 读超时时间, read timeout in milliseconds.
                      NULL,    // 远程机器验证
                      errbuf   // 错误缓冲
                      )) == NULL)
  {
    fprintf(stderr, "\nUnable to open the adapter. %s is not supported by WinPcap\n", argv[1]);
    return;
  }

  /* 设置MAC源地址为 2:2:2:2:2:2 */
  // 54-E1-AD-D7-E4-CA
  // rpcap://\Device\NPF_{5866A9D4-EFB2-4619-BCA0-7082048D3AB2}
  packet[6] = 2;
  packet[7] = 2;
  packet[8] = 2;
  packet[9] = 2;
  packet[10] = 2;
  packet[11] = 2;

  /* protocol type part */
  packet[12] = 0x11;
  packet[13] = 0x12;

  /* 填充剩下的内容 */
  for (i = 14; i < 100; i++)
  {
    packet[i] = 0;
  }
  for (i = 4; i < 34; i++)
  {
    filePath[i] = 0;
  }
  for (i = 0; i < 30; i++)
  {
    filename[i] = 0;
  }
  while (1)
  {
    printf("please input the file name that you want to send to the target host: \n");
    scanf("%s", &filename);
    for (i = 0; i < 30; i++)
    {
      if (filename[i] == 0 && count == 0)
      {
        flag = i;
        count = 1;
      }
    }
    for (i = 4; i < flag + 4; i++)
    {
      filePath[i] = filename[i - 4];
    }
    for (i = 0; i < flag + 4; i++)
    {
      printf("%c", filePath[i]);
    }
    fg = fopen(filePath, "r");
    i = 14;
    while (!feof(fg))
    {
      fscanf(fg, "%c", &packet[i]);
      i++;
    }
    /* 发送数据包 */
    if (pcap_sendpacket(fp, packet, 100 /* size */) != 0)
    {
      fprintf(stderr, "\nError sending the packet: \n", pcap_geterr(fp));
      return;
    }

    scanf("%c", &continueOrNot);
    printf("Continue to send next message?(Y or N)\n");
    scanf("%c", &continueOrNot);
    if (continueOrNot == 'N' || continueOrNot == 'n')
    {
      break;
    }
  }

  return;
}