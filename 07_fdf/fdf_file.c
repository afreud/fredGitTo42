
#include "fdf.h"

bool	ft_atoi_error(char *s)
{
	int		i;
	int		nb;
	bool	pos;

	i = 0;
	nb = 0;
	pos = 1;
	while ((s[i] > 8 && s[i] < 14) || s[i] == 32)
		i++;
	if (s[i] == '-')
		pos = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		if (pos && ((s[i] - 48) > INT_MAX - (nb * 10)))
			return (1);
		if (!pos && ((48 - s[i]) < (INT_MIN) + (nb * 10)))
			return (1);
		nb *= 10;
		nb += s[i++] - 48;
	}
	return (0);
}

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
		c = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nbr *= 10;
		nbr += (nptr[i++] - 48) % 10;
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
	width = 0;
	width_temp = 0;
	if (spts && spts[i])
		width_temp = ft_len2(spts[i++]);
	while (spts && spts[i])
	{
		width = ft_len2(spts[i++]);
		if (width != width_temp)
			return (0);
	}
	return (width);
}

char	***ft_spts(char *path, int i, t_xdata *xdata)
{
	int		fd;
	char	*line;
	char	***pts;

	pts = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (ft_height(fd, path))
		pts = malloc(sizeof(char **) * (ft_height(fd, path) + 2));
	if (pts)
	{
		line = get_next_line(fd);
		while (line)
		{
			pts[i] = ft_split(line, ' ');
			if (!pts[i++])
				ft_clrexit(&pts, fd, line, xdata);
			free(line);
			line = get_next_line(fd);
		}
		pts[i] = NULL;
	}
	close(fd);
	return (pts);
}
