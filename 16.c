#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<pthread.h>
int main(){
	char buff1[100],buff2[100];
	int ptoc[2];
	int ctop[2];
	pipe(ptoc);
	pipe(ctop);
	if(!fork()){
		close(ptoc[0]);
		close(ctop[1]);
		printf("Enter Message to parent: ");
		scanf("%s",buff1);
		write(ptoc[1],buff1,sizeof(buff1));
		read(ctop[0],buff2,sizeof(buff2));
		printf("Message from Parent: %s\n",buff2);
	}else{
		close(ptoc[1]);
		close(ctop[0]);
		read(ptoc[0],buff1,sizeof(buff1));
		printf("Message from Child:  %s\n",buff1);
		printf("Enter Message to Child: ");
		scanf("%s",buff2);
		write(ctop[1],buff2,sizeof(buff2));
	}
}
