/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:28:33 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/18 20:20:48 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// 1 : Une ligne a été lue
// 0 : La lecture est terminée
// -1 : Une erreur est survenue

static int		ft_getline(t_buff *gnl, char **line)
{
	int		j;
	char	*tmp;
	int		offset;

	j = 0;
	tmp = NULL;
	offset = gnl->i;
	while (gnl->buffer[gnl->i] != '\n' && gnl->buffer[gnl->i] != '\0')
		gnl->i++;
	if (gnl->buffer[gnl->i] != '\n')
		return (0);
	if ((tmp = ft_calloc(gnl->i + 1, sizeof(char))) == NULL)
		return (-1);
	while (j + offset < gnl->i)
	{
		tmp[j] = gnl->buffer[j + offset];
		j++;
	}
	if (gnl->buffer[gnl->i] == '\0')
	{
		free(gnl->buffer);
		gnl->i = 0;
	}
	else
		gnl->i++;
	*line = tmp;
	return (1);	
}

static int		ft_linecat(t_buff *gnl, char **line, int fd, int size)
{
	char	*tmp;

	tmp = NULL;
	if ((tmp = ft_calloc(size + 1, sizeof(char))) == NULL)
		return (-1);
	while ((size = read(fd, gnl->buffer, BUFFER_SIZE)) > 0)
	{
		
	}
}

int				get_next_line(int fd, char **line)
{
	int				size;
	char 			*tmp;
	static t_buff	gnl;
	
	tmp = NULL;
	if (!gnl.buffer)
	{
		if ((gnl.buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char))) == NULL)
			return (-1);
		if ((size = read(fd, gnl.buffer, BUFFER_SIZE)) == 0)
			return (0);
		else if (size == -1)
			return (-1);
	}
	if ((ft_getline(&gnl, &tmp)) == 0)
		printf("buffer trop petit\n");
	else if (tmp == NULL)
		return (-1);
	*line = tmp;
	return (1);
}