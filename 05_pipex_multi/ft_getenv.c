#include "pipex.h"

static int	ft_cmpath(char *str, char *s)
{
	int	i;

	i = 1;
	while (*s && i)
	{
		if (*str++ != *s++)
			i = 0;
	}
	if (i == 1 && *str != '=')
		i = 0;
	return (i);
}

static void	ft_rho(char *str, char *s)
{
	int	l;
	int	i;

	i = 0;
	l = ft_strlen(s) +1;
	while (str[l])
		str[i++] = str[l++];
	str[i] = '\0';
}

char	**ft_getenv(char *s)
{
	extern char	**environ;
	char		**var;
	char		**env;
	int			i;

	i = 0;
	var = NULL;
	env = environ;
	while (env[i] && s)
	{
		if (ft_cmpath(env[i], s))
		{
			ft_rho(env[i], s);
			var = ft_msplit(env[i], ':');
			return (var);
		}
		i++;
	}
	return (var);
}
