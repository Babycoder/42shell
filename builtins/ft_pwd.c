#include "../minishell.h"
#include  "../libft/libft.h"


int     ft_pwd(char **cmd)
{
    char cwd[1200];

    if (getcwd(cwd, sizeof(cwd)) == NULL)
        return(0);
    else
        ft_putendl_fd(cwd, 1);
    return (1);     
}