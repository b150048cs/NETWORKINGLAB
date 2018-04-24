#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
#include<string.h>
int main(void){
	int fd[2],n,c,k,xorofn;
	char str[100] = "";
	pid_t childpid;
	pipe(fd);
	if((childpid = fork()) < 0){
		perror("Error");
		exit(1);
	}
	if(childpid == 0){
		close(fd[0]);
		printf("Enter a integer: ");
		scanf("%d",&n);
		for(c=7;c>=0;c--){
			k = n>>c;
			if(k&1)
				strcat(str,"1");
			else
				strcat(str,"0");
		}
	xorofn = n^171;
	write(fd[1],&xorofn,sizeof(xorofn));
	write(fd[1],&str,sizeof(str));
	exit(0);
	}
	else{
		close(fd[1]);
		read(fd[0],&xorofn,sizeof(xorofn));
		read(fd[0],&str,sizeof(str));
		printf("Binary of number: %s",str);
		printf("\nXor of number with 10101011:%d",xorofn);
	}
	return(0);
}
