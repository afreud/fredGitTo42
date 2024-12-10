
#include "pipex.h"

void	ft_check_fd(int *fd, int argc, char **argv)
{

}

char	**ft_path_t(char ***cmds_t, int *fd)
{
	char	**path_t;
	char	***cmdpath_t;
	int	i;
	int j;

	i = 0;
	j = 0;
	cmdpath_t = ft_cmdpath_t(cmds_t);
	if (!cmdpath_t)
		return (NULL);
	path_t = malloc(sizeof(char *) * (ft_len3(cmds_t) + 1));
	if (!path_t)
	{
		ft_clean3d(cmdpath_t);
		return (NULL);
	}
	while (cmdpath_t[i] && t)
	{
		t = 0;
		while (cmdpath_t[i][j])
		{
			if (access(cmdpath_t[i][j], X_OK) == 0)
			{
				path_t[i] = ft_strdup(cmdpath_t[i][j]);
				t = 1;
			}
			j++;
		}
		j =0;
		i++;
	}
}
