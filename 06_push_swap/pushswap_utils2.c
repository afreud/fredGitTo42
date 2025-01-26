#include "pushswap.h"

char	**ft_clean2(char **strs)
{
	int	i;

	i = 0;
	if (strs)
	{
		while (strs[i])
		{
			free(strs[i]);
			strs[i] = NULL;
			i++;
		}
		free(strs);
	}
	return (NULL);
}

char	***ft_clean3(char ***s)	
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			s[i] = ft_clean2(s[i]);
			i++;
		}
		free(s);
	}
	return (NULL);
}

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
	int	j;
	int	n;

	i = 0;
	n = 0;
	if (s)
	{
		while (s[i])
		{
			j = 0;
			while (s[i][j])
			{
				n++;
				j++;
			}
			i++;
		}
	}
	return (n);
}
