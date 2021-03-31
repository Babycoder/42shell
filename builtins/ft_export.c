#include "../minishell.h"

int     arglen(char *s)
{
    int i;
    i = 0;

    while(s[i] && s[i] != '=')
        i++;
    return(i);
}


int     isequal(char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        if (s[i] == '=')
            return (1);
        i++;
    }
    return(0);
}

int     check_overwrite(t_node *node, char *s)
{
    int len1 = arglen(node->data);
    int len2 = arglen(s);
    
    if (len1 != len2)
        return(0);
    while (node != NULL)
    {
        if  (ft_strncmp(node->data, s, len1) == 0)
            return(1);
        node = node->next;
    }
    return(0); 
}

int     ft_export(t_node **head, char **cmd)
{
    int fd = 1;
    int i = 1;

    while (cmd[i])
    {
        if (valid_id(cmd[i]))
        {
            if (check_overwrite(*head, cmd[i]))
            {
                if(isequal(cmd[i]))
                {
                    deletenode(head, cmd[i]);
                    push_node(head, cmd[i]);
                }
            }
            else
                push_node(head, cmd[i]);
        }
        else
            export_error(cmd[i], fd);
        i++;
    }
    print_export(*head, fd);

    return(1);
}