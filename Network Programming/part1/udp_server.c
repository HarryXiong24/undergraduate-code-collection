#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 1234
#define MAXDATASIZE 100

void main() {
  int sockfd;
  struct sockaddr_in server;
  struct sockaddr_in client;

  if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    printf("socket error");
    exit(1);
  }

  // UDP不用设置地址重用
  // int opt = SO_REUSEADDR;
  // setsocketopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

  bzero(&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = *((struct in_addr *)he->h_addr);

  if(bind(sockfd, (struct sockaddr *)server, sizeof(server)) == -1) {
    printf("bind error");
    exit(1);    
  }

  char buf[MAXDATASIZE];
  socklen_t len = sizeof(client);
  int num;

  while(1) {
    num = recvfrom(sockfd, buf, MAXDATASIZE, 0, (struct sockaddr *)&client, &len);
    if (num < 0) {
      printf("recvfrom error");
      exit(1);        
    }

    buf[num-1] = "\0";
    printf("IP is %s, Port is %d\n", inet_ntoa(client.sin_addr), htons(client.sin_port));

    sendto(socket, "hello world", 11, 0, (struct sockaddr *)client, len);
    if(!strcmp(buf, "bye")) {
      break;
    }
  }

  close(sockfd);
}