#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 1234
#define BACKLOG 5
#define MAXDATASIZE 1000

void process_cli(int connectfd, struct sockaddr_in client);
void *function(void *arg);
struct ARG
{
  /* data */
  int connectfd;
  struct sockaddr_in client
};

// TODO [客户处理函数/循环]调用线程安全函数savedata_r(), 将刚刚接收的客户端数据保存到客户缓冲区cli_data中
void savaedata_r(char *recvbuf, int len, char *cli_data);

// TODO 定义TSD关键字变量
pthread_key_t key;
// TODO 定义变量once
pthread_once_t once = PTHREAD_ONCE_INIT;
// TODO 定义析构函数
static void destructor(void *ptr) {
  free(ptr)
}
// TODO 定义函数creatkey_once
static void creatkey_once(void) {
  pthread_key_create(&key, destructor);
}
// TODO 用于存储TSD
struct ST_DATA {
  int index;
}

void main() {
  int listenfd, connectfd;
  struct sockaddr_in server;
  struct sockaddr_in client;
  struct ARG *arg;
  pthread_t tid;

  if((listenfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    printf("socket error");
    exit(1);
  }

  int opt = SO_REUSEADDR;
  setsocketopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

  bzero(&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = htonl(INADDR_ANY);

  if(bind(listenfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
    printf("bind error");
    exit(1);    
  }

  if(listen(listenfd, BACKLOG) == -1) {
    printf("listen error");
    exit(1);    
  }

  socklen_t len = sizeof(client);

  while(1) {

    if((connectfd = accept(listenfd, (struct sockaddr *)&client, sizeof(client))) == -1) {
      printf("accept error");
      exit(1);    
    }

    arg = (struct AGR *)malloc(sizeof(struct AGR));
    arg->connectd = connectfd;
    memcpy((void *)&arg->client, &client, sizeof(client));

    if(pthread_create(&tid, NULL, function, (void *)arg)) {
      printf("pthread_create error");
      exit(1);    
    }
  }
  close(listenfd);
}

void *function(void *arg) {
  struct ARG *info;
  info = (struct ARG *)arg;
  process_cli(info->connectfd, info->client);
  free(arg);
  pthread_exit(NULL);
}

void savaedata_r(char *recvbuf, int len, char *cli_data) {
  struct ST_DATA *data;
  // TODO 产生TSD关键字，只在第一个新线程中执行
  pthread_once(&once, creatkey_once);
  // TODO 如果没有分配空间给TSD， 则分配空间并与TSD关键字绑定
  if ((data = (struct ST_DATA *)pthread_getspecific(key)) == NULL) {
    data = (struct ST_DATA *)malloc(sizeof(struct ST_DATA));
    pthread_setspecific(key, data);
    data->index = 0;
  }
  int i = 0;
  while(i < len-1) {
    cli_data[data->index++] = recvbuf[i];
    i++;
  }
  cli_data[data->index] = '\0';
}