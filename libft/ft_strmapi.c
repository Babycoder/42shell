/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 12:21:06 by ayghazal          #+#    #+#             */
/*   Updated: 2019/10/26 00:51:44 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*res;
	char				*str;

	i = 0;
	str = (char *)s;
	if (s == NULL || f == NULL)
		return (NULL);
	res = (char *)malloc((ft_strlen(str) + 1));
	if (res == NULL)
		return (NULL);
	while (str[i])
	{
		res[i] = (*f)(i, str[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
