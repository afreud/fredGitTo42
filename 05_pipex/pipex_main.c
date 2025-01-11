/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:31:31 by frdurand          #+#    #+#             */
/*   Updated: 2025/01/07 10:18:15 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int		fd[2];
	char	***cmds_t;
	char	**path_t;
	int		status;

	status = -1;
	cmds_t = NULL;
	path_t = NULL;
	if (argc != 5)
		exit (EXIT_FAILURE);
	ft_open_files(fd, argc, argv);
	cmds_t = ft_cmds_t(argc, argv);
	if (!cmds_t)
		perror("Problem creating arguments array");
	path_t = ft_path_t(cmds_t);
	if (path_t)
		status = pipex(fd, cmds_t, path_t);
	ft_clean_close(fd, &cmds_t, &path_t);
	exit(status);
}
