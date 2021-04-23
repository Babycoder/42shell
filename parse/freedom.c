#include "functions_headerfile.h"

void    free_sliced_line_strings(t_linedata *ptr)
{
    if (ptr != NULL)
    {
        while(1)
        {
            free(ptr->slice);
            ptr->slice = NULL;
            
            ptr = ptr->next;
            if (ptr == NULL)
                break ;
        }
    }
}

void    free_tpipes_contents(t_pipes    *ptr)
{
    while(1)
    {
        free(ptr->line);
        ptr->line = NULL;
        free_sliced_line_strings(ptr->sliced_line);//done
        free_sliced_line_nodes(ptr->sliced_line);//done
        free_targs_nodes(ptr->arguments);//done
        free_tred_nodes(ptr->redirections);//done
        
        ptr = ptr->next;
        if (ptr == NULL)
            break ;
    }
}
void    free_tformat_contents(t_format *ptr)
{
    while(1)
    {
        free(ptr->line);
        ptr->line = NULL;
        free_sliced_line_strings(ptr->sliced_line);//done
        free_sliced_line_nodes(ptr->sliced_line);//done
        free_targs_nodes(ptr->arguments);//done
        free_tred_nodes(ptr->redirections);//done
        if (ptr->pipes != NULL)
        {
            free(ptr->pre_pipe_line);
            ptr->pre_pipe_line = NULL;
            free_tpipes_contents(ptr->pipes);//done
            free_tpipes_nodes(ptr->pipes);//done
        }
        ptr = ptr->next;
        if (ptr == NULL)
            break ;
    }
}

void    ft_freedom(t_format *ptr)
{
    free_tformat_contents(ptr);
    free_tformat_nodes(ptr);
}