// client2 sends 1 no. to server to swap
#include <stdio.h>
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

    int b;
    printf("\nEnter a number : ");
    scanf("%d", &b);
    
    send(sockfd, &b, sizeof(b), 0);
    recv(sockfd, &b, sizeof(b), 0);
    printf("\nb = %d\n", b);


    return 0;
}