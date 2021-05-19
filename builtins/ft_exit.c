/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:42:44 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/19 12:42:41 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int   ft_isnumeric(char *s)
{
    int i;

    i = 0;
    if(s)
    {
        while (s[i])
        {
            if (s[i] >= '0' && s[i] <= '9')
                i++;
            else
                return (0);
        }
    }
    return (1);
}

void    exit_error(char *s)
{
    ft_putstr_fd("minishell: exit: ", 2);
    ft_putstr_fd(s, 2);
    ft_putstr_fd(": numeric argument required\n", 2); 
}

int     ft_exit(t_arguments *arguments)
{
    if (g_global.p == 0)
        ft_putstr_fd("exit\n", 2);  
    if (arguments)
    {
        if(ft_isnumeric(arguments->arg))
        {
            if(arguments->next)
            {
                ft_putstr_fd("minishell: exit: too many arguments\n", 2);
                return(1);
            }
            exit(ft_atoi(arguments->arg));
        }
        else
        {
            exit_error(arguments->arg);
            exit(255);
        }
    }
    else
        exit(0);
}
