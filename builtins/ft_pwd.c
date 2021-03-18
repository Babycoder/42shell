#include "../minishell.h"
#include  "../libft/libft.h"


int     ft_pwd(char **cmd)
{
    char cwd[256];

    if (getcwd(cwd, sizeof(cwd)) == NULL)
        return(0);
    else
        printf("%s\n", cwd);
    return (1);     
}