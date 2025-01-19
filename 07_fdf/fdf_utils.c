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

void	ft_clrtab(int **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab[i]);
		tab[i] = NULL;
		free(tab);
	}
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
