#include "pushswap.h"

static bool	ft_not_digit(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i][j])
		{
			if ((s[i][j] < '0' || s[i][j] > '9') && s[i][j] != '+'
					&& s[i][j] != '-')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static bool	ft_not_unique(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (!(ft_strcmp(s[i], s[j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static bool	ft_atoi_error(char *s)
{
	int		i;
	int		nb;
	bool	pos;

	i = 0;
	nb = 0;
	pos = 1;
	while (s[i] == ' ')
		i++;
	if (s[i] == '-')
		pos = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (pos && ((s[i] - 48) > INT_MAX - (nb * 10)))
			return (1);
		if (!pos && ((48 - s[i]) < (INT_MIN) + (nb * 10)))
			return (1);
		nb *= 10;
		nb += s[i++] - 48;
	}
	return (0);
}

static bool	ft_out_limits(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_atoi_error(s[i]))
			return (1);
		i++;
	}
	return (0);
}

bool	ft_args_ok(char **args)
{
	if (!args)
		return (0);
	if (ft_not_digit(args))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_not_unique(args))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_out_limits(args))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}
