#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

void main() {
    key_t key = ftok(".", 's');
    int shmid = shmget(key, 1024, 0);

    char *data = shmat(shmid, 0, 0);
    shmdt(data);
}