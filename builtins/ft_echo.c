#include "../minishell.h"
#include "../libft/libft.h"

int     ft_echon(char *s)
{
    int i = 0;

    if (s == NULL)
        return(0);
    if (s[i] != '-')
        return(0);
    i++;
    while(s[i])
    {
        if (s[i] != 'n')
            return(0);
        i++;
    }
    return(1);
}

int     ft_echo(char **cmd)
{
    int i;
    int n = 0;

    i = 1;
    if (cmd[i] != NULL)
    {
        while(ft_echon(cmd[i]) == 1)
        {
            n = 1;
            i++;
        }
    }
    while (cmd[i] != NULL)
    {
        ft_putstr_fd(cmd[i], 1);
        if (cmd[i + 1] != NULL)
            ft_putchar_fd(' ', 1);
        i++;
    }
    if (n == 0)
        ft_putchar_fd('\n', 1);
    return(1);   
}
