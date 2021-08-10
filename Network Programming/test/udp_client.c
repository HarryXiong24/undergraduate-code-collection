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
  int socketfd;
  struct sockaddr_in server;
  struct hostent *he;

  if(argc != 2) {
    printf("%s", argv[0])
  }

  if((he = gethostbyname(argv[1])) == NULL) {

  }

  if((socketfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {

  }

  bzero(&server. sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr = *((struct in_addr *)he->h_addr);

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

}
