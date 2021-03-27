#include "minishell.h"
#include "libft/libft.h"



int     main(int argc, char **argv, char **env)
{
    int ret = 0;
    t_node  *head;

    head = get_envp(env);

    char *cmd[] = {"ls", "-la", NULL};

    if (ft_strcmp(cmd[0], "echo") == 0)
        ft_echo(cmd);
    else if (ft_strcmp(cmd[0], "pwd") == 0)
        ft_pwd(cmd);
    else if (ft_strcmp(cmd[0], "cd") == 0)
    {
        if(ft_cd(cmd) == 0);
            printf("No such file or directory\n");
    }         
    else if (ft_strcmp(cmd[0], "exit") == 0)
        ft_exit(cmd);
    else if ((ft_strcmp(cmd[0], "env") == 0) && cmd[1] == NULL)
        ft_env(head);
    else 
        ft_path(cmd, head);
    //else
        //printf("command not found\n");*/

    return(0);
}