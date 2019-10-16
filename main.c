#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fd;
	char *line;

	fd = open("file.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);
	close(fd);

	return (0);
}	