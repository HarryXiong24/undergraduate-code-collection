/*server.c*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 1234
#define BACKLOG 1

int main(void)
{
  int listenfd, connectfd;
  struct sockaddr_in server;
  struct sockaddr_in client;
  int sin_size;

  if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {
    perror("Create socket failed");
    exit(-1);
  }
  int opt = 1;
  setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
  bzero(&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(listenfd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1)
  {
    perror("Bind error");
    exit(-1);
  }

  if (listen(listenfd, BACKLOG) == -1)
  {
    perror("listen error");
    exit(-1);
  }
  sin_size = sizeof(struct sockaddr_in);
  while (1)
  {
    if ((connectfd = accept(listenfd, (struct sockaddr *)&client, &sin_size)) == -1)
    {
      perror("accept error");
      exit(-1);
    }
    printf("IP is %s, Port is %d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
    send(connectfd, "welcome to my server\n", 22, 0);
    close(connectfd);
  } /* while */
  close(listenfd);
}
