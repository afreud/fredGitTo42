
#include "pipex.h"


int main(int argc, char **argv)
{
	int fd[2];
	char	***cmds_t;
	char	**path_t;

	if (argc < 5)
	{
		write(0, "Too few arguments", 17);
		return (-1);
	}
	if (ft_open_files(fd, argv[1], argv[2]))
		argv++;
	cmds_t = ft_cmds_t(argc, argv);
	if (!cmds_t)
		perror("Problem creating arguments array");
	path_t = ft_path_t(cmds_t);		
	if (!path_t && cmds_t)
		perror("Wrong command");
	if (path_t)
		pipex(fd, cmds_t, path_t);
	ft_clean_close(fd, cmds_t, path_t)
	return (0);
}
