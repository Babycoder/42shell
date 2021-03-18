/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 23:02:30 by ayghazal          #+#    #+#             */
/*   Updated: 2019/10/26 16:03:23 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	unsigned int	ln;
	char			*p1;
	char			*p2;

	i = 0;
	p1 = (char *)haystack;
	p2 = (char *)needle;
	ln = ft_strlen(needle);
	if (*needle == '\0')
		return (p1);
	while (p1[i] != '\0' && (ln + i) <= len)
	{
		if (ft_strncmp((p1 + i), p2, ln) == 0)
		{
			return (p1 + i);
		}
		i++;
	}
	return (NULL);
}
