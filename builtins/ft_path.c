/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:42:32 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/15 17:49:32 by ayghazal         ###   ########.fr       */
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

int    check_redirection(t_redirections *redirections, t_node *head)
{
    int in;
    int out;

    in = 0;
    out = 0;
    while(redirections != NULL)
    {
        if (!(ft_strcmp(redirections->redirection_type, "<")))
            in = open(redirections->redirection_file,  O_RDONLY, S_IRWXU);
        if(!(ft_strcmp(redirections->redirection_type, ">")))
            out = open(redirections->redirection_file, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
        if(!(ft_strcmp(redirections->redirection_type, ">>")))
            out = open(redirections->redirection_file, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
        if ((in < 0 || out < 0))
        {
            printf("minishell: %s: %s\n", redirections->redirection_file, "No such file or directory");
            return(1);
        }
        if (redirections->next && out && ft_strcmp(redirections->next->redirection_type, "<"))
            close(out);
        if (redirections->next && in && !(ft_strcmp(redirections->next->redirection_type, "<")))
            close(in);
        redirections = redirections->next;
    }
    if(out)
        dup2(out, STDOUT_FILENO);
    if(in)
        dup2(in, STDIN_FILENO);
    return(0);
}

int     ft_path(char *command, t_arguments *arguments, t_node *head)
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
            printf("minishell: %s: No such file or directory\n", command);
            exit(1);
        }
        if (ft_isabsolute(command))
            execve(command, convertlist(arguments, command), convertenv(head));
        split = ft_split(path, ':');
        cmd = check_command(split, command);
        ft_free_split(split);
        if (cmd)
            execve(cmd, convertlist(arguments, command), convertenv (head));
        else
        {
            printf("minishell: %s: command not found\n", command);
            exit(1);
        }
    }
    else
        wait(NULL);
    return(0);
}
