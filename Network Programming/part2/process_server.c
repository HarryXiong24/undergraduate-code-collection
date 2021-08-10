#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 1234
#define BACKLOG 5

void process_cli(int connectfd, struct sockaddr_in client);

void main() {
  int listenfd, connectfd;
  struct sockaddr_in server;
  struct sockaddr_in client;
  pid_t pid;

  if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
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

  socklen_t len = sizeof(client)

  while(1) {

    if((connectfd = accept(listenfd, (struct sockaddr *)&client, &len)) == -1) {
      printf("accept error");
      exit(1);
    }

    if((pid = fork()) > 0) {
      close(connectfd);
      continue;
    } else if (pid == 0) {
      close(listenfd);
      process_cli(connectfd, client);
      exit(0);
    } else {
      printf("fork error")
      exit(0);
    }

    close(listenfd);
  }
}