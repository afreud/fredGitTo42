/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:11:42 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/21 11:11:47 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putarg(const char *str, va_list pls, ssize_t *count)
{
	ssize_t	i;

	i = -1;
	if (*str == 'c')
		i = ft_putchar(va_arg(pls, int));
	else if (*str == 's')
		i = ft_putstr(va_arg(pls, char *));
	else if (*str == 'p')
		i = ft_putadr(va_arg(pls, void *));
	else if (*str == 'd' || *str == 'i')
		i = ft_putnbr(va_arg(pls, int));
	else if (*str == 'u')
		i = ft_putunbr(va_arg(pls, unsigned int));
	else if (*str == 'x')
		i = ft_puthex(va_arg(pls, unsigned int), 'x');
	else if (*str == 'X')
		i = ft_puthex(va_arg(pls, unsigned int), 'X');
	else if (*str == '%')
		i = write(1, "%", 1);
	if (i >= 0)
		*count += i;
	else
		*count = -1;
}

int	ft_printf(const char *str, ...)
{
	va_list	pls;
	ssize_t	temp;
	ssize_t	count;

	count = 0;
	if (!str)
		return (-1);
	va_start(pls, str);
	while (*str && count >= 0)
	{
		if (*str != '%')
		{
			temp = write(1, str, 1);
			if (temp >= 0)
				count += temp;
			else
				count = -1;
		}
		else if (*str++ == '%')
			ft_putarg(str, pls, &count);
		str++;
	}
	va_end(pls);
	return ((int)count);
}
