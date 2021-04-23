#include "../minishell.h"
#include "../libft/libft.h"


int     ft_cd(t_format *ptr)
{

    int ret;

    ret = chdir(ptr->arguments->arg);
    if (ret < 0)
    {
        printf("cd: %s: No such file or directory\n", ptr->arguments->arg);
        return(0);
    }
    return(1);
}