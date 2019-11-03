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

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(6000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    connect(sockfd, (const struct sockaddr *) &server, sizeof(server));

    int a, b, res;
    printf("\nEnter two numbers : ");
    scanf("%d%d", &a, &b);
    
    send(sockfd, &a, sizeof(a), 0);
    send(sockfd, &b, sizeof(b), 0);
    recv(sockfd, &res, sizeof(res), 0);

    printf("\nSum = %d\n", res);


    return 0;
}