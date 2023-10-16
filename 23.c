#include<unistd.h>
#include<stdio.h>

void main(void) {
    printf("Maximum number of files can be opend within a process: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Size of a pipe: %ld\n", pathconf(".", _PC_PIPE_BUF));
}