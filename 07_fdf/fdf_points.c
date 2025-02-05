#include "fdf.h"

int ft_ppl(char **s)
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

int ft_nbpts(char ***s)
{
	int	i;
	int l;

	i = 0;
	l = 0;
	if (s)
	{
		while (s[i])
		{
			l += ft_ppl(s[i]);
			i++;
		}
	}
	printf("Totpts: %d\n", l);
	return (l);
}

int	**ft_talloc(char ***pts, int n)
{
	int	i;
	int	l;
	int **tab;

	if (!pts)
		return (NULL);
	i = 0;
	l = ft_nbpts(pts);
	tab = (int **)malloc(sizeof(int *) * (l + 1));
	if (tab)
	{
		while (i < l)
		{
			tab[i] = (int *)malloc(sizeof(int) * n);
			if (!tab[i])
			{
				ft_clrtab(t3d);
				return (NULL);
			}
			i++;
		}
	}
	return (tab);
}

int	**ft_3d_points(char ***pts)
{
	int	**t3d;
	int i;
	int	j;
	int n;

	i = 0;
	n = 0;
	t3d = ft_talloc(pts, 3);
	if (!t3d)
		return (NULL);
	while (pts[i])
	{
		j = 0;
		while (pts[i][j])
		{
			t3d[n][0] = j * 10;
			t3d[n][1] = i * 10;
			t3d[n][2] = ft_atoi(pts[i][j]) * 10;
			j++;
			n++;
		}
		i++;		
	}
	t3d[n] = NULL;
	return (t3d);
}

int **ft_2d_points(char ***pts)
{
	int	**t2d;
	int	**t3d;
	int	i;

	i = 0;
	t3d = ft_3d_points(pts);
	if (!t3d)
		return (NULL);
	t2d = ft_talloc(pts, 2);
	if (t2d)
	{
		while (t3d[i])
		{
			t2d[i][0] = t3d[i][0] * cos(ANGL + 2) + t3d[i][1] * cos(ANGL)
				+ t3d[i][2] * cos(ANGL - 2);
			t2d[i][1] = t3d[i][0] * sin(ANGL + 2) + t3d[i][1] * sin(ANGL)
				+ t3d[i][2] * sin(ANGL - 2);
			i++;
		}
		t2d[i] = NULL;
		ft_clrtab(t3d);
	}
	return (t2d);
}
