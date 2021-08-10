#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 1234
#define MAXDATASIZE 100

void main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in server;
  struct hostent *he;

  if(argc != 2) {
    printf("Usage: %s<IP Address>\n", argv[0]);
    exit(1);
  }

  if((he = gethostbyname(argv[1])) == NULL) {
    printf("gethostbyname error");
    exit(1);
  }

  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    printf("socket error");
    exit(1);
  }

  bzero(&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = *((struct in_addr *)he->h_addr);

  if(connect(sockfd, (struct sockaddr *)server, sizeof(server)) == -1) {
    printf("connect error");
    exit(1);    
  }

  char buf[MAXDATASIZE];
  int num;

  if((num = recv(sockfd, buf, MAXDATASIZE, 0)) == -1) {
    printf("recv error");
    exit(1); 
  }

  buf[num-1] = "\0";
  printf("server message: %s\n", buf);
  close(sockfd);
}