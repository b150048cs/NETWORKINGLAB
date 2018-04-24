#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>

int main(void)
{
        int     fd[2], i, j, a, n=10, number[30] ;
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

               printf("Enter the numbers \n");

        for (i = 0; i < n; ++i)

               scanf("%d", &number[i]);

       for (i = 0; i < n; ++i)

           {

               for (j = i + 1; j < n; ++j)

           {

                      if (number[i] > number[j])

                    {

                      a =  number[i];

                      number[i] = number[j];

                      number[j] = a;

            }

           }
        }


    for (i = 0; i < n; ++i)

    write(fd[1], &number[i], sizeof(number[i]));

                exit(0);
        }

        else

        {

                close(fd[1]);
                printf("the numbers in ascending order: ");
               for (i = 0; i < n; ++i){
                read(fd[0], &number[i], sizeof(number[i]));
                printf(" %d ", number[i]);
        }}

        return(0);
}
