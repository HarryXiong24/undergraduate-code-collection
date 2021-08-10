#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 1235
#define BACKLOG 1
#define MAXDATASIZE 100

char *reverse(char *str, int len);

void main()
{

    // 定义监听套接字和已连接套接字
    int listenfd, connectfd;
    // 定义套接字地址存放变量 
    struct sockaddr_in server; /* server's address information */
    struct sockaddr_in client; /* client's address information */
    // 定义客户端的套接字地址结构对应的长度
    socklen_t addrlen;

    /* Create TCP socket */
    /* 
     * int socket(int family, int type, int protocol)
     * family: 协议族
     * type: 产生套接字的类型
     * protocol: 协议标志，一般为0
     */
    // TODO 用于生成TCP套接字，生成失败则报错
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        /* handle exception */
        perror("socket() error.");
        exit(1);
    }

    /* set socket option */
    // TODO 允许地址重用
    int opt = SO_REUSEADDR;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // TODO 先将server置0
    bzero(&server, sizeof(server));

    // TODO 初始化server
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    /* 
     * int bind(int sockfd, const struct sockaddr *server, socklen_len addrlen)
     * sockfd: 套接字函数返回的套接字描述符
     * server: 特定协议的地址结构指针
     * addrlen: 指定了该套接字地址结构长度
     */
    // TODO 用于调用socket函数产生的套接字，分配一个本地协议地址，建立地址与套接字之间的关系
    if (bind(listenfd, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        /* handle exception */
        perror("Bind() error");
        exit(1);
    }
    
    /* 
     * int listen(int sockfd, int backlog)
     * sockfd: 套接字函数返回的套接字描述符
     * backlog: g规定请求队列中最大连接的个数
     */
    // TODO 开始监听，指示内核应该接受发向套接字的请求
    if (listen(listenfd, BACKLOG) == -1)
    {
        perror("listen() error.\n");
        exit(1);
    }

    addrlen = sizeof(client);
    
    /* 
     * int accept(int listenfd, struct sockaddr *client, socklen_t *addrlen)
     * listenfd: 套接字函数返回的套接字描述符
     * client: 客户端的套接字地址结构
     * addrlen: 客户端的套接字地址结构对应的长度
     * return: connectfd, 已连接套接字
     */
    // TODO 使服务器接受客户端的连接请求
    if ((connectfd = accept(listenfd, (struct sockaddr *)&client, &addrlen)) == -1)
    {
        perror("accept() error\n");
        exit(1);
    }

    char buf[MAXDATASIZE];
    int num;
    while (1)
    {
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
        num = recv(connectfd, buf, MAXDATASIZE, 0);

        if (!strcmp(buf, "quit"))
        {
            break;
        }
        
        // 需要对输出数据进行格式转化
        printf("You got a message from %s, port is %d.\n", inet_ntoa(client.sin_addr), htons(client.sin_port));
        buf[num] = '\0';
        printf("Message: %s\n", buf);
        reverse(buf, num);

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
        send(connectfd, buf, num, 0);
    } 

    printf("Quit successfully!\n");

    // TODO 使用玩后要记得关闭
    close(connectfd);
    close(listenfd);   /* close listenfd */
}

// TODO 反转字符串
char *reverse(char *str, int len)
{
    //自定义的字符串反转函数
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