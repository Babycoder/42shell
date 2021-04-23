
#include "./minishell.h"

int     main(int ac, char **av, char **env)
{
    char *input;
    t_format    *ptr;

    while (1)
    {
        ptr = malloc(sizeof(t_format));
        if (parse(input, ptr) == NULL)//formatted data is now stored in ptr
            continue ;
        //printf("hello\n");
        ft_execution(ptr, env);
        //print_da(ptr);//if you want to print the output
        ft_freedom(ptr);//free func
    }
}