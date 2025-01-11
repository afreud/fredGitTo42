/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:34:37 by frdurand          #+#    #+#             */
/*   Updated: 2024/12/24 13:44:54 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	ft_splen(const char *str, char c)
{
	int		sum;
	char	q;

	sum = 0;
	if (*str == '\'' || *str == '\"')
	{
		q = *str;
		str++;
		while (*str != q && *str)
		{
			sum++;
			str++;
		}
		return (sum);
	}
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

static char	*ft_cpstr(const char *s, char c, char **strs)
{
	int		i;
	char	q;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_splen(s, c) + 1));
	if (dest == NULL)
	{
		strs = ft_clean2(strs);
		return (NULL);
	}
	if (*s == '\'' || *s == '\"')
	{
		q = *s;
		s++;
		while (*s != q && *s)
			dest[i++] = *s++;
	}
	else
		while (*s != c && *s != '\0')
			dest[i++] = *s++;
	dest[i] = '\0';
	return (dest);
}

char	**ft_msplit(char const *s, char c)
{
	int		i;
	int		t;
	char	**strs;

	i = 0;
	t = 1;
	strs = malloc(sizeof(char *) * (ft_wc(s, c) + 1));
	while (*s && strs)
	{
		if (*s != c && t == 1)
		{
			strs[i] = ft_cpstr(s, c, strs);
			if (strs[i++] == NULL)
				strs = NULL;
			t = 0;
		}
		if (*s == '\'' || *s == '\"')
			s += ft_splen(s, ' ') + 1;
		if (*s != c && *(s + 1) == c)
			t = 1;
		s++;
	}
	if (strs)
		strs[i] = NULL;
	return (strs);
}
