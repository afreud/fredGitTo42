/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:10:34 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/21 11:10:54 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

ssize_t	ft_putadr(void *adr)
{
	if (!adr)
		return (write(1, "NULL", 4));
	if (write(1, "0x", 2) < 0)
		return (-1);
	return (ft_puthex((unsigned int)(uintptr_t)adr, 'x') + 2);
}
