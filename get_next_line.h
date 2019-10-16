/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:35:57 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/16 21:39:11 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_buff
{
	char		*buffer;
	int			i;
}				t_buff;

int				get_next_line(int fd, char **line);
void			*ft_calloc(size_t count, size_t size);

#endif