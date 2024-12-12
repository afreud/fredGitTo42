
#include "pipex.h"

void	ft_clean_close(int *fd, char ***cmds_t, char **path_t)
{
	close(fd[0]);
	close(fd[1]);
	ft_clean3(cmds_t);
	ft_clean2(path_t);
}

void	ft_hdoc(int *fd, char *limiter)
{
	char	*line[2500];
	fd[0] = open("here_file", O_RDWR | O_CREAT, 0666);
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
	line = ft_get_next_line(0, limiter);
	while (line)
	{
		write(fd[0], line, ft_strlen(line));
		free(line);
		line = NULL;
		line = ft_get_next_line(0, limiter);
	}
	free(line);
	line = NULL;
}

int	ft_open_files(int *fd, char **argv)
{
	int	i;

	i = 0;
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		ft_hdoc(fd, limiter);
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
