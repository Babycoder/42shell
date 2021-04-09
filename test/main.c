#include <stdio.h>
#include <string.h>




char    **sorting(char **argv)
{
    int i;
    int j;
    char    *temp;
    i = 0;
    while (argv[i])
    {
        j = 0;
        while (argv[j])
        {
            if (strcmp(argv[i], argv[j]) < 0)
            {
                temp = argv[i];
                argv[i] = argv[j];
                argv[j] = temp;
            }
            j++;
        }
        i++;
    }
    return (argv);
}

void    print2d(char **s)
{
    int i = 0;
    while(s[i])
    {
        printf("%s\n", s[i]);
        i++;
    }
}

int     main()
{
    char **str;
    int i = 0;
    char *s[]= {"hhhhhh", "bbbbbbb", "zzzzzz", "aa", NULL};
    str  = sorting(s);
    print2d(str);
}