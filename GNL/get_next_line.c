
#include "get_next_line.h"

static ssize_t	ft_read_file(int fd, char *buff)
{
	ssize_t	count;
	int	i;

	i = BUFFER_SIZE;
	while (i >= 0)
		buff[i--] = '\0';
	count = read(fd, buff, BUFFER_SIZE);
	return (count);
}

static char	*ft_tostash(char *stash, char *buff)
{
	char	temp[ft_gllen(stash, '\0') + 1];

	temp[0] = '\0';
	if (*buff == '\0')
		return (stash);
	if (stash)
	{
		ft_glcp(temp, stash, '\0');
		free(stash);
	}
	return (ft_gljoin(temp, buff));
}

static char	*ft_toline(char *stash)
{
	char	*line;
	char	c[2];
	char	temp[ft_gllen(stash, ft_eol(stash)) + 1];

	c[0] = ft_eol(stash);
	c[1] = '\0';
	temp[0] = '\0';
	ft_glcp(temp, stash, ft_eol(stash));
	line = ft_gljoin(temp, c);
	if (!line)
		free(stash);
	else
		ft_cutstash(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	ssize_t		 i;
	char		buff[BUFFER_SIZE + 1];
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		return (NULL);
	}
	line = NULL;
	i = ft_read_file(fd, buff);
	if (i < 0 || (i == 0 && *stash == '\0')) 
	{
		free(stash);
		return (NULL);
	}
	stash = ft_tostash(stash, buff);
	if (stash)
		line = ft_toline(stash);
	return (line);
}