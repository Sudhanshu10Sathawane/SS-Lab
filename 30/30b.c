#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

void main() {
    key_t key = ftok(".", 's');
    int shmid = shmget(key, 1024, IPC_CREAT | 0600);

    char *data = shmat(shmid, 0, SHM_RDONLY);
    printf("Enter the text: ");
    scanf("%[^\n]", data);
}