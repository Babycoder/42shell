/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:17:49 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/21 08:54:48 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"



void    ft_resetio(int sin, int sout)
{
    dup2(sin, STDIN_FILENO);
    dup2(sout, STDOUT_FILENO);
}

int ft_exec_cmd(char *command, t_arguments *arguments, t_redirections *redirections, t_node **head)
{
    int sout;
    int sin;

    sin = dup(STDIN_FILENO);
    sout = dup(STDOUT_FILENO);

    if(check_redirection(redirections, *head))
        return(1);
    if (ft_strcmp(command, "pwd") == 0)
        ft_pwd();
    else if (ft_strcmp(command, "cd") == 0)
        ft_cd(arguments, head);
    else if(ft_strcmp(command, "echo") == 0)
        ft_echo(arguments);
    else if (ft_strcmp(command, "exit") == 0)
        ft_exit(arguments);
    else if (ft_strcmp(command, "env") == 0)
        ft_env(arguments, *head);
    else if (ft_strcmp(command, "unset") == 0)
        ft_unset(arguments, head);
    else if (ft_strcmp(command, "export") == 0)
        ft_export(arguments, head);
    else
        ft_path(command, arguments, *head);
    ft_resetio(sin, sout);
    return(0);
}

int ft_exec(t_format *ptr, t_node **head)
{
    int ret;

    ret = 0;
    while(ptr != NULL)
    {
        g_global.p = 0;
        //g_global.forked = 1;
        //purge(convertenv(*head), ptr);
        if(ptr->pipes == NULL)
            ft_exec_cmd(ptr->command, ptr->arguments, ptr->redirections, head);
        else if (ptr->pipes)
        {
            g_global.p = 5;
            ft_setpipes(ptr->pipes, head);
        }
        ptr = ptr->next;
    }
    return (0);
}
