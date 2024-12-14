/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:00:20 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/12 11:51:51 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*r;
	unsigned char	cc;

	i = 0;
	r = (char *)s;
	cc = (unsigned char)c;
	while (r[i] != '\0')
		i++;
	while (&r[i] != &r[0])
	{
		if (r[i] == cc)
			return (&r[i]);
		i--;
	}
	if (r[i] == cc)
		return (&r[i]);
	return (NULL);
}
