/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:31:22 by frdurand          #+#    #+#             */
/*   Updated: 2025/02/06 14:44:13 by frdurand         ###   ########.fr       */
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

void	ft_clean_close(int *fd, char ****cmds_t, char ***path_t)
{
	close(fd[0]);
	close(fd[1]);
	*cmds_t = ft_clean3(*cmds_t);
	*path_t = ft_clean2(*path_t);
}

void	ft_open_files(int *fd, int argc, char **argv)
{
	int err_sav;

	fd[0] = open(argv[1], O_RDONLY, 0666);
	if (fd[0] == -1)
	{
		err_sav = errno;
		perror("Error opening File");
		exit (err_sav);
	}
	fd[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (fd[1] == -1)
	{
		err_sav = errno;
		perror("Error opening File");
		exit (err_sav);
	}
}
