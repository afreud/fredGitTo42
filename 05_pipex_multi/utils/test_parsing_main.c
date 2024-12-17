#include <stdio.h>
#include "ft_getenv.c"
#include "pipex.h"
#include "pipex_cmds.c"
#include "pipex_strs.c"
#include "pipex_utils.c"
#include "pipex_init.c"





int main(int argc, char **argv)
{
	if (argc)
	{
		int j;
		int k =0;

		j = 0;
		char	***cmds_t;
//		char	***allpaths_t;
		char	**path_t;
		cmds_t = NULL;
		path_t = NULL;
		printf("\n");

		cmds_t = ft_cmds_t(argc, argv);
		while (cmds_t[j])
		{
			while (cmds_t[j][k])
			{
				printf("%s\n", cmds_t[j][k]);
				k++;
			}
			printf("\n");
			j++;
			k = 0;
		}

//		j = 0;
//		k = 0;
//		allpaths_t = ft_allpaths_t(cmds_t);
//		while (allpaths_t[j])
//		{
//			while (allpaths_t[j][k])
//			{
//				printf("%s\n", allpaths_t[j][k]);
//				k++;
//			}
//			printf("\n");
//			k =0;
//			j++;
//		}
//

		j =0;
		path_t = ft_path_t(cmds_t);
		if (!path_t)
			printf("WRONG COMMAND\n");
		else
			while (path_t[j])
				printf("%s\n", path_t[j++]);
		ft_clean3d(cmds_t);
//		ft_clean3d(allpaths_t);
		ft_clean(path_t);
		printf("      %s\n", argv[argc - 1]);
	}
	return (0);
}
