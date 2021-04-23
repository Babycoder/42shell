#include "../minishell.h"

int       ft_execution(t_format *ptr, char **env)
{
    int ret;
    t_node  *head;

    ret = 0;
    head = get_envp(env);
    while(ptr != NULL)
    {
        //printf("%s\n", ptr->command);
        if (ft_strcmp(ptr->command, "pwd") == 0)
            ft_pwd(ptr);
        else if (ft_strcmp(ptr->command, "cd") == 0)
            ft_cd(ptr);
        else
            printf("command not found\n");
        ptr = ptr->next;
    }










    return (0);
}