#include "../minishell.h"



void    print_env(t_node *node, int fd)
{
    while (node != NULL)
    {
        if (isequal(node->data))
            ft_putendl_fd(node->data, fd);
        node = node->next;
    }
}


int     ft_env(t_node *head, char **cmd)
{
    int fd;

    fd = 1;
    if (cmd[1] != NULL)
    {
        ft_putendl_fd("Too many argument", fd);
        return(0);
    }
    print_env(head, fd);
    return(1);
}