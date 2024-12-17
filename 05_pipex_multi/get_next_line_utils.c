/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:46:21 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/27 09:46:33 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

ssize_t	ft_gllen(char *str, char c)
{
	ssize_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*str++ != c)
		i++;
	return (i);
}

char	ft_eol(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return ('\n');
		s++;
	}
	return ('\0');
}

void	ft_glcp(char *dest, char *src, char c)
{
	if (src)
	{
		while (*src != c)
			*dest++ = *src++;
	}
	*dest = '\0';
}

char	*ft_gljoin(char *s1, char *s2)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_gllen(s1, '\0') + ft_gllen(s2, '\0') + 1));
	if (str)
	{
		while (s1 && *s1)
			str[i++] = *s1++;
		while (s2 && *s2)
			str[i++] = *s2++;
		str[i] = '\0';
	}
	return (str);
}

void	ft_cutstash(char *stash)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stash[i] != ft_eol(stash))
		i++;
	if (stash[i] == '\n')
		i++;
	if (i < ft_gllen(stash, '\0'))
	{
		while (stash[i])
			stash[j++] = stash[i++];
	}
	stash[j] = '\0';
}
