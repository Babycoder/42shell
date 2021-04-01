#include <stdio.h>




int     arglen(char *s)
{
    int i;
    i = 0;

    while(s[i] && s[i] != '=')
        i++;
    return(i);
}







int     main()
{
    printf("%d\n", arglen("12345"));
    return(0);
}