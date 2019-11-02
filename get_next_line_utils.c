/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:36:00 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/31 15:52:31 by lucocozz         ###   ########.fr       */
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
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*strnew;
	int		len_s1;
	int		len_s2;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (s1[0] == '\0' && s2[0] == '\0')
		return (ft_strdup(""));
	if (!(strnew = malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_bzero(strnew, len_s1 + len_s2 + 1);
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

char			*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
