#include <unistd.h>

int ft_atoi(char *s)
{
	int n = 0, i = 0, sign = 1;
	if (s[0] == '-')
	{
		sign = -1;
		s++;
	}
	else if (s[0] == '+')
		s++;
	while (s[i])
	{
		n *= 10;
		n += s[i] - 48;
		i++;
	}
	n *= sign;
	return (n);
}

void ft_putnbr(int n)
{
	char c;
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + 48;
	write(1, &c, 1);
}

int	ft_isprime(int n)
{
	int i = 2;

	if (n < i)
		return (0);
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int n = ft_atoi(argv[1]);
	int i = 1;
	int sum = 0;

	if (argc != 2 || n < 0)
		write(1, "0", 1);
	else if (argc == 2)
	{
		while (i <= n)
		{
			if (ft_isprime(i))
				sum += i;
			i++;
		}
		ft_putnbr(sum);
	}
	write(1, "\n", 1);
	return (0);
}
