/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:31:50 by frdurand          #+#    #+#             */
/*   Updated: 2024/12/27 11:09:53 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_strcp(char *s2, int *t)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = malloc(sizeof(char) * (ft_strlen(s2) + 1));
	if (s1)
	{
		while (s2[i])
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = '\0';
		*t = 1;
	}
	return (s1);
}

static char	**ft_check_acc(char ***allpaths_t, int i, int j, int k)
{
	char	**path_t;
	int		t;

	path_t = malloc(sizeof(char *) * (ft_len3(allpaths_t) + 1));
	while (allpaths_t[i] && path_t)
	{
		t = 0;
		while (allpaths_t[i][j] && !t)
		{
			if (access(allpaths_t[i][j], X_OK) == 0)
				path_t[k] = ft_strcp(allpaths_t[i][j], &t);
			j++;
		}
		if (!t)
		{
			perror("\nCommand not found");
			path_t[k++] = NULL;
		}
		i++;
		j = 0;
	}
	if (path_t)
		path_t[k] = NULL;
	if (!t)
		path_t = ft_clean2(path_t);
	return (path_t);
}

char	**ft_path_t(char ***cmds_t)
{
	char	**path_t;
	char	***allpaths_t;
	int		i;
	int		j;

	i = 0;
	j = 0;
	path_t = NULL;
	allpaths_t = ft_allpaths_t(cmds_t);
	if (!allpaths_t)
		return (NULL);
	path_t = ft_check_acc(allpaths_t, i, j, 0);
	allpaths_t = ft_clean3(allpaths_t);
	return (path_t);
}
