/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:17:09 by ayghazal          #+#    #+#             */
/*   Updated: 2021/04/25 13:17:10 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    print_env(t_node *node)
{
    while (node != NULL)
    {
        if (isequal(node->data))
            ft_putendl_fd(node->data, 1);
        node = node->next;
    }
}


int     ft_env(t_format *ptr,t_node *head)
{

    if (ptr->arguments)
    {
        ft_putendl_fd("Too many argument", 1);
        return(1);
    }
    print_env(head);
    return(0);
}
