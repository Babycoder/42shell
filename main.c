#include "minishell.h"
#include "libft/libft.h"



int     main(int argc, char **argv, char **env)
{
    int ret = 0;
    t_node  *head;// = NULL;

    head = get_envp(env);
    //print_list(head);
    
    char *cmd[] = {"ls", NULL};

    //ret = execve("/bin/ls", cmd, env);
    //printf("%d\n", ft_isabsolute("/hello"));
    /*if (ft_strcmp(cmd[0], "echo") == 0)
        ft_echo(cmd);
    else if (ft_strcmp(cmd[0], "pwd") == 0)
        ft_pwd(cmd);
    else if (ft_strcmp(cmd[0], "cd") == 0)
        ft_cd(cmd);
    else if (ft_strcmp(cmd[0], "exit") == 0)
        ft_exit(cmd);
    else
        printf("command not found\n");*/
    ft_path(cmd, head, env);

    return(0);
}