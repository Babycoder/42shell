#include "minishell.h"
#include "libft/libft.h"


int     main(int argc, char **argv)
{
    char *cmd[] = {"pwd", NULL};
   
    if (ft_strcmp(cmd[0], "echo") == 0)
    {
        ft_echo(cmd);
    }
    if (ft_strcmp(cmd[0], "pwd") == 0)
    {
        ft_pwd(cmd);
    }

    if (ft_strcmp(cmd[0], "cd") == 0)
    {
        if (cmd[2] == NULL)
            ft_cd(cmd);
        else
            perror("cd: too many arguments");
        
    }
    if (ft_strcmp(cmd[0], "exit") == 0)
        ft_exit(cmd);
    
    //printf("command not found\n");


    return(0);
}