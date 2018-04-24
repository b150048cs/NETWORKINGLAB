#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>

#define size 2

int main(void)
{
        int fd[2], vector[4*size], arr1[size][size], arr2[size][size], i, j, k=0;
        pid_t   childpid;

        pipe(fd);
        
        if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }
        if(childpid == 0)
        {
               
                close(fd[0]);

                

                printf("\nEnter values of first %dX%d matrix: ", size, size);
		for (k=0; k<2*size; k++)
			scanf("%d",&vector[k]);
		//printf("\nEnter values of second %dX%d matrix: ", size, size);
		for (k=2*size; k<4*size; k++)
			scanf("%d",&vector[k]);
		write(fd[1], &vector, sizeof(vector));
                exit(0);
        }
        else
        {

		close(fd[1]);

		read(fd[0], &vector, sizeof(vector));
		k=0;
		printf("\nFirst 2D array:\n");
		for (i=0; i<size; i++)
		{
			for (j=0; j<size; j++)
			{
				arr1[i][j]=vector[k++];
				printf("%d ",arr1[i][j]);
			}
			printf("\n");
		}
		printf("\nSecond 2D array:\n");
		for (i=0; i<size; i++)
		{
			for (j=0; j<size; j++)
			{
				arr2[i][j]=vector[k++];
				printf("%d ",arr2[i][j]);
			}
			printf("\n");
		}
        }
	printf("\n");
        return(0);
}
