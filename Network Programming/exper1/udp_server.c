#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 3333
#define MAXDATASIZE 100

char *reverse(char *str, int len);

int main()
{
    // 定义监听套接字和已连接套接字
    int sockfd;
    // 定义缓冲区
    char recvbuf[MAXDATASIZE];
    // 定义套接字地址存放变量 
    struct sockaddr_in server; 
    struct sockaddr_in client;
    // 定义客户端的套接字地址结构对应的长度
    socklen_t addrlen;

    /* 
     * int socket(int family, int type, int protocol)
     * family: 协议族
     * type: 产生套接字的类型
     * protocol: 协议标志，一般为0
     */
    // TODO 用于生成UDP套接字，生成失败则报错
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("Socket error!\n");
        exit(0);
    }

    // TODO 地址重用
    int opt = SO_REUSEADDR;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // TODO 初始化
    memset(&server, '\0', sizeof(server));
    server.sin_port = htons(PORT);
    // Hint server.sin_addr结构体中的s_addr才是存储地址内容的地方
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_family = AF_INET;

    /* 
     * int bind(int sockfd, const struct sockaddr *server, socklen_len addrlen)
     * sockfd: 套接字函数返回的套接字描述符
     * server: 特定协议的地址结构指针
     * addrlen: 指定了该套接字地址结构长度
     */
    // TODO 用于调用socket函数产生的套接字，分配一个本地协议地址，建立地址与套接字之间的关系
    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        perror("Bind error!\n");
        exit(0);
    }

    addrlen = sizeof(client);
    int num;

    while (1)
    {
        /* 
         * ssize_t recvform(int sockfd, void *buf, size_t len, int flags, struct sockaddr *from, size_t *addrlen)
         * sockfd: 监听套接字
         * buf: 指向一个用于接受信息的数据缓存区
         * len: 接受信息的数据缓存区的大小
         * from: 返回与之通信的对方的套接字地址结构
         * addrlen: 对方的套接字地址结构的字节数
         */
        // TODO 接受数据
        num = recvfrom(sockfd, recvbuf, MAXDATASIZE, 0, (struct sockaddr *)&client, &addrlen);

        if (!strcmp(recvbuf, "quit"))
        {
            break;
        }

        printf("You got a message from %s, port is %d.\n", inet_ntoa(client.sin_addr), htons(client.sin_port));
        recvbuf[num] = '\0';
        printf("Message:%s\n", recvbuf);
        reverse(recvbuf, num);

        /* 
         * ssize_t sendto(int sockfd, const void *buf, size_t len, int flags, struct sockaddr *to, int *addrlen)
         * sockfd: 监听套接字
         * buf: 指向一个用于发送信息的数据缓存区
         * len: 发送信息的数据缓存区的大小
         * from: 返回与之通信的对方的套接字地址结构
         * addrlen: 对方的套接字地址结构的字节数
         */
        // TODO 发送数据
        sendto(sockfd, recvbuf, num, 0, (struct sockaddr *)&client, len);
    }

    printf("Quit successfully!\n");
    close(sockfd);
    return 0;
}

// TODO 反转字符串
char *reverse(char *str, int len)
{
    char *start = str;
    char *end = str + len - 1;
    char ch;

    if (str != NULL)
    {
        while (start < end)
        {
            ch = *start;
            *start++ = *end;
            *end-- = ch;
        }
    }
    return str;
}