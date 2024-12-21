
#include "pipex.h"

int	ft_creat_pipes(int pipefd[1024][2], char ***cmds_t)
{
	int	i;
	int max;

	i = 0;
	max = ft_len3(cmds_t) - 1;
	while (i < max)
	{
		if (pipe(pipefd[i++]) < 0)
			perror("pipe");
	}
	return (max);
}

void	ft_dupfd(int *fd, int pipefd[1024][2], int i, int max)
{
		if (!i)
		{
			if (dup2(fd[0], STDIN_FILENO) == -1)
				perror("dupf0");
			if (dup2(pipefd[i][1], STDOUT_FILENO) == -1)
				perror("dupf1");
		}
		else if (i && i != max)
		{
			if (dup2(pipefd[i - 1][0], STDIN_FILENO) == -1)
				perror("dupm0");
			if (dup2(pipefd[i][1], STDOUT_FILENO) == -1)
				perror("dupm1");
		}
		else if (i == max)
		{
			if (dup2(pipefd[i - 1][0], STDIN_FILENO) == -1)
				perror("dupl0");
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				perror("dupl1");
		}
}

void	ft_closefd(int pipefd[1024][2],int max)
{
	int i = 0;

	i = 0;
	while (i < max)
	{
		close(pipefd[i][1]);
		close(pipefd[i][0]);
		i++;
	}

}

void	pipex(int *fd, char ***cmds_t, char **path_t)
{
	int		pipefd[1024][2];
	pid_t	pid;
	int	i;
	int max;

	i = 0;
	max = ft_creat_pipes(pipefd, cmds_t);
	while (cmds_t[i])
	{
		pid = fork();
		if (pid < 0)
			perror("fork");
		if (pid == 0)
		{
			ft_dupfd(fd, pipefd, i, max);
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
