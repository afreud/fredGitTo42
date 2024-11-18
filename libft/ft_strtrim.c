/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:19:10 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/13 15:53:28 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s1[i] && k == 0)
	{
		k = 1;
		while (set[j])
		{
			if (s1[i] == set[j])
				k = 0;
			j++;
		}
		i++;
		j = 0;
	}
	return (i -1);
}

static int	ft_end(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	k;

	i = ft_strlen(s1) - 1;
	j = 0;
	k = 0;
	while (i > 0 && k == 0)
	{
		k = 1;
		while (set[j])
		{
			if (s1[i] == set[j])
				k = 0;
			j++;
		}
		i--;
		j = 0;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*d;
	int		start;
	int		end;
	int		i;

	i = 0;
	d = NULL;
	if (set == NULL || s1 == NULL)
		return (NULL);
	if (!*s1)
		return (d = ft_strdup(""));
	else if (!*set)
		return (d = ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start > end)
		return (d = ft_strdup(""));
	d = malloc(sizeof(char) * (end - start + 2));
	if (d)
	{
		while (start <= end)
			d[i++] = s1[start++];
		d[i] = '\0';
	}
	return (d);
}
