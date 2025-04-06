/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:14:38 by frdurand          #+#    #+#             */
/*   Updated: 2025/02/12 12:40:43 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

static int	ft_creat_pipes(int pipefd[512][2], char ***cmds_t)
{
	int	i;
	int	max;

	i = 0;
	max = ft_len3(cmds_t) - 1;
	while (i < max)
	{
		if (pipe(pipefd[i++]) < 0)
		{
			ft_closefd(pipefd, (i - 1));
			perror("pipe");
			return (-1);
		}
	}
	return (max);
}

static void	ft_wrdup(int pipefd[512][2], int *max, int *fd)
{
	ft_closefd2(pipefd, *max, fd);
	*max = -1;
	perror("Problem with dup2");
}

static void	ft_dupfd(int *fd, int pipefd[512][2], int i, int *max)
{
	int	k;

	k = 0;
	if (!i)
	{
		k = dup2(fd[0], STDIN_FILENO);
		if (k != -1)
			k = dup2(pipefd[i][1], STDOUT_FILENO);
	}
	else if (i && i != *max)
	{
		k = dup2(pipefd[i - 1][0], STDIN_FILENO);
		if (k != -1)
			k = dup2(pipefd[i][1], STDOUT_FILENO);
	}
	else if (i == *max)
	{
		k = dup2(pipefd[i - 1][0], STDIN_FILENO);
		if (k != -1)
			k = dup2(fd[1], STDOUT_FILENO);
	}
	if (k == -1)
		ft_wrdup(pipefd, max, fd);
}

static void	ft_exec(char *path_t, char **cmds_t, int max)
{
	extern char	**environ;

	if (max != -1)
	{
		if (execve(path_t, cmds_t, environ) == -1)
		{
			perror(*cmds_t);
			exit(errno);
		}
	}
}

int	pipex(int *fd, char ***cmds_t, char **path_t)
{
	int			pipefd[512][2];
	pid_t		pid;
	int			i;
	int			max;
	int			status;

	i = -1;
	max = ft_creat_pipes(pipefd, cmds_t);
	while (++i <= max)
	{
		if (path_t[i])
		{
			pid = fork();
			if (pid < 0)
				break ;
			if (pid == 0)
			{
				ft_dupfd(fd, pipefd, i, &max);
				ft_closefd2(pipefd, max, fd);
				ft_exec(path_t[i], cmds_t[i], max);
			}
		}
	}
	ft_closefd(pipefd, max);
	i = 0;
	while (i++ <= max)
		waitpid(-1, &status, 0);
	return (WEXITSTATUS(status));
}
