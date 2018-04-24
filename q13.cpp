#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
#include<string.h>
int main(void){
	int fd[2],begin,end,count = 0;
	char s[1000],r[1000];
	pid_t childpid;
	pipe(fd);
	if((childpid = fork()) < 0){
		perror("Fork");
		exit(1);
	}
	if(childpid == 0){
		close(fd[0]);
		printf("Enter a string: ");
		scanf("%s",s);
	    while (s[count] != '\0')
      count++;
 
   end = count - 1;
 
   for (begin = 0; begin < count; begin++) {
      r[begin] = s[end];
      end--;
   }
 
   r[begin] = '\0';
		write(fd[1],&r,sizeof(r));
		exit(0);
	}
	else{
		close(fd[1]);
		read(fd[0],&r,sizeof(r));
		printf("String in reverse order:%s",r);
	}
	return(0);
}
