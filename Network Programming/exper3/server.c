#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#define PORT 1235
#define BACKLOG 5
#define MAXDATASIZE 1000

void process_cli(int connfd, struct sockaddr_in client);
void *function(void *arg);

struct ARG
{
  int connfd;
  struct sockaddr_in client;
};

void main()
{
  int listenfd, connfd;
  pthread_t tid;
  struct ARG *arg;
  struct sockaddr_in server;
  struct sockaddr_in client;
  socklen_t len;
  if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {
    perror("Creating socket failed.");
    exit(1);
  }
  int opt = SO_REUSEADDR;
  setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
  bzero(&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(listenfd, (struct sockaddr *)&server, sizeof(server)) == -1)
  {
    perror("Bind() error.");
    exit(1);
  }
  if (listen(listenfd, BACKLOG) == -1)
  {
    perror("listen() error\n");
    exit(1);
  }
  len = sizeof(client);
  while (1)
  {
    if ((connfd = accept(listenfd, (struct sockaddr *)&client, &len)) == -1)
    {
      perror("accept() error\n");
      exit(1);
    }
    arg = (struct ARG *)malloc(sizeof(struct ARG));
    arg->connfd = connfd;
    memcpy((void *)&arg->client, &client, sizeof(client));
    if (pthread_create(&tid, NULL, function, (void *)arg))
    {
      perror("Pthread_create() error");
      exit(1);
    }
  }
  close(listenfd);
}

void process_cli(int connfd, struct sockaddr_in client)
{
  int num;
  char recvbuf[MAXDATASIZE], sendbuf[MAXDATASIZE], cli_name[MAXDATASIZE];
  printf("You got a connection from %s.\n", inet_ntoa(client.sin_addr));
  num = recv(connfd, cli_name, MAXDATASIZE, 0);
  if (num == 0)
  {
    close(connfd);
    printf("Client disconnected.\n");
    return;
  }

  cli_name[num - 1] = '\0';
  printf("Client's name is %s.\n", cli_name);
  // TODO 接受数据
  while (num = recv(connectfd, recvbuf, MAXDATASIZE, 0))
  {

    recvbuf[num - 1] = '\0';

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
  close(connfd);
}
void *function(void *arg)
{
  struct ARG *info;
  info = (struct ARG *)arg;
  process_cli(info->connfd, info->client);
  free(arg);
  pthread_exit(NULL);
}
