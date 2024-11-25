
#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int		i;
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		return (42);
	i = 1;
	line = NULL;
	while (line = get_next_line(fd), line)
	{
		printf("[%d]: %s", i, line);
		free(line);
		line = NULL;
		i++;
	}
	close(fd);
	return (0);
}
