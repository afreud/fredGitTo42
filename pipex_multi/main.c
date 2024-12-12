#include "pipex.h"


int main(int argc, char **argv)
{
	int fd[2];
	char	***cmds_t;
	char	***allpaths_t;

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
	allpaths_t = ft_allpaths_t(cmds_t);		
	if (!allpaths_t)
		perror("path");
	pipex(fd, cmds_t, allpaths_t);
	close(fd[0]);
	close(fd[1]);
	ft_clean3d(cmds_t);
	ft_clean3d(allpaths_t);
	return (0);
}
