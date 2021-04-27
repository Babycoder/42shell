/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:42:32 by ayghazal          #+#    #+#             */
/*   Updated: 2021/04/25 16:42:33 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char    *getpath(t_node *node)
{
    int i;
    i = 0;
    while (node != NULL)
    {
        if (ft_ispath(node->data))
        {
            return(node->data + 5);
        }
        node = node->next;
    }
    return(NULL);
}

char     *check_command(char **split, char *cmd)
{
    char *command;
    int i = 0;

    while (split[i])
    {
        command = ft_join(split[i], &cmd[0]);
        if (open(command, O_RDONLY) > 0)
            return(command);
        i++;
    }
    return(NULL);
}

int     ft_path(t_format *ptr, t_node *head)
{
    char *path;
    char **split;
    char  *cmd;
    int pid = 0;

    pid = fork();
    if (pid == 0)
    {
        if (!(path = getpath(head)))
        {
            printf("minishell: %s: No such file or directory\n", ptr->command);
            exit(1);
        }
        if (ft_isabsolute(ptr->command))
            execve(ptr->command, convertlist(ptr->arguments, ptr->command), convertenv(head));
        split = ft_split(path, ':');
        cmd = check_command(split, ptr->command);
        ft_free_split(split);
        if (cmd)
            execve(cmd, convertlist(ptr->arguments, ptr->command), convertenv(head));
        else
        {
            printf("minishell: %s: command not found\n", ptr->command);
            exit(1);
        }
    }
    else
        wait(NULL);
    return(0);
}
