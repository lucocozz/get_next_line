/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 03:55:32 by lucocozz          #+#    #+#             */
/*   Updated: 2022/06/12 17:35:25 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

typedef struct s_buffer
{
	int				size;
	int				end;
	int				start;
	char			buffer[BUFFER_SIZE + 1];
	struct s_buffer	*next;
	struct s_buffer	*prev;
}					t_buffer;

t_buffer	*create_link(void);
void		push_back(t_buffer **buffer, t_buffer *link, int read_size);
void		free_link(t_buffer **link);
void		ft_strncpy(char *dst, char *src, int len);
char		*get_next_line(int fd);

#endif
