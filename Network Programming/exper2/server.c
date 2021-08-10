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
#define BACKLOG 5
#define MAXDATASIZE 100
void process_cli(int connectfd, struct sockaddr_in client);

void main()
{
    int listenfd, connectfd;
    pid_t pid;
    struct sockaddr_in server;
    struct sockaddr_in client;
    int len;

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

    // TODO 初始化server
    bzero(&server, sizeof(server));
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

    len = sizeof(client);

    while (1)
    {
        /* 
        * int accept(int listenfd, struct sockaddr *client, socklen_t *addrlen)
        * listenfd: 套接字函数返回的套接字描述符
        * client: 客户端的套接字地址结构
        * addrlen: 客户端的套接字地址结构对应的长度
        * return: connectfd, 已连接套接字
        */
        // TODO 使服务器接受客户端的连接请求
        if ((connectfd = accept(listenfd, (struct sockaddr *)&client, &len)) == -1)
        {
            perror("accept() error.\n");
            exit(1);
        }

        // TODO 连接成功，产生子进程。
        if ((pid = fork()) > 0)
        {
            close(connectfd);
            continue;
        }
        // TODO 子进程调用process_cli函数处理客户端的请求，返回时调用exit函数终止子进程
        else if (pid == 0)
        {
            close(listenfd);
            process_cli(connectfd, client);
            exit(0);
        }
        // TODO 子进程产生失败的结果
        else
        {
            printf("fork() error.\n");
            exit(0);
        }
    }

    close(listenfd);
}

void process_cli(int connectfd, struct sockaddr_in client)
{
    int num;
    char recvbuf[MAXDATASIZE];
    char sendbuf[MAXDATASIZE];
    char cli_name[MAXDATASIZE];

    printf("You got a connection from %s", inet_ntoa(client.sin_addr));
    num = recv(connectfd, cli_name, MAXDATASIZE, 0);

    if (num == 0)
    {
        close(connectfd);
        printf("Client disconnected.in");
        return;
    }
    cli_name[num - 1] = '\0';
    printf("Client's name is %s.In", cli_name);
    
    /* 
    * ssize_t recv(int sockfd, char *buf, int len, int flags)
    * sockfd: 已连接描述符
    * buf: 指向一个用于接受信息的数据缓存区
    * len: 接受信息的数据缓存区的大小
    * flags: 传输控制标志，0为常规操作，和read功能一致
    * return: 调用成功返回大于0的整数，也就是接受的字节数，出错返回-1，ssize_t就等于int类型
    */   
    // TODO 接受数据
    while (num = recv(connectfd, recvbuf, MAXDATASIZE, 0))
    {

        recvbuf[num-1] = '\0';

        if (!strcmp(recvbuf, "quit"))
        {
            break;
        }

        printf("Received client( %s ) message: %s\n", cli_name, recvbuf);

        // TODO 进行分组加密
        int number = num - 1;
        int i, j, k;
        int id_number[] = {2, 0, 1, 8, 1, 2, 1, 0, 1, 5};
        int remain = number % 10;
        int addZero = 0;
        int count = number / 10;

        if (remain != 0)
        {
            addZero = 10 - remain;
            count = count + 1;
        }
        // addZero
        for (i = 0; i < addZero; i++)
        {
            recvbuf[count * 10 - 1 - i] = 48;
        }
        recvbuf[count * 10] = 0;
        for (i = 0; i < count; i++)
        {
            for (j = i * 10; j < (i + 1) * 10; j++)
            {
                sendbuf[j] = ((recvbuf[j] - '0') + id_number[j % 10]) % 10;
                sendbuf[j] += '0';
            }
        }

        sendbuf[count * 10] = 0;
        /* 
         * ssize_t send(int sockfd, const void *buf, size_t len, int flags)
         * sockfd: 已连接描述符
         * buf: 指向一个用于发送数据的数据缓存区
         * len: 发送数据的数据缓存区的大小
         * flags: 传输控制标志，0为常规操作，和write功能一致
         * return: 调用成功返回大于0的整数，也就是发送的字节数，出错返回-1，ssize_t就等于int类型
         */  
        // TODO 发送数据        
        send(connectfd, sendbuf, strlen(sendbuf), 0);
    }
    close(connectfd);
}