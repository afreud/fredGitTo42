/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:33:20 by frdurand          #+#    #+#             */
/*   Updated: 2025/01/07 11:39:53 by frdurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

static void	ft_nia(int pipefd[512][2], int *max)
{
	ft_closefd(pipefd, *max);
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
		ft_nia(pipefd, max);
}

static void	ft_exec(char *path_t, char **cmds_t, int max)
{
	extern char	**environ;

	if (max != -1)
		execve(path_t, cmds_t, environ);
	perror(*cmds_t);
	exit(EXIT_FAILURE);
}

int	pipex(int *fd, char ***cmds_t, char **path_t)
{
	int		pipefd[512][2];
	pid_t	pid;
	int		i;
	int		max;
	int		status;

	i = -1;
	max = ft_creat_pipes(pipefd, cmds_t);
	while (++i <= max)
	{
		pid = fork();
		if (pid < 0)
			break ;
		if (pid == 0)
		{
			ft_dupfd(fd, pipefd, i, &max);
			ft_closefd(pipefd, max);
			ft_exec(path_t[i], cmds_t[i], max);
		}
	}
	ft_closefd(pipefd, max);
	i = 0;
	while (i++ <= max)
		waitpid(-1, &status, 0);
	return (WEXITSTATUS(status));
}
