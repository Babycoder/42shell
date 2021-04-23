#include "../minishell.h"
#include  "../libft/libft.h"


int     ft_pwd(t_format *ptr)
{
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) == NULL)
        return(0);
    else
        ft_putendl_fd(cwd, 1);
    return (1);     
}