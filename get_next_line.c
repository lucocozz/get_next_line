/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:28:33 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/30 22:25:51 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_swap(void **pt1, void **pt2)
{
	void	*swap;

	swap = *pt1;
	*pt1 = *pt2;
	*pt2 = swap;
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;

	i = 0;
	if ((substr = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ft_bzero(substr, len + 1);
	if (start < ft_strlen(s))
		while (i < len && s[start + i])
		{
			substr[i] = s[start + i];
			i++;
		}
	substr[i] = '\0';
	return (substr);
}

static char		*ft_getline(char **buffer, int size, int *ret)
{
	int		i;
	char	*tmp;
	char	*line;

	tmp = *buffer;
	i = ft_strchr(tmp, '\n');
	*ret = (i == -1 ? 0 : 1);
	i = (i == -1 ? size : i);
	line = ft_substr(tmp, 0, i);
	if (i + 1 < size)
		*buffer = ft_substr(tmp, i + 1, size);
	else
		*buffer = NULL;
	free(tmp);
	return (line);
}

static int		ft_getbuff(char **buffer, int fd)
{
	int		chr;
	int		size;
	char	*tmp_cat;
	char	*tmp_buff;
	char	tmp_read[BUFFER_SIZE + 1];

	tmp_buff = *buffer;
	while (1)
	{
		ft_bzero(tmp_read, BUFFER_SIZE + 1);
		if ((size = read(fd, tmp_read, BUFFER_SIZE)) <= 0)
			return (size);
		tmp_cat = ft_strjoin(tmp_buff, tmp_read);
		free(tmp_buff);
		tmp_buff = NULL;
		ft_swap((void **)&tmp_cat, (void **)&tmp_buff);
		chr = ft_strchr(tmp_read, '\n');
		if (chr > -1 || (chr == -1 && size < BUFFER_SIZE))
			break ;
	}
	*buffer = tmp_buff;
	return (ft_strlen(tmp_buff));
}

int				get_next_line(int fd, char **line)
{
	int			i;
	int			ret;
	int			size;
	static char	*buffer;
	char		tmp[BUFFER_SIZE + 1];

	ft_bzero(tmp, BUFFER_SIZE + 1);
	if (!buffer)
	{
		if ((size = read(fd, tmp, BUFFER_SIZE)) <= 0)
			return (size);
		buffer = ft_strdup(tmp);
	}
	if ((i = ft_strchr(buffer, '\n')) == -1)
	{
		if ((size = ft_getbuff(&buffer, fd)) <= 0)
		{
			if (buffer)
				free(buffer);
			return (size);
		}
	}
	*line = ft_getline(&buffer, size, &ret);
	return (ret);
}
