/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:56:40 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/13 14:19:54 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*cptr;
	size_t		i;

	i = 0;
	cptr = (char *)malloc(nmemb * size);
	if (!cptr)
		return (NULL);
	while (i <= (nmemb * size))
	{
		cptr[i] = '\0';
		i++;
	}
	return (cptr);
}
