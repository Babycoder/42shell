#include "../minishell.h"



int     ft_export(t_node **head, char **cmd)
{
    int fd = 1;
    int i = 1;

    while (cmd[i])
    {
        if (valid_id(cmd[i]))
            push_node(head, cmd[i]);
        else
            export_error(cmd[i], fd);
        i++;
    }
    print_export(*head, fd);

    return(1);
}