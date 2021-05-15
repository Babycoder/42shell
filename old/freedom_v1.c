#include "functions_headerfile.h"

void    free_sliced_line_nodes(t_linedata *ptr)
{
    t_linedata *tmp;
    if (ptr != NULL)
    {
        while(1)
        {
            tmp = ptr->next;
            free(ptr);
            ptr = NULL;
            if (tmp == NULL)
                break ;
            ptr = tmp;
        }   
    }
}

void    free_targs_nodes(t_arguments    *ptr)
{
    t_arguments *tmp;
    if (ptr != NULL)
    {
        while(1)
        {
            tmp = ptr->next;
            free(ptr);
            ptr = NULL;
            if (tmp == NULL)
                break ;
            ptr = tmp;
        }
    }
}

void    free_tformat_nodes(t_format    *ptr)
{
    t_format *tmp;
    if (ptr != NULL)
    {
        while(1)
        {
            tmp = ptr->next;
            free(ptr);
            ptr = NULL;
            if (tmp == NULL)
                break ;
            ptr = tmp;
        }
    }
}

void    free_tred_nodes(t_redirections    *ptr)
{
    t_redirections *tmp;
    if (ptr != NULL)
    {
        while(1)
        {
            tmp = ptr->next;
            free(ptr);
            ptr = NULL;
            if (tmp == NULL)
                break ;
            ptr = tmp;
        }
    }
}

void    free_tpipes_nodes(t_pipes    *ptr)
{
    t_pipes *tmp;
    if (ptr != NULL)
    {
        while(1)
        {
            tmp = ptr->next;
            free(ptr);
            ptr = NULL;
            if (tmp == NULL)
                break ;
            ptr = tmp;
        }
    }
}