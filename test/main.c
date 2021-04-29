#include <stdio.h>
#include <string.h>
#include <unistd.h>


int     main(int ac, char **av, char **env)
{
    char *s[]= {"echo", NULL};
    //printf("%s\n", s[0]);
    execve("/bin/ls", s, env);
    return(0);
}
















