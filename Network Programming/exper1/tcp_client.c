#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> /* netbd.h is needed for struct hostent */

#define PORT 1235 /* Server Port */
#define MAXDATASIZE 100

void main(int argc, char *argv[])
{
    // 监听套接字
    int sockfd;            /* files descriptors */
    // 定义缓冲区
    char buf[MAXDATASIZE]; /* buf will store received text */
    // 存放远程host信息的结构体
    struct hostent *he;    /* structure that will get information about remote host */
    // 定义套接字地址存放变量 
    struct sockaddr_in server;

    // TODO 如果没有输入IP地址，则报错
    if (argc != 2)
    {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }

    // TODO 获取输入的IP地址
    if ((he = gethostbyname(argv[1])) == NULL)
    {
        printf("gethostbyname() error\n");
        exit(1);
    }

    /* 
     * int socket(int family, int type, int protocol)
     * family: 协议族
     * type: 产生套接字的类型
     * protocol: 协议标志，一般为0
     */
    // TODO 用于生成TCP套接字，生成失败则报错
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("socket() error\n");
        exit(1);
    }

    // TODO 初始化
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr = *((struct in_addr *)he->h_addr);

    /* 
     * int connect(int sockfd, const strust sockaddr *addr, socklen_t addrlen)
     * sockfd: 套接字函数返回的套接字描述符
     * addr: 服务器指向的套接字地址结构指针
     * addrlen: 服务器指向的套接字地址结构的大小
     */
    // TODO 用于建立一个与TCP服务器的连接
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        printf("connect() error\n");
        exit(1);
    }

    int num;    // 用来存放接受数据的长度

    while (1)
    {
        memset(buf, '\0', MAXDATASIZE);
        printf("Please enter your message:");
        scanf("%s", buf);

        /* 
         * int write(int sockfd, const void *buf, int len)
         * sockfd: 已连接描述符
         * buf: 指向一个用于发送数据的数据缓存区
         * len: 发送数据的数据缓存区的大小
         * return: 调用成功返回大于0的整数，也就是发送的字节数，出错返回-1
         */   
        /* 
         * ssize_t send(int sockfd, const void *buf, size_t len, int flags)
         * sockfd: 已连接描述符
         * buf: 指向一个用于发送数据的数据缓存区
         * len: 发送数据的数据缓存区的大小
         * flags: 传输控制标志，0为常规操作，和write功能一致
         * return: 调用成功返回大于0的整数，也就是发送的字节数，出错返回-1，ssize_t就等于int类型
         */   
        // TODO 发送数据
        if (send(sockfd, buf, strlen(buf), 0) == -1)
        {
            perror("Send error!\n");
            exit(0);
        }

        if (!strcmp(buf, "quit"))
        {
            break;
        }

        /* 
         * int read(int sockfd, char *buf, int len)
         * sockfd: 已连接描述符
         * buf: 指向一个用于接受信息的数据缓存区
         * len: 接受信息的数据缓存区的大小
         * return: 调用成功返回大于0的整数，也就是接受的字节数，出错返回-1
         */   
        /* 
         * ssize_t recv(int sockfd, char *buf, int len, int flags)
         * sockfd: 已连接描述符
         * buf: 指向一个用于接受信息的数据缓存区
         * len: 接受信息的数据缓存区的大小
         * flags: 传输控制标志，0为常规操作，和read功能一致
         * return: 调用成功返回大于0的整数，也就是接受的字节数，出错返回-1，ssize_t就等于int类型
         */   
        // TODO 接受数据
        if ((num = recv(sockfd, buf, MAXDATASIZE, 0) == -1))
        {
            perror("Recv error!\n");
            exit(0);
        }

        printf("Reversed message is: %s\n", buf);

    }

    printf("Quit successfully!\n");
    close(sockfd);
}