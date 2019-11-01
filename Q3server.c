#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<stdlib.h>
#include <arpa/inet.h>

typedef struct Student{
    int roll;
    // char name[50];
    int marks[5];
} Student;

int main(){

    //storing one record in server
    Student S;
    printf("\nEnter roll to store : ");
    scanf("%d", &S.roll);
    // printf("\nEnter name : ");
    // fgets(S.name, 50, stdin);
    printf("\nEnter 5 marks : \n");
    for(int i = 0; i < 5; i++){
        scanf("%d", &S.marks[i]);
    }

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

    int roll_search, response;
    recv(fd1, &roll_search, sizeof(roll_search), 0);
    if(roll_search == S.roll)
    {
        response = 1;
        send(fd1, &response, sizeof(response), 0);
    }
    else
        response = 0;
    
    if(response == 1)
        send(fd1, &S, sizeof(S), 0);
    else
        exit(0);

    return 0;
}