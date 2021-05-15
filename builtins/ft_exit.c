/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:42:44 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/15 17:36:07 by ayghazal         ###   ########.fr       */
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

int     ft_exit(t_arguments *arguments)
{  
    if (arguments)
    {
        if(ft_isnumeric(arguments->arg))
        {
            if(arguments->next)
            {
                printf("exit\nminishell: exit: too many arguments\n");
                return(1);
            }
            printf("exit\n");
            exit(ft_atoi(arguments->arg));
        }
        else
        {
            printf("exit\nminishell: exit: %s: numeric argument required\n", arguments->arg);
            exit(255);
        }
    }
    else
    {
        printf("exit\n");
        exit(0);
    }
}
