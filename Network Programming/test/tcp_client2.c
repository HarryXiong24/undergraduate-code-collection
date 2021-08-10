#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 1234
#define MAXDATASIZE 100

void main(int argc, char *argv[]) {
  int listenfd, connectfd;
  struct sockaddr_in server;
  struct hostent *he;

  if(argc != 2) {
    printf("%s", argv[0]);
    exit(1);
  }

  if((he = gethostbyname(argv[1])) == NULL) {
    printf("");
    exit(1);
  }


  if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    printf("");
    exit(1);
  }

  bzero(&server, sizeof(server));
  server.sin_family = AF_INIT;
  server.sin_port = htons(PORT);
  server.sin_addr = *((struct in_addr *)he->h_addr);

  if(connect(listenfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
    printf("");
    exit(1);   
  }

  char buf[MAXDATASIZE];
  int num;

  while(1) {
    if((num = recv(listenfd, buf, MAXDATASIZE, 0)) == -1) {

    }

    buf[num] = '\0';

    printf("%s", buf);

    send()
  }

  close(fd);
}