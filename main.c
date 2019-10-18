#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fd;
	char *line;

	line = NULL;
	fd = open("file.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("line=%s", line);
	close(fd);

	return (0);
}	