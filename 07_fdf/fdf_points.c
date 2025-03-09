#include "fdf.h"

static int	ft_ppl(char **s)
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

static int	ft_nbpts(char ***s)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	if (s)
	{
		while (s[i])
			l += ft_ppl(s[i++]);
	}
	return (l);
}

long	**ft_talloc(char ***pts, int n)
{
	int		i;
	int		l;
	long	**tab;

	if (!pts)
		return (NULL);
	i = 0;
	l = ft_nbpts(pts);
	tab = (long **)malloc(sizeof(long *) * (l + 1));
	if (tab)
	{
		while (i < l)
		{
			tab[i] = (long *)malloc(sizeof(long) * n);
			if (!tab[i])
			{
				ft_clrtab(tab);
				return (NULL);
			}
			i++;
		}
	}
	tab[l] = NULL;
	return (tab);
}

long	**ft_3d_points(char ***pts)
{
	long	**t3d;
	int		i;
	int		j;
	int		n;

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
			t3d[n][0] = j * 100;
			t3d[n][1] = i * 100;
			if (ft_atoi_error(pts[i][j]))
				return (NULL);
			t3d[n++][2] = ft_atoi(pts[i][j++]) * 100;
		}
		i++;
	}
	t3d[n] = NULL;
	return (t3d);
}

long	**ft_2d_points(char ***spts, long **t3d)
{
	long	**t2d;
	int		i;

	i = 0;
	t2d = ft_talloc(spts, 2);
	if (t2d)
	{
		while (t3d[i])
		{
			t2d[i][0] = (t3d[i][0] - t3d[i][1]) * cos(0.523599);
			t2d[i][1] = (t3d[i][0] + t3d[i][1]) * sin(0.523599) - t3d[i][2];
			i++;
		}
		t2d[i] = NULL;
	}
	return (t2d);
}
