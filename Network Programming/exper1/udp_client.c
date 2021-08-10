#include <stdio.h>
#include <netdb.h> //hostent结构体所在头文件
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h> //地址结构体所在头文件
#include <unistd.h>

#define PORT 3333
#define MAXDATASIZE 100

void main(int argc, char *argv[])
{
    // 监听套接字
    int sockfd;
    // 定义缓冲区
    char recvbuf[MAXDATASIZE];
    // 存放远程host信息的结构体
    struct hostent *he;
    // 定义套接字地址存放变量 
    struct sockaddr_in server;
    struct sockaddr_in peer;
    socklen_t len;

    // TODO 如果没有输入IP地址，则报错
    if (argc != 2)
    {
        printf("Usage:%s <IP Address>\n", argv[0]);
        exit(0);
    }

    // TODO 获取输入的IP地址
    if ((he = gethostbyname(argv[1])) == NULL)
    {
        perror("Gethostbyname error!\n");
        exit(0);
    }

    /* 
     * int socket(int family, int type, int protocol)
     * family: 协议族
     * type: 产生套接字的类型
     * protocol: 协议标志，一般为0
     */
    // TODO 用于生成TCP套接字，生成失败则报错
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("Socket error!\n");
        exit(0);
    }

    // TODO 初始化
    memset(&server, '\0', sizeof(server));
    server.sin_port = htons(PORT);
    server.sin_addr = *((struct in_addr *)he->h_addr);
    server.sin_family = AF_INET;

    // TODO 初始化长度
    len = sizeof(peer);
    int num;

    while (1)
    {
        memset(recvbuf, '\0', MAXDATASIZE);
        printf("Please enter your message:");
        scanf("%s", recvbuf);

        /* 
         * ssize_t sendto(int sockfd, const void *buf, size_t len, int flags, struct sockaddr *to, int *addrlen)
         * sockfd: 监听套接字
         * buf: 指向一个用于发送信息的数据缓存区
         * len: 发送信息的数据缓存区的大小
         * from: 返回与之通信的对方的套接字地址结构
         * addrlen: 对方的套接字地址结构的字节数
         */
        // TODO 发送数据
        if (sendto(sockfd, recvbuf, strlen(recvbuf), 0, (struct sockaddr *)&server, sizeof(server)) == -1)
        {
            perror("Sendto error!\n");
            exit(0);
        }

        if (!strcmp(recvbuf, "quit"))
        {
            break;
        }

        /* 
         * ssize_t recvform(int sockfd, void *buf, size_t len, int flags, struct sockaddr *from, size_t *addrlen)
         * sockfd: 监听套接字
         * buf: 指向一个用于接受信息的数据缓存区
         * len: 接受信息的数据缓存区的大小
         * from: 返回与之通信的对方的套接字地址结构
         * addrlen: 对方的套接字地址结构的字节数
         */
        // TODO 接受数据
        if ((num = recvfrom(sockfd, recvbuf, MAXDATASIZE, 0, (struct sockaddr *)&peer, &len)) == -1)
        {
            perror("Recvfrom error!\n");
            exit(0);
        }

        printf("Reversed message is :%s\n", recvbuf);

    } 

    printf("Quit successfully!\n");
    close(sockfd);
}