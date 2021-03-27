#include "../minishell.h"
#include "../libft/libft.h"


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

int     ft_path(char  **cmd, t_node *head)
{
    char *path;
    char **split;
    char *command;

    if (!(path = getpath(head)))
        return(0);
    if (ft_isabsolute(cmd[0]))
        execve(cmd[0], cmd, NULL);
    split = ft_split(path, ':');
    command = check_command(split, cmd[0]);
    ft_free_split(split);
    if (command)
        execve(command, cmd, NULL);
    else
        return(0);
    return(1);
}