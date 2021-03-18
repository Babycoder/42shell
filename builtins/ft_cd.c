#include "../minishell.h"
#include "../libft/libft.h"


int     ft_cd(char **cmd)
{

    int ret;
    
    ret =chdir(cmd[1]);
    printf("%d\n", ret);
    if(ret<0)
        return(0);
    return(1);
}