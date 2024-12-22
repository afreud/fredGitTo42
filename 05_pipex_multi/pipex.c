#include "pipex.h"

void	ft_closefd(int pipefd[1024][2], int max)
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

int	ft_creat_pipes(int pipefd[1024][2], char ***cmds_t)
{
	int	i;
	int	max;

	i = 0;
	max = ft_len3(cmds_t) - 1;
	while (i < max)
	{
		if (pipe(pipefd[i++]) < 0)
		{
			ft_closefd(pipefd, (i - 2));
			perror("pipe");
			return (-1);
		}
	}
	return (max);
}

void	ft_dupfd(int *fd, int pipefd[1024][2], int i, int *max)
{
	int	k;

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
	{
		ft_closefd(pipefd, *max);
		*max = -1;
	}
}

void	pipex(int *fd, char ***cmds_t, char **path_t)
{
	extern char	**environ;
	int			pipefd[1024][2];
	pid_t		pid;
	int			i;
	int			max;

	i = 0;
	max = ft_creat_pipes(pipefd, cmds_t);
	while (i <= max)
	{
		pid = fork();
		if (pid < 0)
			perror("fork");
		if (pid == 0)
		{
			ft_dupfd(fd, pipefd, i, &max);
			ft_closefd(pipefd, max);
			execve(path_t[i], cmds_t[i], environ);
		}
		i++;
	}
	ft_closefd(pipefd, max);
	i = 0;
	while (i++ <= max)
		wait(NULL);
}
