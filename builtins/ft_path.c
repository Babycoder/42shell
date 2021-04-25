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
    char *command;

    if (!(path = getpath(head)))
        return(0);
    if (ft_isabsolute(ptr->command))
        execve(ptr->command, cmd, NULL);
    split = ft_split(path, ':');
    command = check_command(split, cmd[0]);
    ft_free_split(split);
    if (command)
        execve(command, cmd, NULL);
    else
        return(0);
    return(1);
}
