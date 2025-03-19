#include <unistd.h>

int	ft_atoi(char *s)
{
	int n = 0, i = 0;

	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		n *= 10;
		n += s[i] - 48;
		i++;
	}
	return (n);
}

void ft_put_hex(int n, char *base)
{
	char c;
	if (n >= 16)
		ft_put_hex(n / 16, base);
	c = base[n % 16];
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int n = ft_atoi(argv[1]);
		char *base = "0123456789abcdef";

		if (n != 0 || argv[1][0] == '0')
			ft_put_hex(n, base);
	}
	write(1, "\n", 1);
	return (0);
}
