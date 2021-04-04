#include "../minishell.h"

int     ft_unset(t_node **head, char **cmd)
{
    int fd = 1;
    int i = 1;

    while(cmd[i] != NULL)
    {
        if (valid_id(cmd[i]) && !isequal(cmd[i]))
        {
            if (check_overwrite(*head, cmd[i]) == 1)
                deletenode(head, cmd[i]);
        }
        else
            export_error(cmd[i], fd);
        i++;
    }
    return(1);
}