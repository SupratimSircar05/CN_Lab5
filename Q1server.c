#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(){
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd != -1)
        printf("\nSocket creation is success\n");
    else
        printf("\nSocket Error\n");

    struct sockaddr_in server, client;
    server.sin_family = AF_INET;
    server.sin_port = htons(6000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(sockfd, (struct sockaddr *) &server, sizeof(server));
    listen(sockfd, 5);
    int l = sizeof(client);

    int fd1 = accept(sockfd, (struct sockaddr *) &client, &l);

    int a, b, res;
    recv(fd1, &a, sizeof(a), 0);
    recv(fd1, &b, sizeof(b), 0);
    res = a + b;
    send(fd1, &res, sizeof(res), 0);

    return 0;
}