/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:42:53 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/12 11:42:33 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_copy;
	unsigned char	c_copy;
	size_t			i;

	s_copy = (unsigned char *)s;
	c_copy = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_copy[i] == c_copy)
			return ((unsigned char *)&s_copy[i]);
		i++;
	}
	return (NULL);
}
