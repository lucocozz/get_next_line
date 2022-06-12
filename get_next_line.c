/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 03:55:22 by lucocozz          #+#    #+#             */
/*   Updated: 2022/06/12 17:37:33 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static bool	end_of_line(t_buffer *buffer)
{
	int			i;
	t_buffer	*last_link;

	if (buffer == NULL)
		return (false);
	last_link = buffer->prev;
	i = last_link->start - 1;
	while (i < last_link->size)
	{
		i++;
		last_link->end = i;
		if (last_link->buffer[i] == '\n')
		{
			last_link->end++;
			return (true);
		}
	}
	if (last_link->size < BUFFER_SIZE)
		return (true);
	return (false);
}

static int	get_line_len(t_buffer **buffer, int links_len)
{
	int			i;
	int			line_len;
	t_buffer	*tmp;

	i = 0;
	line_len = 0;
	tmp = *buffer;
	while (i < links_len)
	{
		line_len += (tmp->end - tmp->start);
		tmp = tmp->next;
		i++;
	}
	return (line_len);
}

static char	*get_line(t_buffer **buffer, int links_len)
{
	int			i;
	char		*line;
	int			prev_len;
	t_buffer	*link;

	i = 0;
	prev_len = 0;
	link = *buffer;
	line = malloc(sizeof(char) * (get_line_len(buffer, links_len) + 1));
	if (line == NULL)
		return (NULL);
	while (i < links_len)
	{
		i++;
		ft_strncpy(&line[prev_len], &link->buffer[link->start],
			link->end - link->start);
		prev_len += (link->end - link->start);
		if (i == links_len && link->end < link->size)
			link->start = link->end;
		else
			free_link(&link);
	}
	*buffer = link;
	return (line);
}

char	*get_next_line(int fd)
{
	int				links_len;
	int				read_size;
	t_buffer		*link;
	static t_buffer	*buffer = NULL;

	link = NULL;
	read_size = 0;
	links_len = (buffer != NULL);
	while (end_of_line(buffer) == false)
	{
		link = create_link();
		if (link == NULL)
			return (NULL);
		read_size = read(fd, link->buffer, BUFFER_SIZE);
		if (read_size < 0 || (read_size == 0 && links_len == 0))
		{
			free(link);
			return (NULL);
		}
		push_back(&buffer, link, read_size);
		links_len++;
	}
	return (get_line(&buffer, links_len));
}
