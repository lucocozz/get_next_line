/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:36:00 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/16 21:42:38 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	int i;
	unsigned char *tmp;

	i = 0;
	if (!count || !size)
		return (NULL);
	if ((tmp = malloc(size * count)) == NULL)
		return (NULL);
	while (i < count)
		tmp[i++] = 0;
	return ((void *)tmp);
}