/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 07:55:43 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/14 17:14:48 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_test(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 2147483647)
		write(fd, "2147483647", 10);
	else if (n == 0)
		write(fd, "0", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buff[20];
	int		i;

	i = 0;
	if (n == -2147483648 || n == 2147483647 || n == 0)
		ft_test(n, fd);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		while (n)
		{
			buff[i++] = (n % 10) + 48;
			n /= 10;
		}
		i--;
		while (i != -1)
			write(fd, &buff[i--], 1);
	}
}
