/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:46:53 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/30 22:53:35 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int	main(int ac, char **av)
{
	int		i;
	int		fd;
	int		ret;
	char	*line;

	i = 0;
	line = NULL;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("[%d][%d]=%s\n", ret, i, line);
		if (line)
			free(line);
		line = NULL;
		i++;
	}
	printf("[%d][end]=%s\n", ret, line);
	close(fd);
	// system("leaks a.out");
	return (0);
}
