
#include "fdf.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nbr;
	int	c;

	i = 0;
	nbr = 0;
	c = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		c = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nbr *= 10;
		nbr += (nptr[i] - 48) % 10;
		i++;
	}
	return (nbr * c);
}

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

int	ft_width(char ***spts)
{
	int	width;
	int	width_temp;
	int	i;

	i = 0;
	width_temp = ft_len2(spts[i++]);
	while (spts[i])
	{
		width = ft_len2(spts[i++]);
		if (width != width_temp)
			return (0);
	}
	return (width);
}

char	***ft_spts(char *path)
{
	int		i;
	int		fd;
	char	*line;
	char	***pts;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	pts = malloc(sizeof(char **) * (ft_height(fd, path) + 1));
	if (!pts)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		pts[i] = ft_split(line, ' ');
		if (!pts[i++])
		{
			free(line);
			ft_clrexit(&pts, fd);
		}
		free(line);
		line = get_next_line(fd);
	}
	pts[i] = NULL;
	close(fd);
	return (pts);
}

