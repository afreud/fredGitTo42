
#include "fdf.h"

int	ft_len2(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

int	ft_len3(char ***s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}


void	ft_clrexit(char ****s, int fd)
{
	if (*s)
	{
		*s = ft_clean3(*s);
	}
	if (fd >= 0)
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
}

static char	**ft_clean2(char **t)
{
	int	i;

	i = 0;
	if (t)
	{
		while (t && t[i])
		{
			free(t[i]);
			t[i++] = NULL;
		}
		free(t);
		t = NULL;
	}
	return (NULL);
}

char	***ft_clean3(char ***t)
{
	int	i;

	i = 0;
	if (t)
	{
		while (t[i])
		{
			t[i] = ft_clean2(t[i]);
			i++;
		}
		free(t);
		t = NULL;
	}
	return (NULL);
}

