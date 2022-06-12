/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 03:55:29 by lucocozz          #+#    #+#             */
/*   Updated: 2022/06/12 17:38:04 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_buffer	*create_link(void)
{
	t_buffer	*link;

	link = malloc(sizeof(t_buffer) * 1);
	link->size = 0;
	link->end = 0;
	link->start = 0;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

void	push_back(t_buffer **buffer, t_buffer *link, int read_size)
{
	t_buffer	*tmp;

	tmp = *buffer;
	link->size = read_size;
	link->buffer[read_size] = '\0';
	if (tmp == NULL)
	{
		link->next = link;
		link->prev = link;
		*buffer = link;
	}
	else
	{
		link->next = tmp;
		link->prev = tmp->prev;
		tmp->prev->next = link;
		tmp->prev = link;
	}
}

void	free_link(t_buffer **link)
{
	t_buffer	*tmp;

	tmp = *link;
	if (tmp->next == tmp)
	{
		free(tmp);
		*link = NULL;
	}
	else
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		*link = tmp->next;
		free(tmp);
	}
}

void	ft_strncpy(char *dst, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}
