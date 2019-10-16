/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:28:33 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/16 22:35:56 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// 1 : Une ligne a été lue
// 0 : La lecture est terminée
// -1 : Une erreur est survenue

static char		*ft_getline(t_buff *gnl)
{
	int		len;
	char	*tmp;

	while (gnl->buffer[len] != '\0' && gnl->buffer[len] != '\0')
		len++;
	if (gnl->buffer != '\n')
		return (NULL);
}

int				get_next_line(int fd, char **line)
{
	int				size;
	char 			*tmp;
	static t_buff	gnl;
	
	if (!gnl.buffer)
		if ((gnl.buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char))) == NULL)
			return (-1);
		if ((size = read(fd, gnl.buffer, BUFFER_SIZE)) == 0)
			return (0);
		else if (size == -1)
			return (-1);
	if ((tmp = ft_getline(&gnl)) == NULL)
		//copy
	else
	{
		*line = tmp;
		return (1);
	}
	printf("%s\n", gnl.buffer);
	return (1);
}