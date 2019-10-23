/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:36:00 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/23 16:55:27 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (n-- > 0)
		*tmp++ = '\0';
}

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int				ft_strchr(const char *s, int c)
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

char			*ft_strdup(const char *s1)
{
	int		i;
	char	*strnew;

	i = 0;
	if ((strnew = malloc(sizeof(char) * (ft_strlen(s1) + 1))) == NULL)
		return (NULL);
	ft_bzero(strnew, ft_strlen(s1));
	while (s1[i])
	{
		strnew[i] = s1[i];
		i++;
	}
	strnew[i] = '\0';
	return (strnew);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*strnew;

	i = 0;
	j = 0;
	if (s1[0] == '\0' && s2[0] == '\0')
		return (ft_strdup(""));
	if (!(strnew = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_bzero(strnew, ft_strlen(s1) + ft_strlen(s2));
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
