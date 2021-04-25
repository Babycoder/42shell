/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:42:44 by ayghazal          #+#    #+#             */
/*   Updated: 2021/04/25 12:42:45 by ayghazal         ###   ########.fr       */
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

int     ft_exit(t_format *ptr)
{  
    if (ptr->arguments)
    {
        if(ft_isnumeric(ptr->arguments->arg))
        {
            if(ptr->arguments->next)
            {
                printf("exit\nminishell: exit: too many arguments\n");
                return(1);
            }
            printf("exit\n");
            exit(ft_atoi(ptr->arguments->arg));
        }
        else
        {
            printf("exit\nminishell: exit: %s: numeric argument required\n", ptr->arguments->arg);
            exit(255);
        }
    }
    else
    {
        printf("exit\n");
        exit(0);
    }
}
