/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:17:49 by ayghazal          #+#    #+#             */
/*   Updated: 2021/04/25 12:17:51 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int ft_execution(t_format *ptr, t_node **head)
{
    int ret;

    ret = 0;
    
    while(ptr != NULL)
    {
        if (ft_strcmp(ptr->command, "pwd") == 0)
            ft_pwd();
        else if (ft_strcmp(ptr->command, "cd") == 0)
            ft_cd(ptr);
        else if(ft_strcmp(ptr->command, "echo") == 0)
            ft_echo(ptr);
        else if (ft_strcmp(ptr->command, "exit") == 0)
            ft_exit(ptr);
        else if (ft_strcmp(ptr->command, "env") == 0)
            ft_env(ptr, *head);
        else if (ft_strcmp(ptr->command, "unset") == 0)
            ft_unset(ptr, head);
        else if (ft_strcmp(ptr->command, "export") == 0)
            ft_export(ptr, head);
        else
            ft_path(ptr, *head);
            //printf("command not found\n");
        ptr = ptr->next;
    }
    return (0);
}
