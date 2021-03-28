#include "../minishell.h"

void		ft_free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int			ft_isabsolute(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '/')
			return(1);
		i++;
	}
	return(0);
}

int			ft_ispath(char *s)
{
	return(s[0] == 'P' && s[1] == 'A' && s[2] == 'T' && s[3] == 'H');
}

void	print2d(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		printf("%s\n", s[i]);
		i++;
	}
}

char	*ft_join(char const *s1, char const *s2)
{
	char		*temp;
	char		*res;
	int			ls1;
	int			ls2;

	ls1 = 0;
	ls2 = 0;
	if (!s1)
		return (NULL);
	while (s1[ls1++])
		;
	while (s2[ls2++])
		;
	temp = (char *)malloc((ls1 + 1) + ls2 - 1);
	if (temp == NULL)
		return (NULL);
	res = temp;
	while (*s1 != '\0')
		*temp++ = *s1++;
	*temp++ = '/';
	while (*s2 != '\0')
		*temp++ = *s2++;
	*temp = '\0';
	return (res);
}


void    push_node(t_node **head, char *newdata)
{
    t_node *newnode = malloc(sizeof(t_node));

    newnode->data = newdata;
    newnode->next = *head;
    *head=newnode;

}

void    print_list(t_node *node)
{
    while (node != NULL)
    {
        printf("%s\n", node->data);
        node = node->next;
    }
}

t_node     *get_envp(char **env)
{
    int i;
    t_node *head;

    i = 0;
    head = NULL;
    while(env[i])
    {
        push_node(&head, env[i]);
        i++;
    }
    return(head);

}

char	*ft_equal(char	*s1)
{
	char		*temp;
	char		*res;
	int			ls1;


	ls1 = 0;
	if (!s1)
		return (NULL);
	while (s1[ls1++])
		;
	temp = (char *)malloc((ls1 + 3));
	if (temp == NULL)
		return (NULL);
	res = temp;
	while (*s1 != '=')
		*temp++ = *s1++;
	*temp++ = '=';
	*temp++ = 39;
	*temp++ = '=';
	*temp++ = 39;
	*temp = '\0';
	return (res);
}