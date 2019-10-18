/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:36:00 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/18 20:23:15 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char *tmp;

	if (!count || !size)
		return (NULL);
	if ((tmp = malloc(size * count)) == NULL)
		return (NULL);
	ft_memset(tmp, '\0', count);
	return ((void *)tmp);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (n-- > 0)
		*tmp++ = c;
	return (s);
}
