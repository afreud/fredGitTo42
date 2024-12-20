/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:51:25 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/14 14:45:49 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*s_copy;
	size_t	i;

	s_copy = (char *)s;
	i = 0;
	while (i < n)
	{
		s_copy[i] = '\0';
		i++;
	}
}
