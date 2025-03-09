#include "fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_clrtab(long **tab)
{
	int	i;

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

int	ft_colo(int z)
{
	z /= 100;
	if (z <= -3)
		return (0X000000FF);
	else if (z > -3 && z < 0)
		return (0x0000FF00);
	else if (z == 0)
		return (0X0000FF00);
	else if (z > 0 && z <= 2)
		return (0X00E7FF00);
	else if (z > 2 && z <= 5)
		return (0X00FF6C00);
	else if (z > 5 && z <= 7)
		return (0X00FF0000);
	else if (z > 7 && z <= 10)
		return (0X00FF0000);
	else if (z > 10 && z <= 50)
		return (0X00FF00FF);
	else
		return (0X00B150FF);
}

void	ft_chek_name(char *s, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		exit(EXIT_FAILURE);
	while (s[i])
		i++;
	if (i < 5 || s[i - 1] != 'f' || s[i - 2] != 'd'
		|| s[i - 3] != 'f' || s[i - 4] != '.')
	{
		perror("Bad file");
		exit(EXIT_FAILURE);
	}
	(*map).name = malloc(sizeof(char) * (i + 1));
	if (!(*map).name)
		exit(errno);
	while (*s)
		(*map).name[j++] = *s++;
	(*map).name[j] = '\0';
}
