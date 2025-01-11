/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:31:10 by frdurand          #+#    #+#             */
/*   Updated: 2024/12/24 11:31:17 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	***ft_cmds_t(int argc, char **argv)
{
	char	***cmds_t;
	int		i;
	int		j;

	i = 0;
	j = 2;
	cmds_t = malloc(sizeof(char **) * (argc - 2));
	if (!cmds_t)
		return (NULL);
	cmds_t[argc - 3] = NULL;
	while (i < (argc - 3))
	{
		cmds_t[i] = ft_msplit(argv[j], ' ');
		if (!cmds_t[i])
		{
			cmds_t = ft_clean3(cmds_t);
			return (NULL);
		}
		i++;
		j++;
	}
	return (cmds_t);
}

static char	**ft_join_pc(char **path, char *cmd)
{
	char	**cmd_path;
	int		i;

	i = 0;
	cmd_path = malloc(sizeof(char *) * (ft_len2(path) + 1));
	if (!cmd_path)
		return (NULL);
	while (path[i])
	{
		cmd_path[i] = ft_cjoin(path[i], cmd);
		if (!cmd_path[i])
		{
			cmd_path = ft_clean2(cmd_path);
			return (NULL);
		}
		i++;
	}
	cmd_path[i] = NULL;
	return (cmd_path);
}

char	***ft_allpaths_t(char ***cmds_t)
{
	char	***allpaths_t;
	char	**path;
	int		i;

	i = 0;
	if (!cmds_t)
		return (NULL);
	path = ft_getenv("PATH");
	if (!path)
		return (NULL);
	allpaths_t = malloc(sizeof(char **) * (ft_len3(cmds_t) + 1));
	while (cmds_t[i] && allpaths_t)
	{
		allpaths_t[i] = ft_join_pc(path, cmds_t[i][0]);
		if (!allpaths_t[i])
			allpaths_t = ft_clean3(allpaths_t);
		i++;
	}
	if (allpaths_t)
		allpaths_t[i] = NULL;
	path = ft_clean2(path);
	return (allpaths_t);
}
