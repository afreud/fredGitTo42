/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:17:35 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/22 13:54:16 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unbrlen(unsigned int n)
{
	int	c;

	c = 0;
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

ssize_t	ft_putunbr(unsigned int unbr)
{
	int		len;
	char	str[30];

	if (unbr == 0)
		return (write(1, "0", 1));
	len = ft_unbrlen(unbr);
	str[len--] = '\0';
	while (unbr)
	{
		str[len--] = (unbr % 10) + 48;
		unbr /= 10;
	}
	return (write(1, str, ft_strlen(str)));
}
