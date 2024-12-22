
#include "pipex.h"

void	ft_clean_close(int *fd, char ***cmds_t, char **path_t)
{
	close(fd[0]);
	close(fd[1]);
	ft_clean3(cmds_t);
	ft_clean2(path_t);
}

static void	ft_hdoc(int *fd,int argc,char **argv)
{
	char	*line;
	line = NULL;
	fd[0] = open("here_file", O_WRONLY | O_CREAT, 0666);
	fd[1] = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (fd[0] < 0 || fd[1] < 0)
	{
		if (fd[0] > 0)
			close(fd[0]);
		if (fd[1] > 0)
			close(fd[1]);
		perror("Error opening Files");
		exit (-3);
	}
	line = get_next_line(0, argv[2]);
	while (line != NULL)
	{
		write(fd[0], line, ft_strlen(line));
		free(line);
		line = get_next_line(0, argv[2]);
	}
	close(fd[0]);
	fd[0] = open("here_file", O_RDONLY, 0666);
	if (fd[0] < 0)
		close(fd[1]);
}

int	ft_open_files(int *fd, int argc, char **argv)
{
	int	i;

	i = 0;
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		ft_hdoc(fd, argc, argv);
		i = 1;
	}
	else
	{
		fd[0] = open(argv[1], O_RDONLY | O_CREAT, 0666);
		fd[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0666);
		if (fd[0] < 0 || fd[1] < 0)
		{
			if (fd[0] > 0)
				close(fd[0]);
			if (fd[1] > 0)
				close(fd[1]);
			perror("Error opening Files");
			exit (-2);
		}
	}
	return (i);
}
