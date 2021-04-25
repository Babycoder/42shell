/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:37:49 by ayghazal          #+#    #+#             */
/*   Updated: 2021/04/25 12:37:51 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int     ft_echon(char *s)
{
    int i = 0;

    if (s == NULL)
        return(0);
    if (s[i] != '-')
        return(0);
    i++;
    while(s[i])
    {
        if (s[i] != 'n')
            return(0);
        i++;
    }
    return(1);
}

int     ft_echo(t_format *ptr)
{
    int n = 0;

    if (ptr->arguments != NULL)
    {
        while(ft_echon(ptr->arguments->arg) == 1)
        {
            n = 1;
            ptr->arguments = ptr->arguments->next;
            if (ptr->arguments == NULL)
                break;
        }
    }
    while (ptr->arguments != NULL)
    {
        ft_putstr_fd(ptr->arguments->arg, 1);
        if (ptr->arguments->next != NULL)
            ft_putchar_fd(' ', 1);
        ptr->arguments = ptr->arguments->next;
    }
    if (n == 0)
        ft_putchar_fd('\n', 1);
    return(0);   
}
