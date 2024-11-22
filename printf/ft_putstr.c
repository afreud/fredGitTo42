/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:15:08 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/22 14:32:03 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putstr(char *str)
{
	if (str)
		return (write(1, str, ft_strlen(str)));
	if (str == NULL)
		return (write(1, "(null)", 6));
	else
		return (-1);
}
