/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:30:28 by ayghazal          #+#    #+#             */
/*   Updated: 2021/04/25 12:30:29 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int     ft_cd(t_format *ptr)
{
    int ret;

    if (ptr->arguments == NULL)
        return(1);
    ret = chdir(ptr->arguments->arg);
    if (ret < 0)
    {
        printf("cd: %s: No such file or directory\n", ptr->arguments->arg);
        return(1);
    }
    return(0);
}
