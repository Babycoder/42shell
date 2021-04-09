#include "../minishell.h"

int     arglen(char *s)
{
    int i;
    i = 0;

    while(s[i] && s[i] != '=')
        i++;
    return(i);
}



int     check_overwrite(t_node *node, char *s)
{
    int len1;
    int len2;
    
    len1 = 0;
    len2 = arglen(s);
    while (node != NULL)
    {
        len1 = arglen(node->data);
        if (len1 == len2)
        {
            if  (ft_strncmp(node->data, s, len2) == 0)
                return(1);
        }
        node = node->next;
    }
    return(0); 
}

int     ft_export(t_node **head, char **cmd)
{
    int fd = 1;
    int i = 1;

    while (cmd[i] != NULL)
    {
        if (valid_id(cmd[i]))
        {
            if (check_overwrite(*head, cmd[i]) == 1)
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
    //print_list(*head);
    return(1);
}