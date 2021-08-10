#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <stdlib.h>

#define PORT 1240
#define BACKLOG 5
#define MAXDATASIZE 1000

typedef struct CLIENT
{
  int fd;
  char *name;
  struct sockaddr_in addr;
  char *data;
};

void process_cli(struct CLIENT *client, char *recvbuf, int len);
void savedata(char *recvbuf, int len, char *data);

main()
{
  int sockfd_xhw;
  ssize_t n;
  fd_set rset, allset;
  int listenfd_xhw, connectedfd_xhw;
  struct sockaddr_in server;
  struct CLIENT client[FD_SETSIZE];
  char recvbuf[MAXDATASIZE];
  int sin_size;
  int i;
  int maxNumber, maxfd;
  int myReady;

  /* Create TCP socket */
  /* 
    * int socket(int family, int type, int protocol)
    * family: 协议族
    * type: 产生套接字的类型
    * protocol: 协议标志，一般为0
    */
  // TODO 用于生成TCP套接字，生成失败则报错
  if ((listenfd_xhw = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {
    perror("Creating socket failed.");
    exit(1);
  } 

  /* set socket option */
  // TODO 允许地址重用
  int opt = SO_REUSEADDR;
  setsockopt(listenfd_xhw, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

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
  if (bind(listenfd_xhw, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1)
  {
    perror("Bind error.");
    exit(1);
  } 

  /* 
    * int listen(int sockfd, int backlog)
    * sockfd: 套接字函数返回的套接字描述符
    * backlog: g规定请求队列中最大连接的个数
    */
  // TODO 开始监听，指示内核应该接受发向套接字的请求
  if (listen(listenfd_xhw, BACKLOG) == -1)
  {
    perror("listen() error\n");
    exit(1);
  } 
  
  // TODO 监听网络连接
  sin_size = sizeof(struct sockaddr_in);
  maxfd = listenfd_xhw;
  maxNumber = -1;

  for (i = 0; i < FD_SETSIZE; i++)
  {
    client[i].fd = -1;
  }

  FD_ZERO(&allset);
  FD_SET(listenfd_xhw, &allset);

  while (1)
  {
    struct sockaddr_in addr;
    rset = allset;
    myReady = select(maxfd + 1, &rset, NULL, NULL, NULL);

    /* 
    * int accept(int listenfd, struct sockaddr *client, socklen_t *addrlen)
    * listenfd: 套接字函数返回的套接字描述符
    * client: 客户端的套接字地址结构
    * addrlen: 客户端的套接字地址结构对应的长度
    * return: connectfd, 已连接套接字
    */
    // TODO 使服务器接受客户端的连接请求
    if (FD_ISSET(listenfd_xhw, &rset))
    {
      if ((connectedfd_xhw = accept(listenfd_xhw, (struct sockaddr *)&addr, &sin_size)) == -1)
      {
        perror("accept() error\n");
        continue;
      }
      for (i = 0; i < FD_SETSIZE; i++)
        if (client[i].fd < 0)
        {
          client[i].fd = connectedfd_xhw;
          client[i].name = malloc(sizeof(char[MAXDATASIZE]));
          client[i].addr = addr;
          client[i].data = malloc(sizeof(char[MAXDATASIZE]));
          client[i].name[0] = '\0';
          client[i].data[0] = '\0';
          printf("You got a connection from %s.", inet_ntoa(client[i].addr.sin_addr));
          break;
        }
      if (i == FD_SETSIZE)
        printf("too many clients\n");
      FD_SET(connectedfd_xhw, &allset);
      if (connectedfd_xhw > maxfd)
        maxfd = connectedfd_xhw;
      if (i > maxNumber)
        maxNumber = i;
      if (--myReady <= 0)
        continue;
    }
    for (i = 0; i <= maxNumber; i++)
    {
      if ((sockfd_xhw = client[i].fd) < 0)
        continue;
      if (FD_ISSET(sockfd_xhw, &rset))
      {
        /* 
        * ssize_t recv(int sockfd, char *buf, int len, int flags)
        * sockfd: 已连接描述符
        * buf: 指向一个用于接受信息的数据缓存区
        * len: 接受信息的数据缓存区的大小
        * flags: 传输控制标志，0为常规操作，和read功能一致
        * return: 调用成功返回大于0的整数，也就是接受的字节数，出错返回-1，ssize_t就等于int类型
        */   
        // TODO 接受数据
        if ((n = recv(sockfd_xhw, recvbuf, MAXDATASIZE, 0)) == 0)
        {
          close(sockfd_xhw);
          printf("Client( %s ) closed connection. User's data: %s\n", client[i].name, client[i].data);
          FD_CLR(sockfd_xhw, &allset);
          client[i].fd = -1;
          free(client[i].name);
          free(client[i].data);
        }
        else 
        {
          process_cli(&client[i], recvbuf, n);
        }
        if (--myReady <= 0)
        {
          break;
        }
      }
    }
  }
  close(listenfd_xhw);
}

void process_cli(struct CLIENT *client, char *recvbuf, int len)
{
  char sendbuf[MAXDATASIZE];
  recvbuf[len - 1] = '\0';
  if (strlen(client->name) == 0)
  {
    memcpy(client->name, recvbuf, len);
    printf("Client's name is %s.\n", client->name); //接收客户的名字并显示
    return;
  }

  printf("Received client( %s ) message: %s\n", client->name, recvbuf);
  // TODO 调用线程安全函数
  savedata(recvbuf, len, client->data); 
  // TODO 加密准备
  int j = strlen(recvbuf) / 10 + 1;
  int l = (len - 1) % 10;
  int m;
  for (m = 0; l != 0 && m < 10 - l; m++)
  {
    recvbuf[len + m - 1] = '0';
  }
  int k = 0;
  int i;

  // TODO 加密
  while (j > 0)
  {
    for (i = k * 10; i < 10 * (k + 1); i++)
    {
      if (i == 0 + k * 10)
        sendbuf[i] = recvbuf[i] + 2;
      if (i == 1 + k * 10)
        sendbuf[i] = recvbuf[i] + 0;
      if (i == 2 + k * 10)
        sendbuf[i] = recvbuf[i] + 1;
      if (i == 3 + k * 10)
        sendbuf[i] = recvbuf[i] + 8;
      if (i == 4 + k * 10)
        sendbuf[i] = recvbuf[i] + 1;
      if (i == 5 + k * 10)
        sendbuf[i] = recvbuf[i] + 2;
      if (i == 6 + k * 10)
        sendbuf[i] = recvbuf[i] + 1;
      if (i == 7 + k * 10)
        sendbuf[i] = recvbuf[i] + 0;
      if (i == 8 + k * 10)
        sendbuf[i] = recvbuf[i] + 1;
      if (i == 9 + k * 10)
        sendbuf[i] = recvbuf[i] + 4;
    }
    k++;
    j--;
  }
  sendbuf[strlen(recvbuf)] = '\0';
  /* 
  * ssize_t send(int sockfd, const void *buf, size_t len, int flags)
  * sockfd: 已连接描述符
  * buf: 指向一个用于发送数据的数据缓存区
  * len: 发送数据的数据缓存区的大小
  * flags: 传输控制标志，0为常规操作，和write功能一致
  * return: 调用成功返回大于0的整数，也就是发送的字节数，出错返回-1，ssize_t就等于int类型
  */  
  // TODO 发送数据  
  send(client->fd, sendbuf, strlen(sendbuf), 0);
}

// TODO 线程安全函数
void savedata(char *recvbuf, int len, char *data) 
{
  int start = strlen(data);
  for (int i = 0; i < len; i++)
  {
    data[start + i] = recvbuf[i];
  }
}