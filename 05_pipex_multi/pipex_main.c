
#include "pipex.h"


int main(int argc, char **argv)
{
	int		fd[2];
	char	***cmds_t;
	char	**path_t;

	cmds_t = NULL;
	path_t = NULL;
	if (argc < 5)
	{
		write(0, "Too few arguments", 17);
		return (-1);
	}
	if (ft_open_files(fd, argc, argv))
	{
		argc--;
		argv++;
	}
	cmds_t = ft_cmds_t(argc, argv);
	if (!cmds_t)
		perror("Problem creating arguments array");
	path_t = ft_path_t(cmds_t);		
	if (path_t)
		pipex(fd, cmds_t, path_t);
	ft_clean_close(fd, cmds_t, path_t);
	return (0);
}
