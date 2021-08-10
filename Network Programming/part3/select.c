#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <stdlib.h>


// 清空描述符集合
// 建立需要监视的描述符和描述符集合的练习
// 调用select函数
// 检查所有需要监视的描述符，利用FD_ISSET判断是否准备好
// 对已准备好的描述符进行I/O操作

#define PORT 1234
#define BACKLOG 5
#define MAXDATASIZE 1000

// TODO 用来存储客户信息的一个结构
typedef struct CLIENT
{
  int fd;
  char *name;
  struct sockaddr_in addr; /* client's address information */
  char *data;
};

// TODO 处理客户信息的一个结构
void process_cli(CLIENT *client, char *recvbuf, int len);

// TODO 处理存取的数据
void savedata(char *recvbuf, int len, char *data);

void main()
{
  int i, maxi, maxfd, sockfd;
  int nready;
  ssize_t n;
  fd_set rset, allset;
  int listenfd, connectfd;
  struct sockaddr_in server;

  CLIENT client[FD_SETSIZE];
  CHAR recvbuf[MAXDATASIZE];
  int sin_size;

  if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {
    perror("socket error");
    exit(1);
  }

  int opt = SO_REUSEADDR;
  setsocketopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

  bzero(&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(listenfd, (struct sockaddr *)&server, sizeof(server)) == -1)
  {
    perror("bind error");
    exit(1);
  }

  if (listen(listenfd, BACKLOG))
  {
    perror("listen error");
    exit(1);
  }

  sin_size = sizeof(struct sockaddr_in);

  // 当前只有一个 listenfd，没有客户的 connectfd，所以最大 fd 就是 listenfd
  maxfd = listenfd;
  // 当前没有客户，当前最大客户编号为-1（客户编号从 0 开始）
  maxi = -1;
  // FD_SETSIZE 表示一个进程中select所能操作文件描述符的最大数目
  for (i = 0; i < FD_SETSIZE; i++)
  {
    client[i].fd = -1; // 将每个客户的 fd 设置为-1，表示空位，
  }
  FD_ZERO(&allset); // 将所有 fd（包括 1 个 listenfd 和所有客户的 connectfd）置 0
  // 将fd字段为lieten的字段设置成1 
  FD_SET(listenfd, &allset); // 将 listenfd 置 1

  while (1)
  {
    struct sockaddr_in addr;
    rset = allset;

    if((nready = select(maxfd + 1, &rset, NULL, NULL, NULL)) == -1) {
      perror("select error");
      exit(1);
    }

    // TODO 监测listen套接字是否为1, 为1说明有新客户连接
    if (FD_ISSET(listenfd, &rset))
    {
      // 接受客户请求
      if ((connectfd = accept(listenfd, (struct sockaddr *)&addr, &sin_size)) == -1)
      {
        perror("accept error");
        exit(1);
      }
    }

    // 找到空位放客户的connectfd
    for (i = 0; i < FD_SETSIZE; i++) {
      if (client[i].fd < 0) {
        clinet[i].fd = connectfd;
        client[i].name = new char[MAXDATASIZE];
        client[i].addr = addr;
        client[i].data = new char[MAXDATASIZE];
        client[i].name[0] = '\0'; // 客户名字初始为空
        client[i].data[0] = '\0'; // 客户名字数据为空
        printf("You got a connect from %s.", inet_ntoa(client[i].addr.sin_addr));
        break;
      }
    }
    
    // 遍历到最后也没找到空位，说明客户太多，报错
    if (i == FD_SETSIZE) {
      printf("too many clients.\n");
    }
    
    // 将客户的 connectfd 加入 allset 中
    FD_SET(connectfd, &allset);

    // 调整个数
    if (connectfd > maxfd)
      maxfd = connectfd;
    if (i > maxi)
      maxi = i;
    // 如果 select 没有返回更多描述符，说明没有客户数据，直接进入下次循环
    if (--nready < = 0)
      continue;
  }

  // 循环检查所有已经加入的客户
  for (i = 0; i <= maxi; i++)
  {
    // 如果这个客户已经退出，不再检查其是否返回数据，直接检查下一个客户
    if ((sockfd = client[i].fd) < 0)
      continue;
    if (FD_ISSET(sockfd, &rset))
    {
      // 如果读到的客户消息长度为 0，关闭客户连接
      if ((n = recv(sockfd, recvbuf, MAXDATASIZE, 0)) == 0)
      {
        close(sockfd);
        printf("Client(%s) closed connection.User’s data: %s\n", client[i].name, client[i].data);
        FD_CLR(sockfd, &allset);
        client[i].fd = -1;
        delete client[i].name;
        delete client[i].data;
      }
      else // 如果读到的客户消息长度不为 0，处理客户消息
        process_cli(&client[i], recvbuf, n);
      if (--nready <= 0) // 如果 select 没有返回更多描述符，说明没有其他客户数据，不再检查下个客户，直接进入下一次调用 select
        break;
    } /* if (FD_ISSET(sockfd, &rset))  */
  }   /* for(i = 0; i <= maxi; i++)   */
  close(listenfd);
}

// 将收到的客户消息存储到客户数据 client->data 后面
void savedata(char* recvbuf, int len, char* data)
{
  int start = strlen(data);
  for (int i = 0; i < len; i++) {
    data[start + i] = recvbuf[i];
  }
}