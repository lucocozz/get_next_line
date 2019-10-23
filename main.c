/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:46:53 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/23 20:54:24 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	line = NULL;
	fd = open("file.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("line[%d]=%s\n", i, line);
		if (line)
			free(line);
		line = NULL;
		i++;
	}
	close(fd);
	return (0);
}
