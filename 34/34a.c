#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void main() {
    struct sockaddr_in server, client;
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    
    server.sin_family = AF_INET;
    server.sin_port = htons(33546);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    bind(sd, (struct sockaddr*) &server, sizeof(server));

    listen(sd, 5);
    printf("Waiting for client...\n");
    while(1) {
        int nsd = accept(sd, (struct sockaddr*) NULL, 0);
        if(fork()) {
            close(nsd);
        } else {
            close(sd);
            printf("Client connected\n");
            char buff[100];
            read(nsd, buff, sizeof(buff));
            printf("Message from client: %s\n", buff);
            write(nsd, "ACK\n", 4);
            _exit(0);
        }
    }

}