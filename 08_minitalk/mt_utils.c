/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:55:15 by frdurand          #+#    #+#             */
/*   Updated: 2025/02/20 13:57:48 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

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

char	*ft_realloc(char *s, int l)
{
	char		*temp;
	static int	n = 1;

	if (!s)
	{
		s = ft_calloc((SIZE * n), sizeof(char));
		return (s);
	}
	if ((l + 2) == (SIZE * n))
	{
		temp = ft_calloc((l + 1), sizeof(char));
		if (!temp)
		{
			free(s);
			return (NULL);
		}
		ft_strlcpy(temp, s, l + 1);
		free(s);
		s = ft_calloc((SIZE * ++n), sizeof(char));
		if (s)
			ft_strlcpy(s, temp, l + 1);
		free(temp);
		temp = NULL;
	}
	return (s);
}
