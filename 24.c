#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>

void main(void) {
    key_t key = ftok(".", 's');
    int msgid = msgget(key, IPC_CREAT | 0666);
    printf("Key: 0x%0x, msg-id: %d\n", key, msgid);   
}