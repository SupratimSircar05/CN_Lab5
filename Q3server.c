// server stores multiple records and returns record if match is found
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>

typedef struct Student{
    int roll;
    char name[50];
    int marks[5];
} Student;

int main(){

    int count;
    printf("\nEnter no. of records of students to store in server : ");
    scanf("%d", &count);
    //storing 'count' no. of records in server
    Student S[count];
    for(int i = 0; i < count; i++){
        printf("\n%d)", i + 1);
        printf("\nEnter roll to store : ");
        scanf("%d", &S[i].roll);
        printf("\nEnter name : ");
        scanf("%s[^ \n]", S[i].name);
        printf("\nEnter 5 marks : \n");
        for(int j = 0; j < 5; j++)
            scanf("%d", &S[i].marks[j]);
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
    int z;
    for(z = 0; z < count; z++)
        if(roll_search == S[z].roll)
        {
            response = 1;
            send(fd1, &response, sizeof(response), 0);
            break;
        }
        else
            response = 0;
        
    if(response == 1)
        send(fd1, &S[z], sizeof(S[z]), 0);
    else
        exit(0);

    return 0;
}
