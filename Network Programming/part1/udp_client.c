#include <stdio.h>
#include <netdb.h> 
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h> 
#include <unistd.h>

#define PORT 1234
#define MAXDATASIZE 100

void main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in server;
  struct sockaddr_in peer;
  struct hostent *he;

  if(argc != 3) {
    printf("Usage: %s<IP Address> <Message>\n", argv[0]);
    exit(1);
  }

  if((he = gethostbyname(argv[1])) == NULL) {
    printf("gethostbyname error");
    exit(1);    
  }

  if((sockfd = socket(AF_INET, SOCK_DGRAM, O)) == -1) {
    printf("socket error");
    exit(1);      
  }

  bzero(&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = *((struct in_addr *)he->h_addr);

  sendto(sockfd, argv[2], strlen(argv[2]), 0, (struct sockaddr *)&server, strlen(server));

  socklen_t len = sizeof(peer);
  char buf[MAXDATASIZE];
  int num;

  while(1) {
    if((num = recvfrom(sockfd, buf, MAXDATASIZE, 0, (struct sockaddr *)&peer, &len)) == -1) {
      printf("recvfrom error");
      exit(1);   
    }

    if(len != sizeof(server) || memcmp((const *void)&server, (const void *)&peer, len) != 0) {
      continue;
    }

    bum[num] = '\0';
    printf("Sever Message: %s\n", buf);
    break;
  }

  close(sockfd);
}