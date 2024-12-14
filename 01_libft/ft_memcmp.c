/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:58:23 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/12 11:42:46 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s1_copy;
	char	*s2_copy;

	i = 0;
	if (n <= 0)
		return (0);
	s1_copy = (char *)s1;
	s2_copy = (char *)s2;
	while (i < n)
	{
		if (s1_copy[i] != s2_copy[i])
			return ((int)(unsigned char)s1_copy[i]
					- (int)(unsigned char)s2_copy[i]);
		i++;
	}
	return (0);
}
