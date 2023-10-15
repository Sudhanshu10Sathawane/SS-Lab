#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/select.h>
#include<sys/stat.h>
#include<pthread.h>
void main(){
	char buff[80];
    fd_set readfds;
    struct timeval tv;
    int fd = open("fifo", O_RDONLY);
    
    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);
    tv.tv_sec = 10;
    tv.tv_usec = 0;

    int available = select(fd+1, &readfds, NULL, NULL, &tv);

    if(!available) printf("Data not available\n");
    else {
        printf("Data is available now\n");
        read(fd, buff, sizeof(buff));
        printf("The text : %s\n", buff);
    }

}