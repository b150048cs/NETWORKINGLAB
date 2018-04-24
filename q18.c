#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
int main(void)
{
	int Num;
	int fd[2];
	pid_t childpid;
	pipe(fd);
	 if((childpid = fork()) < 0)
        {
                perror("fork");
                exit(1);
        }
    if(childpid == 0)
        {
        close(fd[0]);
        printf("\nEnter the Num is : ");
        scanf("%d", &Num);
        write(fd[1], &Num, sizeof(Num));
        exit(0);
    }
    else
    {
    	close(fd[1]);
    	read(fd[0], &Num, sizeof(Num));
    	switch(Num){
               case 28:
               printf("ferbuary");
               break;

               case 29:
               printf("ferbuary");
               break;

               case 30:
               printf("april\n june\n september\n november\n");
               break;

               case 31:
               printf("january\n march\n may\n july\n august\n october\n december");
               break;

               default :
               printf("\nEnter the number between 28 to 31 only: ");
               break;
            }
    	return 0;
    }
}