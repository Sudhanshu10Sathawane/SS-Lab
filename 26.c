#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>

void main() {
    struct msg {
        long mtype;
        char mtext[100];
    } mq;
    key_t key = ftok(".", 's');

    int msgid = msgget(key, IPC_CREAT | 0600);
    printf("Key: 0x%0x, msg-id: %d\n", key, msgid);

    printf("Enter msg type: ");
    scanf("%ld", &mq.mtype);
    getchar();

    printf("Enter message: ");
    scanf("%[^\n]", mq.mtext);

    int size = strlen(mq.mtext);
    msgsnd(msgid, &mq, size + 1, 0);
}