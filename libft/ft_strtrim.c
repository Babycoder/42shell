/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:49:35 by ayghazal          #+#    #+#             */
/*   Updated: 2019/10/29 23:49:31 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		left(char const *s1, char const *set, int *ptr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
			*ptr = 0;
		}
		else
		{
			j++;
			*ptr = 1;
		}
	}
	return (i);
}

static int		right(char const *s1, char const *set, int *ptr)
{
	int j;
	int l;

	j = 0;
	l = ft_strlen(s1) - 1;
	while (l >= 0 && set[j] != '\0')
	{
		if (s1[l] == set[j])
		{
			l--;
			j = 0;
			*ptr = 0;
		}
		else
		{
			j++;
			*ptr = 1;
		}
	}
	return (l);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		l;
	int		notfound;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*set == '\0')
		return (ft_strdup(s1));
	notfound = 0;
	i = left(s1, set, &notfound);
	l = right(s1, set, &notfound);
	return (notfound) ? (ft_substr(s1, i, ((l - i) + 1))) : ft_strdup("");
}
