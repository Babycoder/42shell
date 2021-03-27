#include "../minishell.h"
#include "../libft/libft.h"
int     novalue(char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        if (s[i] == '=')
        {
            if (s[i+1])
                return(0);
            return(1);
        }
        i++;
    }
    return(1);
}

int     ft_export(t_node **head, char **cmd)
{
    int i = 1;
    int ret = 0;

    while (cmd[i])
    {
        if (!(ret = novalue(cmd[i])))
            push_node(head, cmd[i]);
        else
            push_node(head, ft_strjoin(cmd[i], "=''"));
        i++;
    }
    print_list(*head);

    return(1);
    //push_node(head, "HELOOOOOOOOOOOO");
}