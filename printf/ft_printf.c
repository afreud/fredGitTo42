#include <unistd.h>
#include <stdarg.h>

void	ft_wrnbr(int arg, char *base, int len, int *i)
{
	int	c;

	c = 0;
	if (arg > 0 && *i >= 0)
	{
		c = arg % len;
		arg = arg /len;
		ft_wrnbr(arg, base, len, i);
		*i += write(1, &base[c], 1);
	}
}

int	ft_putnbrf_base(int arg, char *base)
{
	int	i;

	i = 0;
	if (!arg)
		return (-42);
	if (arg < 0)
	{
		i += write(1, "-", 1);
		arg *= -1;
	}
	if (arg == 0)
		i += write(1, base[0], 1);
	else
		i += ft_wrnbr(arg, base, ft_strlen(base), &i);
	return (i);
}

void	ft_putarg(char *str, void *arg, int *count)
{
	int	i;

	if (*str == 'c')
		i =	write(1, &(char)arg, 1);
	else if (*str == 's')
		i = write(1, (char *)arg, ft_strlen((char *)arg));
	else if (*str == 'p')
		i = ft_putnbrf_base((unsigned int)arg, "0123456789abcde");
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
	int	count;

	count = 0;
	if (!str)
		return (0);
	va_start(pls, str);
	while (*str && count >= 0)
	{
		if (*str != '%')
			count += write(1, str, 1);
		else if (*str++ == '%')
			ft_putarg(str, va_arg(pls, void *), &count);
		str++;
	}
	va_end(pls);
	return (count);
}
