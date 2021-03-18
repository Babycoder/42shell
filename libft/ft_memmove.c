/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:12:02 by ayghazal          #+#    #+#             */
/*   Updated: 2019/10/23 18:51:40 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *temp1;
	char *temp2;

	temp1 = (char *)dst;
	temp2 = (char *)src;
	if (dst == src)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, src, len);
	if (dst > src)
	{
		while (len--)
		{
			temp1[len] = temp2[len];
		}
	}
	return (dst);
}
