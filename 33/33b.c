#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void main() {
    struct sockaddr_in server;
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    
    server.sin_family = AF_INET;
    server.sin_port = htons(33546);
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Waiting for server...\n");
    connect(sd, (struct sockaddr*) &server, sizeof(server));
    printf("Connected to server\n");

    char buff[100];
    write(sd, "Hello\n", 6);
    read(sd, buff, sizeof(buff));
    printf("Message from Server: %s\n", buff);
    getchar();
}