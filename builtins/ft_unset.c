/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:28:54 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/15 17:43:02 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int     ft_unset(t_arguments *arguments, t_node **head)
{

    while(arguments != NULL)
    {
        if (valid_id(arguments->arg) && !isequal(arguments->arg))
        {
            if (check_overwrite(*head, arguments->arg) == 1)
                deletenode(head, arguments->arg);
        }
        else
            export_error(arguments->arg);
        arguments = arguments->next;
    }
    return(0);
}
