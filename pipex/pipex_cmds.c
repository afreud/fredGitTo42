
#include "pipex.h"

char	***ft_cmds_t(int argc, char **argv)
{
	char	***cmds_t;
	int	i;
	int j;

	i = 0;
	j = 2;
	cmds_t = malloc(sizeof(char **) * (argc - 2));
	if (!cmds_t)
		return (NULL);
	cmds_t[argc - 3] = NULL;
	while (i < (argc - 3))
	{
		cmds_t[i] = ft_msplit(argv[j], ' ');
		if (!cmds_t[i])
		{
			ft_clean3d(cmds_t);
			return (NULL);
		}
		i++;
		j++;
	}
	return (cmds_t);
}

static int	ft_len2(char **s)
{
	int c;
	int	i;

	i = 0;
	c = 0;
	while (s[i++])
		c++;
	return (c);
}

int	ft_len3(char ***s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	**ft_join_pc(char **path, char *cmd)
{
	char **cmd_path;
	int	i;

	i = 0;
	cmd_path = malloc(sizeof(char *) * (ft_len2(path) + 1));
	if (!cmd_path)
		return (NULL);
	while (path[i])
	{
		cmd_path[i] = ft_cjoin(path[i], cmd);
		if (!cmd_path[i])
		{
			ft_clean(cmd_path);
				return (NULL);
		}
		i++;
	}
	cmd_path[i] = NULL;
	return (cmd_path);
}

char	***ft_cmdpath_t(char ***cmds_t)
{
	char	***cmdpath_t;
	char	**path;
	int	i;

	i = 0;
	if (!cmds_t)
		return (NULL);
	path = ft_getenv("PATH");
	if (!path)
		return (NULL);
	cmdpath_t = malloc(sizeof(char **) * (ft_len3(cmds_t) + 1));
	if (!cmdpath_t)
		return (NULL);
	while (cmds_t[i])
	{
		cmdpath_t[i] = ft_join_pc(path, cmds_t[i][0]);
		if (!cmdpath_t[i])
			ft_clean3d(cmdpath_t);
		i++;
	}
	cmdpath_t[i] = NULL;
	ft_clean(path);
	return (cmdpath_t);
}
