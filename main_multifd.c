/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_multifd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:46:53 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/31 15:34:47 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/errno.h>

static int ft_fd_is_valid(int fd)
{
	if (fcntl(fd, F_GETFL) < 0 && errno == EBADF)
		return (0);
	return (1);
}

// static int	ft_check_valide_fds_list(int *fds_list, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		if (ft_fd_is_valid(fds_list[i]))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

int	main(int ac, char **av)
{
	int		fd;
	int		ret;
	int		fd_open;
	int		fds_list[ac];
	char	*line;

	fd = 0;
	fd_open = 1;
	line = NULL;
	if (ac < 2)
		return (0);
	while (fd + 1 < ac)
	{
		fds_list[fd] = open(av[fd + 1], O_RDONLY);
		fd++;
	}
	while (1)
	{
		if (fd + 1 == ac)
			fd = 0;
		if ((fd_open = ft_fd_is_valid(fds_list[fd])))
		{
			if ((ret = get_next_line(fds_list[fd], &line)) <= 0)
				close(fds_list[fd]);
			printf("[%d][%d]=%s\n", ret, fd, line);
			if (line)
				free(line);
			line = NULL;
		}
		fd++;
		if (fd_open == 0 && fd + 1 == ac)
			break ;
	}
	// system("leaks a.out");
	return (0);
}
