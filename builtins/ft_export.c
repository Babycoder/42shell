#include "../minishell.h"
#include "../libft/libft.h"


int     check_value(char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        if (s[i] == '=')
        {
            if(s[i+1])
                return(2);
            return(1);
        }
        i++;
    }
    return(0);
}

void    print_cases(char *s, int ret)
{
    int i;

    i = 0;
}

void    print_export(t_node *node)
{
    int ret = 0;
    int i = 0;

    while (node != NULL)
    {
        ft_putstr_fd("declare -x ", 1);
        ret = check_value(node->data);
        if (ret == 0)
        {
            ft_putendl_fd(node->data, 1);
        }
        if (ret == 1)
        {
            ft_putstr_fd(node->data, 1);
            ft_putendl_fd("\"\"", 1);
        }
        if (ret == 2)
        {
            i = 0;
            while(node->data[i] != '=')
            {
                ft_putchar_fd(node->data[i], 1);
                i++;
            }
            i++;
            ft_putstr_fd("=\"", 1);
            while(node->data[i])
            {
                ft_putchar_fd(node->data[i], 1);
                i++;
            }
            ft_putendl_fd("\"", 1);
        }
              
        
        node = node->next;
    }
}

int     ft_export(t_node **head, char **cmd)
{
    int i = 1;

    while (cmd[i])
    {
        push_node(head, cmd[i]);
        i++;
    }
    print_export(*head);

    return(1);
}