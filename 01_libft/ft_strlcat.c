/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:25:29 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/14 12:38:27 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (dst == NULL && size == 0)
		return (ft_strlen((char *)src));
	while (dst[i] != '\0')
		i++;
	len = i;
	if (size <= len)
		return (ft_strlen((char *)src) + size);
	if (size > len)
	{
		while (src[j] != '\0' && j < (size - len - 1))
			dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (len + ft_strlen((char *)src));
}
