#include "../minishell.h"
#include "../libft/libft.h"



int     ft_exit(char **cmd)
{
    if (cmd[1])
        exit(ft_atoi(cmd[1]));
    exit(0);
}