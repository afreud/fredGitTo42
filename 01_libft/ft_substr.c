/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 07:52:39 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/13 14:55:38 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	size_t			i;
	unsigned int	slen;

	i = 0;
	slen = ft_strlen(s);
	if (slen < start)
	{
		dest = malloc(sizeof(char) * 1);
		if (dest)
			*dest = '\0';
		return (dest);
	}
	if ((len) > (slen - start))
		dest = malloc(sizeof(char) * ((slen - start) + 1));
	else
		dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (dest);
	while (start--)
		s++;
	while (i < len && *s != '\0')
		dest[i++] = *s++;
	dest[i] = '\0';
	return (dest);
}
