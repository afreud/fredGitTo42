/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:56:40 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/22 12:44:19 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*cptr;
	size_t	max;

	max = -1;
	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (size != 0 && nmemb > max / size)
		return (NULL);
	cptr = malloc(nmemb * size);
	if (cptr)
		ft_bzero(cptr, nmemb * size);
	return (cptr);
}
