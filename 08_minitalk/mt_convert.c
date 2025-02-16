
#include "mt.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nbr;
	int	c;

	i = 0;
	nbr = 0;
	c = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		c = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nbr *= 10;
		nbr += (nptr[i] - 48);
		i++;
	}
	return (nbr * c);
}

int	ft_nblen(int n)
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

static void	ft_pmin(char *res)
{
	*res++ = '-';
	*res++ = '2';
	*res++ = '1';
	*res++ = '4';
	*res++ = '7';
	*res++ = '4';
	*res++ = '8';
	*res++ = '3';
	*res++ = '6';
	*res++ = '4';
	*res++ = '8';
}

char	*ft_itoa(int n)
{
	int		size;
	char	*res;

	size = ft_nblen(n);
	res = malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	else if (n == -2147483648)
		ft_pmin(res);
	else if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	res[size--] = '\0';
	while (n && n != -2147483648)
	{
		res[size--] = (n % 10) + 48;
		n /= 10;
	}
	return (res);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
	}
	if (size > 0 && dst[i] != '\0' && i < (size))
		dst[i] = '\0';
	return (ft_strlen((char *)src));
}

void	ft_bzero(void *s, size_t n)
{
	char	*s_copy;
	size_t	i;

	s_copy = (char *)s;
	i = 0;
	while (i < n)
	{
		s_copy[i] = '\0';
		i++;
	}
}
