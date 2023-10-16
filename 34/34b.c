#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<pthread.h>

void *handleClient(void *arg) {
    int *client_socket = (int *) arg;
    printf("Client connected\n");
    char buff[100];
    read(*client_socket, buff, sizeof(buff));
    printf("Message from client: %s\n", buff);
    write(*client_socket, "ACK\n", 4);
}

void main() {
    struct sockaddr_in server, client;
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    pthread_t tid;

    server.sin_family = AF_INET;
    server.sin_port = htons(33546);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    bind(sd, (struct sockaddr*) &server, sizeof(server));

    listen(sd, 5);
    printf("Waiting for client...\n");
    while(1) {
        int nsd = accept(sd, (struct sockaddr*) NULL, 0);
        pthread_create(&tid, NULL, handleClient, &nsd);
    }

}