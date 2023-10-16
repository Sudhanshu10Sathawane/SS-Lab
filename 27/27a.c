#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>

void main() {
    struct msg {
        long mtype;
        char mtext[100];
    } mq;
    key_t key = ftok(".", 's');
    int msgid = msgget(key, IPC_CREAT | 0600);

    printf("Enter msg type: ");
    scanf("%ld", &mq.mtype);

    msgrcv(msgid, &mq, sizeof(mq.mtext), mq.mtype, 0);
    printf("Message : %s\n", mq.mtext);
}