/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:14:25 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/22 11:04:10 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static ssize_t	ft_testnbr(int n)
{
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n == 2147483647)
		return (write(1, "2147483647", 10));
	else if (n == 0)
		return (write(1, "0", 1));
	else
		return (-1);
}

ssize_t	ft_putnbr(int n)
{
	char	buff[12];
	int		i;

	if (n == -2147483648 || n == 2147483647 || n == 0)
		return (ft_testnbr(n));
	else
	{
		i = ft_nblen(n);
		buff[i--] = '\0';
		if (n < 0)
		{
			buff[0] = '-';
			n = -n;
		}
		while (n)
		{
			buff[i--] = (n % 10) + 48;
			n /= 10;
		}
		return (write(1, buff, ft_strlen(buff)));
	}
}
