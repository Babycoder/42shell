#include "../minishell.h"
#include "../libft/libft.h"



int   ft_isnumeric(char *s)
{
    int i;

    i = 0;
    if(s)
    {
        while (s[i])
        {
            if (s[i] >= '0' && s[i] <= '9')
                i++;
            else
                return (0);
        }
    }
    return (1);
}

int     ft_exit(char **cmd)
{
    
    if (ft_isnumeric(cmd[1]))
    {
        if (cmd[2])
        {
            ft_putendl_fd("exit", 1);
            ft_putendl_fd("minishell: exit: too many arguments", 1);
            return(1);
        }
        ft_putendl_fd("exit", 1);
        if (cmd[1])
            exit(ft_atoi(cmd[1]));
        exit(0);
    }
    else
    {
        ft_putendl_fd("exit", 1);
        printf("minishell: exit: %s: numeric argument required\n", cmd[1]);
        exit(255);
    }
}