#include <unistd.h>
#include <stdarg.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

static int	ft_nblen(int n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		c++;
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

void	ft_wr_nbr(int nbr, char *base, int len, ssize_t *i)
{
	ssize_t	c;
	int		rest;
	char	str[11];
	int 	nlen;

	nlen = ft_nblen(nbr);
	str[nlen + 1] = '\0';
	while (nbr > 0)
	{
		rest = nbr % len;
		str[nlen--] = base[rest];
		nbr = nbr / len;
	}
	c = write(1, str, ft_strlen(str));
	if (c >= 0)
		*i += c;
	else
		*i = -42;
}

static ssize_t	ft_putnbrf_base(int nbr, char *base)
{
	ssize_t	i;
	int nbr;

	i = 0;
	if (!nbr)
		return (-42);
	if (nbr < 0)
	{
		i += write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr == 0)
		i = write(1, base, 1);
	else
		ft_wr_nbr(nbr, base, ft_strlen(base), &i);
	if (i >= 0)
		return (i);
	else
		return (-42);
}

void	ft_putarg(const char *str, va_list pls, ssize_t *count)
{
	if (*str == 'c')
		return (ft_putchar(va_arg(pls, int)));
	else if (*str == 's')
		i = write(1, va_arg(pls, char *), ft_strlen((char *)arg));

	//else if (*str == 'p')
	//	i = ft_putadr((int *)(va_arg(pls, void *), "0123456789abcde");
	
	else if (*str == 'd' || *str == 'i')	
		i = ft_putnbrf_base(va_arg(pls, int), "0123456789");
	else if(*str == 'u')	
		i =ft_putnbrf_base((va_arg( pls, unsigned int), "0123456789");
	else if (*str == 'x')	
		i = ft_putnbrf_base(va_arg(pls, ssize_t)), "0123456789abcde");
	else if (*str == 'X')	
		i = ft_putnbrf_base(va_arg(pls, ssize_t), "0123456789ABCDEF");
	else if (*str == '%')	
		i = write(1, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	pls;
	ssize_t temp;
	ssize_t	count;

	count = 0;
	if (!str)
		return (0);
	va_start(pls, str);
	while (*str && count >= 0)
	{
		if (*str != '%')
		{
			temp = write(1, str, 1);
			if (temp >= 0)
				count += temp;
			else
				count = -42;
		}
		else if (*str++ == '%')
			ft_putarg(str, pls, &count);
		str++;
	}
	va_end(pls);
	return ((int)count);
}

#include <stdio.h>


 int main()
{
	int	r;

	int		d = 1234;
	int		i = -1234;
	unsigned int u = 1;
	char	c = 'a';
	char	*s = "abcde";

	r = ft_printf("Me modulo : %%\n");
	printf("%d\n", r);
	r = printf("Org modulo : %%\n");
	printf("%d\n", r);

	r = ft_printf("Me s: %s\n", s);
	printf("%d\n", r);
	r = printf("Org s: %s\n", s);
	printf("%d\n", r);

	r = ft_printf("Me c: %c \n", c);
	printf("%d\n", r);
	r = printf("Org c: %c \n", c);
	printf("%d\n", r);



	r = ft_printf("Me d: %d\n", d);
	printf("%d\n", r);
	r = ft_printf("Me i: %i\n", i);
	printf("%d\n", r);
	r = ft_printf("Me u: %u\n", u);
	printf("%d\n", r);

	r = printf("Org d: %d\n", d);
	printf("%d\n", r);
	r = printf("Org i: %i\n", i);
	printf("%d\n", r);
	r = printf("Org u: %u\n", u);
	printf("%d\n", r);

	return (0);
}
