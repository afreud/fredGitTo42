#include "pipex.h"

static void	ft_error_access(int *t, char **path_t, int i, char ***allpaths_t)
{
	int j;

	j = 0;
	if (!i)
	{
		free(path_t);
		path_t = NULL;
	}
	if (!*t && i)
		path_t[i] = NULL;
	*t = 0;
	while (allpaths_t[i][j])
		perror(allpaths_t[i][j++]);
	perror("Command cannot be found");
	ft_clean2(path_t);
}

static char	*ft_strcp(char *s2)
{
	char *s1;
	int	i;

	i = 0;
 	s1 = malloc(sizeof(char) * (ft_strlen(s2) + 1));
	if (s1)
	{
		while (s2[i])
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = '\0';
	}
	return (s1);
}

static char	**ft_check_acc(char ***allpaths_t, int i, int j)
{
	char	**path_t;
	int t;

	t = 1;
	path_t = malloc(sizeof(char *) * (ft_len3(allpaths_t) + 1));
	while (allpaths_t[i] && t && path_t)
	{
		t = 0;
		while (allpaths_t[i][j] && t == 0)
		{
			if (access(allpaths_t[i][j], X_OK) == 0)
			{
				path_t[i] = ft_strcp(allpaths_t[i][j]);
				t = 1;
			}
			j++;
		}
		if (t == 0 || !path_t[i])
		{
			ft_error_access(&t, path_t, i, allpaths_t);
			return (NULL);
		}
		j = 0;
		i++;
	}
	if (path_t)
		path_t[i] = NULL;
	return (path_t);
}

char	**ft_path_t(char ***cmds_t)
{
	char	**path_t;
	char	***allpaths_t;
	int	i;
	int	j;

	i = 0;
	j = 0;
	path_t = NULL;
	allpaths_t = ft_allpaths_t(cmds_t);
	if (!allpaths_t)
		return (NULL);
	path_t = ft_check_acc(allpaths_t, i, j);
	ft_clean3(allpaths_t);
	return (path_t);
}
