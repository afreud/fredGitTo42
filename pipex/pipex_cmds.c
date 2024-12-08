
#include "pipex.h"

char	***ft_tabcmd(int argc, char **argv)
{
	char	***tabcmd;
	int	i;
	int j;

	i = 0;
	j = 2;
	tabcmd = malloc(sizeof(char **) * (argc - 2));
	if (!tabcmd)
		return (NULL);
	tabcmd[argc - 3] = NULL;
	while (i < (argc - 3))
	{
		tabcmd[i] = ft_msplit(argv[j], ' ');
		if (!tabcmd[i])
		{
			ft_clean3d(tabcmd);
			return (NULL);
		}
		i++;
		j++;
	}
	return (tabcmd);
}

static int	ft_tablen(char **s)
{
	int c;
	int	i;

	i = 0;
	c = 0;
	while (s[i++])
		c++;
	return (c);
}

char	**ft_cmdpath(char **path, char *cmd)
{
	char **cmd_path;
	int	i;

	i = 0;
	cmd_path = malloc(sizeof(char *) * (ft_tablen(path) + 2));
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
