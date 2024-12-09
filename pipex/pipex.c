
#include "pipex.h"

static void	ft_child(int *fd, int *pipefd, char **cmds, char **cmd_path)
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
	perror("Second command arguments error");
	exit(EXIT_FAILURE);
}

static void	ft_parent(int *fd, int *pipefd, char **cmds, char **cmd_path)
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
	perror("Second command arguments error");
	exit(EXIT_FAILURE);
}


void	pipex(int *fd, char ***cmds_t, char ***cmdpath_t)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) != 0)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (!pid)
		ft_child(fd, pipefd, cmds_t[0], cmdpath_t[0]);
	waitpid(pid, NULL, 0);
	close(pipefd[1]);
	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (!pid)
		ft_parent(fd, pipefd, cmds_t[1], cmdpath_t[1]);
	else
	{
		waitpid(pid, NULL, 0);
		close(pipefd[0]);
		ft_clean3d(cmds_t);
		ft_clean3d(cmdpath_t);
	}
}
