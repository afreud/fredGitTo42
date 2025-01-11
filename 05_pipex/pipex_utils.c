/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:12:17 by frdurand          #+#    #+#             */
/*   Updated: 2024/12/24 11:12:24 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_closefd(int pipefd[512][2], int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		close(pipefd[i][1]);
		close(pipefd[i][0]);
		i++;
	}
}

int	ft_len2(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

int	ft_len3(char ***s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	**ft_clean2(char **t)
{
	int	i;

	i = 0;
	if (t)
	{
		while (t && t[i])
		{
			free(t[i]);
			t[i++] = NULL;
		}
		free(t);
		t = NULL;
	}
	return (NULL);
}

char	***ft_clean3(char ***t)
{
	int	i;

	i = 0;
	if (t)
	{
		while (t[i])
		{
			t[i] = ft_clean2(t[i]);
			i++;
		}
		free(t);
		t = NULL;
	}
	return (NULL);
}
