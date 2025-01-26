#include "pushswap.h"

static char	***ft_tab3(char **av)
{
	int	i;
	char ***t3;

	i = 0;
	t3 = malloc(sizeof(char **) * (ft_len2(av) + 1));
	if (t3)
	{
		while (av[i])
		{
			t3[i] = ft_split(av[i], ' ');
			if (!t3[i])
			{
				t3 = ft_clean3(t3);
				return (NULL);
			}
			i++;
		}
		t3[i] = NULL;
	}
	return (t3);
}

static char **ft_tab2(char ***t3)
{
	int		i;
	int		j;
	int		k;
	char	**t2;

	i = 0;
	k = 0;
	t2 = malloc(sizeof(char *) * (ft_len3(t3) + 1));
	if (t2)
	{
		while (t3[i])
		{
			j = 0;
			while (t3[i][j])
				t2[k++] = t3[i][j++];
			free(t3[i]);
			t3[i] = NULL;
			i++;
		}
		t2[k] = NULL;
		free(t3);
	}
	return (t2);
}

char	**ft_creatab(char **av)
{
	char	**t;
	char	***t3;

	t = NULL;
	t3 = NULL;
	t3 = ft_tab3(av);
	if (!t3)
		return (NULL);
	t = ft_tab2(t3);
	return (t);
}
