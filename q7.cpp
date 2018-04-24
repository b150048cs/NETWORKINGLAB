#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
int main(void){
	int fd[2],c=0,count[26]={0},x;
	char string[100];
	pid_t childpid;
	pipe(fd);
	if((childpid = fork()) < 0){
		perror("fork");
		exit(1);
	}
	if(childpid == 0){
		close(fd[0]);
		printf("Enter a string: ");
		gets(string);
		while(string[c] != '\0'){
			if(string[c] >= 'a' && string[c] <= 'z'){
				x = string[c] - 'a';
				count[x]++;
			}
			c++;
			write(fd[1],&count,sizeof(count));
			exit(0);
		}
	}
	else{
		close(fd[1]);
		read(fd[0],&count,sizeof(count));
		for(c=0;c<26;c++){
			printf("%c occurs %d times in the string.\n", c + 'a', count[c]);
		}
	}
	return(0);
}
