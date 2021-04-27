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

int     ft_export(t_format *ptr, t_node **head)
{

    if (ptr->arguments == NULL)
        print_export(*head);
    while (ptr->arguments != NULL)
    {
        if (valid_id(ptr->arguments->arg))
        {
            if (check_overwrite(*head, ptr->arguments->arg) == 1)
            {
                if(isequal(ptr->arguments->arg))
                {
                    deletenode(head, ptr->arguments->arg);
                    push_node(head, ptr->arguments->arg);
                }
            }
            else
                push_node(head, ptr->arguments->arg);
        }
        else
            export_error(ptr->arguments->arg);
        ptr->arguments = ptr->arguments->next;
    }
    return(1);
}