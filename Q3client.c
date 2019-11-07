// client requests for a particular student's records
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef struct Student{
    int roll;
    char name[50];
    int marks[5];
} Student;

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

    int rollSearch;
    printf("\nEnter the roll number to be searched : ");
    scanf("%d", &rollSearch);
    
    send(sockfd, &rollSearch, sizeof(rollSearch), 0);

    int response;
    Student S;
    recv(sockfd, &response, sizeof(response), 0);
    if(response == 1)
    {
        recv(sockfd, &S, sizeof(S), 0);
        printf("\nFound !");
        printf("\nRoll No. : %d\n", S.roll);
        printf("\nName : %s", S.name);
        printf("\nMarks : ");
        for(int i = 0; i < 5; i++)
            printf("%d\t", S.marks[i]);
        printf("\n");
    }
    else
    {
        printf("\nRecord not found.\n");
    }

    return 0;
}