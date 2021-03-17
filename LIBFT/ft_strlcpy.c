/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:02:03 by ayghazal          #+#    #+#             */
/*   Updated: 2019/10/23 01:01:18 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	char				*temp;
	unsigned int		i;
	unsigned int		j;
	unsigned int		free;

	i = 0;
	j = 0;
	free = size - 1;
	temp = (char *)src;
	while (temp[j] != '\0')
	{
		j++;
	}
	if (size == 0)
		return (j);
	while (src[i] != '\0' && free > 0)
	{
		dst[i] = src[i];
		i++;
		free--;
	}
	dst[i] = '\0';
	return (j);
}
