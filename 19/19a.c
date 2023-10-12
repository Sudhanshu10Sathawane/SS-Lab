#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<pthread.h>
void main(){
	char *file_name="./mknodeFIFO";
	int ch=mknod(file_name,S_IFIFO|0666,0);
	if(ch!=-1){
		printf("Success\n");
	}else{
		printf("Error\n");
	}
}