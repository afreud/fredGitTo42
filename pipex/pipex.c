
#include "pipex.h"

static void	ft_child(int *fd, int *pipefd, char ***cmds_t, char **path)
{
	char	**cmd_path;
	int	i;

	i = 0;
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror("dupfd0");
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		perror("dupfd1");
	close(fd[0]);
	close(pipefd[1]);
	close(pipefd[0]);
	cmd_path = ft_join_pc(path, cmds_t[0][0]);
	if (!cmd_path)
		perror("cmd_path");
	while (cmd_path[i] && (execve(cmd_path[i], cmds_t[0], environ) == -1))
	{
		i++;
	}
	ft_clean(cmd_path);
	exit(EXIT_SUCCESS);
}

static void	ft_parent(int *fd, int *pipefd, char ***cmds_t, char **path)
{
	char	**cmd_path;
	int	i;

	i = 0;
	dup2(fd[1], STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	close(fd[1]);
	close(pipefd[0]);
	close(pipefd[1]);
	cmd_path = ft_join_pc(path, cmds_t[1][0]);
	while (cmd_path[i] && (execve(cmd_path[i], cmds_t[1], environ) == -1))
		i++;
	ft_clean(cmd_path);
	exit(EXIT_SUCCESS);
}


void	pipex(int *fd, char ***cmds_t, char **path)
{
	int		status;
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) != 0)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (!pid)
	{
		ft_child(fd, pipefd, cmds_t, path);
	}
	else
	{
		waitpid(pid, &status, 0);
		ft_parent(fd, pipefd, cmds_t, path);
		ft_clean3d(cmds_t);
		ft_clean(path);
		close(fd[0]);
		close(fd[1]);
	}
}
