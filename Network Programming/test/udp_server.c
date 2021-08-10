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

  }

  bzero(&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = htonl(INADDR_ANY);

  if(bind(listenfd, (struct sockaddr *)&server, sizeof(server)) == -1) {

  }

  socklen_t len = sizeof(client);
  int num;
  char buf[MAXDATASIZE];

  while(1) {
    if(num = recvfrom(listenfd, buf, MAXDATASIZE, 0, (struct sockaddr *)&client, &len) == -1) {

    }

    buf[num] = '\0';
    printf("%s, %d\n", inet_ntoa(client.sin_addr), ntohs(PORT));

    sendto(listenfd, buf, MAXDATASIZE, 0, (struct sockaddr *)&client, len);

    if(!strcmp(buf, "bye")) {
      break;
    }

  }
  close(sockfd);
}