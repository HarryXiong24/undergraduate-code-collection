bzero(&server, sizeof(server));
bcopy(&src, &dst, sizeof(server));
bcmp(&src, &dst, sizeof(server));

memset(&server, 0, sizeof(server));
memcpy(&dst, &src, sizeof(server));
memcmp(&dst, &src, sizeof(server));

in_addr inet_addr("192.168.0.1");
int inet_aton("192.168.0.1", &(server.sin_addr));
char *inet_ntoa(client.sin_addr);

int inet_pton(AF_INET, "192.168.0.1", &(server.sin_addr));
const char *inet_ntop(AF_INET, &(client.sin_addr), result_str, sizeof(str));

