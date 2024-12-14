/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:12:28 by frdurand          #+#    #+#             */
/*   Updated: 2024/11/14 16:26:01 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(const char *str, char c)
{
	int	sum;

	sum = 0;
	while (*str == c)
		str++;
	while (*str != c && *str != '\0')
	{
		sum++;
		str++;
	}
	return (sum);
}

static int	ft_wc(const char *str, char c)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (str[i] != '\0' )
	{
		if (str[i] != c && str[i + 1] == c)
			sum++;
		else if (str[i] != c && str[i + 1] == '\0' )
			sum++;
		i++;
	}
	return (sum);
}

static void	ft_clear_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

static char	*ft_putstr(const char *s, char c, char **strs)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_len(s, c) + 1));
	if (dest == NULL)
	{
		ft_clear_strs(strs);
		return (NULL);
	}
	while (*s != c && *s != '\0')
		dest[i++] = *s++;
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		t;
	char	**strs;

	i = 0;
	t = 1;
	strs = malloc(sizeof(char *) * (ft_wc(s, c) + 1));
	if (strs == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c && t == 1)
		{
			strs[i] = ft_putstr(s, c, strs);
			if (strs[i] == NULL)
				return (NULL);
			t = 0;
			i++;
		}
		if (*s != c && *(s + 1) == c)
			t = 1;
		s++;
	}
	strs[i] = NULL;
	return (strs);
}
