#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 1240
#define MAXDATASIZE 100
void process(FILE *fp, int sockfd);
char *getMessage(char *sendline, int len, FILE *fp);

int main(int argc, char *argv[])
{
  int socketfd_xhw;
  struct hostent *he;
  struct sockaddr_in server;
  
  // TODO 如果没有输入IP地址，则报错
  if (argc != 2)
  {
    printf("Usage:%s <IP Address>\n", argv[0]);
    exit(1);
  } 
  // TODO 获取输入的IP地址
  if ((he = gethostbyname(argv[1])) == NULL)
  {
    printf("gethostbyname() error\n");
    exit(1);
  }
  /* 
    * int socket(int family, int type, int protocol)
    * family: 协议族
    * type: 产生套接字的类型
    * protocol: 协议标志，一般为0
    */
  // TODO 用于生成TCP套接字，生成失败则报错
  if ((socketfd_xhw = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {
    printf("socket() error\n");
    exit(1);
  } 

  // TODO 初始化
  bzero(&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr = *((struct in_addr *)he->h_addr);

  /* 
  * int connect(int sockfd, const strust sockaddr *addr, socklen_t addrlen)
  * sockfd: 套接字函数返回的套接字描述符
  * addr: 服务器指向的套接字地址结构指针
  * addrlen: 服务器指向的套接字地址结构的大小
  */
  // TODO 用于建立一个与TCP服务器的连接
  if (connect(socketfd_xhw, (struct sockaddr *)&server, sizeof(server)) == -1)
  {
    printf("connect() error\n");
    exit(1);
  }      
  // TODO 连接成功后，调用函数                
  process(stdin, socketfd_xhw); 
  // TODO 关闭套接字
  close(socketfd_xhw);          
}

// TODO 处理收发消息的函数
void process(FILE *fp, int socketfd_xhw)
{
  char sendline[MAXDATASIZE], recvline[MAXDATASIZE];
  int num;
  printf("Connected to server. \n");
  printf("Input client's name : ");
  if (fgets(sendline, MAXDATASIZE, fp) == NULL)
  {
    printf("\nExit.\n");
    return;
  }
  send(socketfd_xhw, sendline, strlen(sendline), 0);
  while (getMessage(sendline, MAXDATASIZE, fp) != NULL)
  {
    /* 
    * ssize_t send(int sockfd, const void *buf, size_t len, int flags)
    * sockfd: 已连接描述符
    * buf: 指向一个用于发送数据的数据缓存区
    * len: 发送数据的数据缓存区的大小
    * flags: 传输控制标志，0为常规操作，和write功能一致
    * return: 调用成功返回大于0的整数，也就是发送的字节数，出错返回-1，ssize_t就等于int类型
    */   
    // TODO 发送数据
    send(socketfd_xhw, sendline, strlen(sendline), 0);
    if (strcmp(sendline, "quit\n") == 0)
    {
      break;
    }
    /* 
    * ssize_t recv(int sockfd, char *buf, int len, int flags)
    * sockfd: 已连接描述符
    * buf: 指向一个用于接受信息的数据缓存区
    * len: 接受信息的数据缓存区的大小
    * flags: 传输控制标志，0为常规操作，和read功能一致
    * return: 调用成功返回大于0的整数，也就是接受的字节数，出错返回-1，ssize_t就等于int类型
    */   
    // TODO 接受数据   
    if ((num = recv(socketfd_xhw, recvline, MAXDATASIZE, 0)) == 0)
    {
      printf("Server terminated.\n");
      return;
    }
    recvline[num] = '\0';
    printf("Server Message: %s\n", recvline);
  }
  printf("\nExit.\n");
}

// TODO 提示并获得用户从终端输入的字符串
char *getMessage(char *sendline, int len, FILE *fp)
{
  printf("Input string to server:");
  return (fgets(sendline, MAXDATASIZE, fp));
} 