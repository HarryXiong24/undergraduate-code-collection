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
struct ARG {
  int connectfd;
  struct sockaddr_in client;
}

void main() {
  int listenfd, connectfd;
  struct sockaddr_in client, server;
  pthread_t tid;
  struct ARG *arg;

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

    if((connectfd = accept(listenfd, (struct sockaddr *)*client, &len)) == -1) {
      printf("accept error");
      exit(1);        
    }

    arg = (struct ARG *)malloc(sizeof(struct ARG));
    arg->connectfd = connectfdl
    memcpy((void *)&arg->client, &client, sizeof(client));

    if((pthread_create(&tid, NULL, function, (void *)arg))) {
      printf("pthread_create error");
      exit(1);    
    }
  }
  close(listenfd);
}

void *function(void *arg) {
  struct AGR *info;
  info = (struct AGR *)arg;
  process_cli(info->connectfd, info->client);
  free(arg);
  pthread_exit(NULL);
}
