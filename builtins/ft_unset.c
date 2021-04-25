/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:28:54 by ayghazal          #+#    #+#             */
/*   Updated: 2021/04/25 13:29:00 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int     ft_unset(t_format *ptr, t_node **head)
{

    while(ptr->arguments != NULL)
    {
        if (valid_id(ptr->arguments->arg) && !isequal(ptr->arguments->arg))
        {
            if (check_overwrite(*head, ptr->arguments->arg) == 1)
                deletenode(head, ptr->arguments->arg);
        }
        else
            export_error(ptr->arguments->arg);
        ptr->arguments = ptr->arguments->next;
    }
    return(0);
}
