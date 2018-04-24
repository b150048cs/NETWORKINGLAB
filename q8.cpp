#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
int main(void){
	int fd[2],num;
	pid_t childpid;
	pipe(fd);
	if((childpid = fork()) < 0){
		perror("fork");
		exit(1);
	}
	if(childpid == 0){
		close(fd[0]);
		printf("Enter a number in between 1-9: ");
		scanf("%d",&num);
		write(fd[1],&num,sizeof(num));
		exit(0);
	}
	else{
		close(fd[1]);
		read(fd[0],&num,sizeof(num));
		switch(num){
			case 1:
				printf("First");
				break;
			case 2:
				printf("Second");
				break;
			case 3:
				printf("Third");
				break;
			case 4:
				printf("Fourth");
				break;
			case 5:
				printf("Fifth");
				break;
			case 6:
				printf("Sixth");
				break;
			case 7:
				printf("Seventh");
				break;
			case 8:
				printf("Eigth");
				break;
			case 9:
				printf("Nine");
				break;
			default:
				printf("Please enter a number in between 1 - 9.");
				break;
		}
	}
	return(0);
}
