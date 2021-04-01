#include <stdio.h>




int     arglen(char *s)
{
    int i;
    i = 0;

    while(s[i] && s[i] != '=')
        i++;
    return(i);
}

int     get_arglen(char *s1, char *s2)
{
    int len1 = arglen(s1);
    int len2 = arglen(s2);

    if (len1 > len2)
        return(len1);
    else
        return(len2);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if ((s1[i] == '\0' && s2[i] == '\0') || n == 0)
		return (0);
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}






int     main()
{
    printf("%d\n", ft_strncmp("abcd=argaga", "ab=agadgadfg", get_arglen("ab=agadgadfg", "abcd=argaga")));
    return(0);
}