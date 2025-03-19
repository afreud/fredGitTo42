#include <stdio.h>

int ft_cmp(char c, char *b1, char *b2)
{
	int	i = 0;

	while (b1[i])
	{
		if (b1[i] == c || b2[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	char *base1 = "0123456789abcdef";
	char *base2 = "0123456789ABCDEF";
	int i = 0, n, sign = 1;
	int res = 0;
	int mult = 1;

	if (str[0] == '-')
	{
		sign = -1;
		str++;
	}
	else if (str[0] == '+')
		str++;
	while (str[i])
	{
		res *= str_base;
		n = ft_cmp(str[i], base1, base2);
		res += n * mult;
		i++;
	}
	res *= sign;
	return (res);
}

int main()
{
	char *str = "-aa123";
	int base = 16;
	int res = ft_atoi_base(str, base);
	printf("%d\n", res);
	return (0);
}
