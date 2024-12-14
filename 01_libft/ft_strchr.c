/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 05:55:23 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/12 11:44:47 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*r;
	unsigned char	cc;

	i = 0;
	r = (char *)s;
	cc = (unsigned char) c;
	while (r[i] != '\0')
	{
		if (r[i] == cc)
			return (&r[i]);
		i++;
	}
	if (cc == '\0')
		return (&r[i]);
	else
		return (NULL);
}
