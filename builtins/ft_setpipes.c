/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setpipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:02:30 by ayghazal          #+#    #+#             */
/*   Updated: 2021/05/16 18:26:29 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pipe_len(t_pipes *pipes)
{
	t_pipes *tmp;
	int i;

	i = 0;
	tmp = pipes;
	while(tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return(i);
}

int    ft_setpipes(t_pipes *pipes, t_node **head)
{
	int len;

	len = pipe_len(pipes);
	printf("%d\n", len);

	return (0);
}