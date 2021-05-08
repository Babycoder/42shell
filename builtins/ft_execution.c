/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:17:49 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/03 15:19:05 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"



void    ft_resetio(int sin, int sout)
{
    dup2(sin, STDIN_FILENO);
    dup2(sout, STDOUT_FILENO);
}


void	set_pipes_fd(t_format *ptr)
{
	/*if (cmds[i].sep && cmds[i].sep[0] == '|')
		pipe(cmds[i].pipe);*/
    /*t_pipes *tmp;
    tmp = ptr->pipes;
    while(ptr->pipes != NULL)
    {
        pipe(ptr->pipes->fd);
        ptr->pipes = ptr->pipes->next;
    }
    ptr->pipes = tmp;
    printf("%s\n", ptr->pipes->command);*/
}

int ft_execution(t_format *ptr, t_node **head)
{
    int sout;
    int sin;
    int ret;

    ret = 0;
    sin = dup(STDIN_FILENO);
    sout = dup(STDOUT_FILENO);
    
    while(ptr != NULL)
    {
            //set_pipes_fd(ptr);
        if(check_redirection(ptr, *head))
            return(1);
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
        ft_resetio(sin, sout);
        ptr = ptr->next;
    }
    return (0);
}
