
#include "fdf.h"

int	ft_height(int fd, char *path)
{
	int		h;
	char	c;

	h = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n' || c == '\0')
			h++;
	}
	close(fd);
	fd = open(path, O_RDONLY);
	return (h);
}

char	***ft_init_pts(char *path)
{
	int		i;
	int		ht;
	int		fd;
	char	*line;
	char	***pts;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	ht = ft_height(fd, path);
	pts = malloc(sizeof(char **) * (ht + 1));
	if (!pts)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		pts[i] = ft_split(line, ' ');
		if (!pts[i++])
			ft_clrexit(&pts, fd);
		free(line);
		line = get_next_line(fd);
	}
	pts[i] = NULL;
	close(fd);
	return (pts);
}
