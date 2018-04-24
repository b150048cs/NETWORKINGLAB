#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
#include<string.h>
int main(void){
	int fd[2];
	char salutation[100],name[100];
	pid_t childpid;
	pipe(fd);
	if((childpid = fork()) < 0){
		perror("Fork");
		exit(1);
	}
	if(childpid == 0){
		close(fd[0]);
		printf("Enter The name: ");
		scanf("%s",&name);
		printf("Enter the salutation: ");
		scanf("%s",&salutation);
		write(fd[1],&name,sizeof(name));
		write(fd[1],&salutation,sizeof(salutation));
		exit(0);
	}
	else{
		close(fd[1]);
		read(fd[0],&name,sizeof(name));
		read(fd[0],&salutation,sizeof(salutation));
		printf("%s,%s",salutation,name);
	}
	return(0);
}



