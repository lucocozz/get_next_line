/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:28:33 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/20 23:38:33 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// 1 : Une ligne a été lue
// 0 : La lecture est terminée
// -1 : Une erreur est survenue

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;

	i = 0;
	if ((substr = ft_calloc(len + 1, sizeof(char))) == NULL)
		return (NULL);
	if (start < ft_strlen(s))
		while (i < len && s[start + i])
		{
			substr[i] = s[start + i];
			i++;
		}
	substr[i] = '\0';
	return (substr);
}

static char		*ft_getline(char **buffer, int size)
{
	int		i;
	char	*tmp;
	char	*line;

	tmp = *buffer;
	i = ft_strchr(tmp, '\n');
	line = ft_substr(tmp, 0, i);
	if (i + 1 < size)
		*buffer = ft_substr(tmp, i + 1, size);
	else
		*buffer = NULL;
	free(tmp);
	return (line);
}

static int		ft_getbuff(char	**buffer)
{
	char	tmp_read[BUFFER_SIZE + 1];
	char	*tmp_buff;

	tmp_buff = *buffer;

}

int				get_next_line(int fd, char **line)
{
	int			i;
	int			size;
	static char	*buffer;
	char		tmp[BUFFER_SIZE + 1];

	if (!buffer)
		if ((size = read(fd, tmp, BUFFER_SIZE)) == -1)
			return (-1);
		else if (size == 0)
			return (0);
	buffer = ft_strdup(tmp);
	if ((i = ft_strchr(buffer, '\n')) == -1)
		size = ft_getbuff(*buffer);
	*line = ft_getline(&buffer, size);
	return (1);
}