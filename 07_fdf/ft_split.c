#include "fdf.h"

static int	ft_len(const char *str, char c)
{
	int	sum;

	sum = 0;
	while (*str == c)
		str++;
	while (*str != c && *str != '\0' && *str != '\n')
	{
		sum++;
		str++;
	}
	return (sum);
}

static int	ft_wc(const char *str, char c)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] != c && str[i + 1] == c)
			sum++;
		else if (str[i] != c && (str[i + 1] == '\0' || str[i + 1] == '\n'))
			sum++;
		i++;
	}
	return (sum);
}

static char	**ft_clear_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		strs[i++] = NULL;
	}
	free(strs);
	return (NULL);
}

static char	*ft_fillstr(const char *s, char c, char **strs)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_len(s, c) + 1));
	if (dest == NULL)
	{
		strs = ft_clear_strs(strs);
		return (NULL);
	}
	while (*s != c && *s != '\0' && *s != '\n')
		dest[i++] = *s++;
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		t;
	char	**strs;

	i = 0;
	t = 1;
	if (!s)
		return (NULL);
	strs = malloc(sizeof(char *) * (ft_wc(s, c) + 1));
	if (!strs)
		return (NULL);
	while (*s)
	{
		if (*s != c && t == 1)
		{
			strs[i] = ft_fillstr(s, c, strs);
			if (strs[i++] == NULL)
				return (NULL);
			t = 0;
		}
		if (*s++ != c && *s == c)
			t = 1;
	}
	strs[i] = NULL;
	return (strs);
}
