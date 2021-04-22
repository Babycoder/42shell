#include "functions_headerfile.h"

int     main()
{
    char *input;
    t_format    *ptr;

    while (1)
    {
        ptr = malloc(sizeof(t_format));
        if (parse(input, ptr) == NULL)//formatted data is now stored in ptr
            continue ;
        //ft_execution(ptr);
        //print_da(ptr);//if you want to print the output
        ft_freedom(ptr);//free func
    }
}