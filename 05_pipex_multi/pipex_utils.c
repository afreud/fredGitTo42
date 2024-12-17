
#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
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

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

void	ft_clean2(char **t)
{
	int	i;

	i = 0;
	if (t)
	{
		while ( t && t[i])
		{
			free(t[i]);
			t[i++] = NULL;
		}
		free(t);
		t = NULL;
	}
}

void ft_clean3(char ***t)
{
	int	i;

	i = 0;
	if (t)
	{
		while (t[i])
			ft_clean2(t[i++]);
		free(t);
		t = NULL;
	}
}
