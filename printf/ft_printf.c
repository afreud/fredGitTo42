#include <unistd.h>
#include <stdarg.h>

void	ft_wrnbr(int nbr, char *base, int len, ssize_t *i)
{
	ssize_t	c;
	int rest;

	if (nbr > 0 && *i >= 0)
	{
		rest = nbr % len;
		nbr = nbr /len;
		ft_wrnbr(nbr, base, len, i);
		c = write(1, &base[rest], 1);
		if (c >= 0)
			*i += c;
	}
}

int	ft_putnbrf_base(int nbr, char *base)
{
	ssize_t	i;

	i = 0;
	if (!nbr)
		return (-42);
	if (nbr < 0)
	{
		i += write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr == 0)
		i += write(1, base[0], 1);
	else
		i += ft_wrnbr(nbr, base, ft_strlen(base), &i);
	return (i);
}

void	ft_putarg(char *str, void *arg, ssize_t *count)
{
	ssize_t	i;

	if (*str == 'c')
		i =	write(1, &(char)arg, 1);
	else if (*str == 's')
		i = write(1, (char *)arg, ft_strlen((char *)arg));
	else if (*str == 'p')

		i = ft_putnbrf_base((int)(unsigned int)&arg, "0123456789abcde");
	
	else if (*str == 'd')	
		i = ft_putnbrf_base((int)arg, "0123456789");
	else if (*str == 'i')	
		i = ft_putnbrf_base((int)arg, "0123456789");
	else if(*str == 'u')	
		i =ft_putnbrf_base((unsigned int)arg, "0123456789");
	else if (*str == 'x')	
		i = ft_putnbrf_base((unsigned int)arg, "0123456789abcde");
	else if (*str == 'X')	
		i = ft_putnbrf_base((unsigned int)arg, "0123456789ABCDEF");
	else if (*str == '%')	
		i = write(1, "%", 1);
	if (i >= 0)
		*count += i;
	else
		*count = -42;
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
			ft_putarg(str, va_arg(pls, void *), &count);
		str++;
	}
	va_end(pls);
	return ((int)count);
}
