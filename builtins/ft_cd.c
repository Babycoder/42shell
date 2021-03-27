#include "../minishell.h"
#include "../libft/libft.h"


int     ft_cd(char **cmd)
{

    int ret;
    
    ret =chdir(cmd[1]);
    if(ret<0)
        return(0);
    return(1);
}