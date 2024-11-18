/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:57:50 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/13 14:12:01 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	if (dest == NULL && src == NULL)
		return (NULL);
	s = (char *)src;
	d = (char *)dest;
	if (dest <= src)
	{
		while (n--)
			*d++ = *s++;
	}
	else if (dest > src)
	{
		d = d + n - 1;
		s = s + n - 1;
		while (n--)
			*d-- = *s--;
	}
	return (&dest[0]);
}
