#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<time.h>

void main() {
    key_t key = ftok(".", 's');
    int msgid = msgget(key, IPC_CREAT | 0666);
    struct msqid_ds ds;
    msgctl(msgid, IPC_STAT, &ds);
    struct ipc_perm perm = ds.msg_perm;

    printf("Access permission: %o\n", perm.mode);
    printf("UID: %d\n", perm.uid);
    printf("GID: %d\n", perm.gid);
    printf("Time of last message send: %s", ctime(&ds.msg_stime));
    printf("Time of last message receive: %s", ctime(&ds.msg_rtime));
    printf("Time of last change in the message queue: %s", ctime(&ds.msg_ctime));
    printf("Number of messages in queue: %ld\n", ds.msg_qnum);
    printf("Maximum number of bytes allowed: %ld\n", ds.msg_qbytes);
    printf("PID of msgsnd: %d\n", ds.msg_lspid);
    printf("PID of msgrcv: %d\n", ds.msg_lrpid);

}