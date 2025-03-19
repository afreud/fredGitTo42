
static int	ft_cmppath(char *str, char *s)
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

char	**ft_getenv(char *path)
{
	extern char	**environ;
	char		**var;
	char		**env;
	int			i;

	i = 0;
	var = NULL;
	env = environ;
	while (env[i] && path)
	{
		if (ft_cmppath(env[i], path))
		{
			ft_rho(env[i], path);
			var = ft_msplit(env[i], ':');
			return (var);
		}
		i++;
	}
	return (var);
}
