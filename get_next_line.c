#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int c;
	int s;
	char *tmp;

	c = '0';
	s = 1;
	tmp = ft_strnew(1);
	while (ft_isprint(c) && s)
	{
		s = read(fd, &c, 1);
		if (s == -1)
			return -1;
		if (ft_isprint(c) && s)
		{
			tmp = ft_realloc(tmp, sizeof(tmp) + 1);
			tmp[ft_strlen(tmp)] = c;
		}
	}
	ft_strcpy(*line, tmp);
	if (c == '\n')
		return 1;
	else
		return 0;
}
