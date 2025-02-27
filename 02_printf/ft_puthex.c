/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:13:46 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/23 09:51:26 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int n)
{
	int	c;

	c = 0;
	while (n)
	{
		n /= 16;
		c++;
	}
	return (c);
}

ssize_t	ft_puthex(unsigned int hexa, char c)
{
	int		i;
	char	buff[12];
	char	*base;

	if (hexa == 0)
		return (write(1, "0", 1));
	if (c == 'x')
		base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	i = ft_hexlen(hexa);
	buff[i--] = '\0';
	while (hexa)
	{
		buff[i--] = base[hexa % 16];
		hexa /= 16;
	}
	return (write(1, buff, ft_strlen(buff)));
}
