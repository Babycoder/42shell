#include "../minishell.h"
#include "../libft/libft.h"


char    *get_path(char **env)
{
    int i;
    char *path = NULL;

    i = 0;
    while (env[i] != NULL)
    {
        if (ft_ispath(env[i]))
        {
            path = env[i]+5;
            return(path);
        }
        i++;
    }
    return(path);
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

int     ft_path(char  **cmd, t_node *head, char **env)
{
    char *path;
    char **split;
    char *command;

    if (!(path = getenv("PATH")))
        return(0);
    split = ft_split(path, ':');
    command = check_command(split, cmd[0]);
    if (command)
        execve(command, cmd, env);
    else
        printf("command not found\n");
        

    //execve(command, cmd, env);
    //print2d(split);
    //printf("x\n");
    //printf("%s\n", command);
    //printf("%s\n", getenv("PATH"));



    return(1);
}