#include "pipex.h"


int main(int argc, char **argv)
{
	int fd[2];
	char	***cmds_t;
	char	***cmdpath_t;

	if (argc <= 4)
		return (-1);
	fd[0] = open(argv[1], O_RDWR | O_CREAT, 0666);
	fd[1] = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (fd[0] < 0 || fd[1] < 0)
	{
		perror("Files");
		exit (EXIT_FAILURE);
	}
	cmds_t = ft_cmds_t(argc, argv);
	if (!cmds_t)
		perror("tabcmd");
	cmdpath_t = ft_cmdpath_t(cmds_t);		
	if (!cmdpath_t)
		perror("path");
	pipex(fd, cmds_t, cmdpath_t);
	close(fd[0]);
	close(fd[1]);
	ft_clean3d(cmds_t);
	ft_clean3d(cmdpath_t);
	return (0);
}
