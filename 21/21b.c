#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<pthread.h>
void main(){
	char buff1[100];
	char buff2[100];
	int fd1=open("fifo1",O_RDONLY);
	int fd2=open("fifo2",O_WRONLY);
	read(fd1,buff1,sizeof(buff1));
	printf("Message from FIFO is: %s\n",buff1);	
	printf("Enter the text: ");
	scanf("%[^\n]",buff2);
	write(fd2,buff2,sizeof(buff2));
	
}