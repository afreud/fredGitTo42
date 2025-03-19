
int	ft_abs(int a)
{
	int	b;

	b = a >> 31;
	return ((a ^ b) - b);
}

int	ft_multi(int a, int b)
{
	bool	sign;
	int		res;

	sign = 0;
	res = 0;
	if ((a < 0) ^ (b < 0))
		sign = 1;
	ft_abs(a);
	ft_abs(b);
	while (b)
	{
		if (b & 1)
			res += a;
		a <<= 1;
		b >>= 1;
	}
	if (sign)
		return (-res);
	return (res);
}

int ft_div(int a, int b)
{
	bool		sign;
	int			i;
	long long	q;

	if (a == INT_MIN && b == -1)
		return (INT_MAX);
	a = (long long)ft_abs(a);
	b = (long long)ft_abs(b);
	sign = 0;
	q = 0;
	i = 31;
	if ((a < 0) ^ (b < 0))
		sign = 1;
	while (i >= 0)
	{
		if ((b << i) <= a)
		{
			a -= (b << i);
			q |= (1LL << i)
		}
		i--;
	}
	if (sign)
		return (-(int)q);
	return ((int)q);
}

void	ft_swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

char	*ft_tolower(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] >= 'A' && s[i] <= 'Z')
		s[i++] |= 32;
	return (s);
}

char *ft_toupper(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] >= 'a' && s[i] <= 'z')
		s[i++] &= ~32;
	return (s);
}

int	ft_min(int a, int b)
{
	return (b ^ ((a ^ b) & -(a < b)));
}

int	ft_max(int a, int b)
{
	return (b ^ ((a ^ b) & -(a > b)));
}
