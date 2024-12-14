/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:08:16 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/12 11:43:21 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*s_copy;
	char	c_copy;

	i = 0;
	s_copy = (char *)s;
	c_copy = (char)c;
	while (i < n)
	{
		s_copy[i] = c_copy;
		i++;
	}
	return (s);
}
