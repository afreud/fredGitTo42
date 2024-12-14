/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:10:34 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/23 09:55:36 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlenadr(uintptr_t n)
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

static ssize_t	ft_puthexadr(uintptr_t hexa)
{
	int		i;
	char	buff[30];
	char	*base;

	if (hexa == 0)
		return (write(1, "0", 1));
	base = "0123456789abcdef";
	i = ft_hexlenadr(hexa);
	buff[i--] = '\0';
	while (hexa)
	{
		buff[i--] = base[hexa % 16];
		hexa /= 16;
	}
	return (write(1, buff, ft_strlen(buff)));
}

ssize_t	ft_putadr(void *adr)
{
	if (!adr)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) < 0)
		return (-1);
	return (ft_puthexadr((uintptr_t)adr) + 2);
}
