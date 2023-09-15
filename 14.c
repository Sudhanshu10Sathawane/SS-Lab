#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int a[2];
	char buffer[10];
	if(pipe(a)==-1){
		perror("Error in pipe");
		exit(1);
	}
	write(a[1],"ssgmce",7);
	printf("\n");

	read(a[0],buffer,7);
	printf("%s\n",buffer);
}
