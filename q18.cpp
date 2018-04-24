#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
int main(void){
	int fd[2], number;
	pid_t childpid;
	pipe(fd);
	if((childpid = fork()) == -1){
		perror("fork error");
		exit(1);
	}
	if(childpid==0){
		close(fd[0]);
		printf("Enter a number: ");
		scanf("%d",&number);
		write(fd[1],&number,sizeof(number));
	
		exit(0);
	}
	else
	{
		close(fd[1]);
		read(fd[0],&number,sizeof(number));
			swich(number)
			case 28:
				printf("February");
				break;
			case 29:
				printf("February");
				break;
			case 30:
				printf("April\nJune\nSeptember\nNovember");
				break;
			case 31:
				printf("January\nMarch\nMay\nJuly\nAugust\nOctober\nDecember");
				break;
			default:
				print("Please Print in between 28 to 31.");
				break;
	}
	return(0);
}
