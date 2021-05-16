/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:30:28 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/16 13:02:35 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    cd_error(char *s)
{
        ft_putstr_fd("cd: ", 2);
        ft_putstr_fd(s, 2);
        ft_putstr_fd(": No such file or directory\n", 2);   
}

int     ft_cd(t_arguments *arguments)
{
    int ret;

    if (arguments == NULL)
        return(1);
    ret = chdir(arguments->arg);
    if (ret < 0)
    {
        cd_error(arguments->arg);
        return(1);
    }
    return(0);
}
