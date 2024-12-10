
#include "pipex.h"

static void	ft_child_f(int *fd, int *pipefd, char **cmds, char **cmd_path)
{
	int	i;

	i = 0;
	close(pipefd[0]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror("dupfd0");
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		perror("dupfd1");
	close(fd[0]);
	close(pipefd[1]);
	while (cmd_path[i] && (execve(cmd_path[i], cmds, environ) == -1))
		i++;
	perror("First command arguments error");
}

static void	ft_child_m(int *fdprev, int *fdnext, char **cmds, char **cmd_path)
{
	int	i;

	i = 0;
	close(fdnext[0]);
	if (dup2(fdprev[0], STDIN_FILENO) == -1)
		perror("dupfd0");
	if (dup2(fdnext[1], STDOUT_FILENO) == -1)
		perror("dupfd0");
	close(fdprev[0]);
	close(fdnext[1]);
	while (cmd_path[i] && (execve(cmd_path[i], cmds, environ) == -1))
		i++;
	perror("Command arguments error");
}

static void	ft_child_l(int *fd, int *pipefd, char **cmds, char **cmd_path)
{
	int	i;

	i = 0;
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		perror("dupfd0");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror("dupfd0");
	close(fd[1]);
	close(pipefd[0]);
	while (cmd_path[i] && (execve(cmd_path[i], cmds, environ) == -1))
		i++;
	perror("Last command arguments error");
}


void	pipex(int *fd, char ***cmds_t, char ***cmdpath_t)
{
	int		pipefd[1024][2];
	pid_t	pid;
	int	i;
	int max;

	i = 0;
	max = ft_len3(cmds_t) - 1;
	while (cmds_t[i])
	{
		if (i != max)
		{
			if (pipe(pipefd[i]) != 0)
				perror("pipe");
		}
		pid = fork();
		if (pid < 0)
			perror("fork");
		if (!pid && !i)
			ft_child_f(fd, pipefd[i], cmds_t[i], cmdpath_t[i]);
		else if (!pid && i && i != max)
			ft_child_m(pipefd[i - 1], pipefd[i], cmds_t[i], cmdpath_t[i]);
		else if (!pid && i == max)
			ft_child_l(fd, pipefd[i - 1], cmds_t[i], cmdpath_t[i]);
		else if (pid)
		{
			waitpid(pid, NULL, 0);
			if (i == 0)
			{
				close(pipefd[i][1]);
			}
			else if (i == max)
				close(pipefd[i - 1][0]);
			else
			{
				close(pipefd[i - 1][0]);
				close(pipefd[i][1]);
			}
		}
		i++;
	}
}
