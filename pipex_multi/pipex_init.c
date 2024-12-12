
#include <stdio.h>
#include "pipex.h"

//void	ft_check_fd(int *fd, int argc, char **argv)

char	*ft_strcp(char *s2)
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

char	**ft_check_acc(char ***allpaths_t, int i, int j)
{
	char	**path_t;
	int t;

	t = 1;
	path_t = malloc(sizeof(char *) * (ft_len3(allpaths_t) + 1));
	while (path_t && allpaths_t[i] && t)
	{
		t = 0;
		while (allpaths_t[i][j] && t == 0)
		{
			if (access(allpaths_t[i][j], X_OK) == 0)
			{
				path_t[i] = ft_strcp(allpaths_t[i][j]);
				if (path_t[i])
					t = 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (t == 0)
		ft_clean(path_t);
	else
		path_t[i] = NULL;
	return (path_t);
}

char	**ft_path_t(char ***cmds_t)
{
	char	**path_t;
	char	***allpaths_t;
	int	i;
	int	j;

	path_t = NULL;
	i = 0;
	j = 0;
	allpaths_t = ft_allpaths_t(cmds_t);
	if (!allpaths_t)
		return (NULL);
	path_t = ft_check_acc(allpaths_t, i, j);
	ft_clean3d(allpaths_t);
	allpaths_t = NULL;
	return (path_t);
}
