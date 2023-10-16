#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>

void main() {
    struct msg {
        int mtype;
        char mtext[100];
    } mq;
    key_t key = ftok(".", 's');
    int msgid = msgget(key, 0);

    msgctl(msgid, IPC_RMID, NULL);
}