/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:36:00 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/20 21:00:20 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	i;
	unsigned char	*tmp;

	i = 0;
	if (!count || !size)
		return (NULL);
	if ((tmp = malloc(size * count)) == NULL)
		return (NULL);
	while (i < count)
		tmp[i++] = 0;
	return ((void *)tmp);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_strchr(const char *s, int c)
{
	unsigned int i;

	i = 0;
	while (i < ft_strlen(s) + 1)
		if (s[i] == c)
			return (i);
		else
			i++;
	return (-1);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*strnew;

	i = 0;
	if ((strnew = (char *)ft_calloc(ft_strlen(s1) + 1, sizeof(char))) == NULL)
		return (NULL);
	while (s1[i])
	{
		strnew[i] = s1[i];
		i++;
	}
	strnew[i] = '\0';
	return (strnew);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*strnew;

	i = 0;
	j = 0;
	if (s1[0] == '\0' && s2[0] == '\0')
		return (ft_strdup(""));
	strnew = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2), sizeof(char));
	if (strnew == NULL)
		return (NULL);
	while (s1[i])
	{
		strnew[i] = s1[i];
		i++;
	}
	while (s2[j])
		strnew[i++] = s2[j++];
	strnew[i] = '\0';
	return (strnew);
}