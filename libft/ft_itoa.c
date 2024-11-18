/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:39:04 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/12 11:40:56 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
