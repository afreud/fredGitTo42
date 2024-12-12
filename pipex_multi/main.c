#include "pipex.h"


int main(int argc, char **argv)
{
	int fd[2];
	char	***cmds_t;
	char	**path_t;

	if (argc <= 4)
		return (-1);
	fd[0] = open(argv[1], O_RDWR | O_CREAT, 0666);
	fd[1] = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (fd[0] < 0 || fd[1] < 0)
	{
		perror("Error opening Files");
		exit (-2);
	}
	cmds_t = ft_cmds_t(argc, argv);
	if (!cmds_t)
		perror("tabcmd");
	path_t = ft_path_t(cmds_t);		
	if (path_t)
		pipex(fd, cmds_t, path_t);
	close(fd[0]);
	close(fd[1]);
	ft_clean3(cmds_t);
	ft_clean2(path_t);
	return (0);
}
