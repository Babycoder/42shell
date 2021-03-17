#include "minishell.h"
#include "LIBFT/libft.h"


int     main(int argc, char **argv)
{
    char *cmd[] = {"echo", "hello", "world", NULL};
   
    if (ft_strcmp(cmd[0], "echo") == 0)
    {
        ft_echo(cmd);
    }

    return(0);
}