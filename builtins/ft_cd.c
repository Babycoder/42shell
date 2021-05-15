/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:30:28 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/15 17:25:54 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int     ft_cd(t_arguments *arguments)
{
    int ret;

    if (arguments == NULL)
        return(1);
    ret = chdir(arguments->arg);
    if (ret < 0)
    {
        printf("cd: %s: No such file or directory\n", arguments->arg);
        return(1);
    }
    return(0);
}
