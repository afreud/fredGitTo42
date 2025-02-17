
#include "mt.h"

static int	ft_not_digit(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[i])
		return (1);
	while (s[i])
	{
			if ((s[i] < '0' || s[i] > '9') && s[i] != '+' && s[i] != '-')
				return (1);
			else if ((s[i] == '-' || s[i] == '+')
					&& ((s[i + 1] < '0' || s[i + 1] > '9')
					|| (i && s[i - 1] > 32)))
				return (1);
		i++;
	}
	return (0);
}

static int	ft_atoi_error(char *s)
{
	int	i;
	int	nb;
	int	pos;

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

int	ft_args_ok(char *arg)
{
	if (ft_not_digit(arg))
		return (0);
	if (ft_atoi_error(arg))
		return (0);
	return (1);
}
