#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>



int     main(int ac, char **av)
{
    int fd[2];
    
    //fd[0] ==> read;
    //fd[1] ==> write;

    if(pipe(fd) == -1)
    {
        printf("Error on pipe");
        return 1;
    }

    int id = fork();
    if (id == 0)
    {
        close(fd[0]);
        int x;
        printf("what's your ages ? :");
        scanf("%d", &x);
        write(fd[1], &x, sizeof(int));
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int y;
        read(fd[0], &y, sizeof(int));
        close(fd[0]);
        printf("got from child process = %d\n", y);
        
    }

    return(0);
}