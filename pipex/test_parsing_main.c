#include <stdio.h>
#include "ft_getenv.c"
#include "pipex.h"
#include "pipex_cmds.c"
#include "pipex_strs.c"
#include "pipex_utils.c"

int main(int argc, char **argv)
{
	if (argc)
	{
		int	i;
		int j;
		int k =0;

		i = 0;
		j = 0;
		char	***tabcmd;
		char	**cmdpath;
		cmdpath = NULL;
		tabcmd = NULL;
		char	**path = ft_getenv(argv[1]);
		printf("\n");

		if (!path)
		{
			printf("%s doesn't exist", argv[1]);
			printf("ENV_VAR(ex:PATH) cmd..cmd message\n");
		}
		else
		{
			while (path[i])
			{
				printf("%s\n",path[i]);
				i++;
			}
			i = 0;
			printf("\n");

			tabcmd = ft_tabcmd(argc, argv);
			while (tabcmd[j])
			{
				while (tabcmd[j][k])
				{
					printf("%s\n", tabcmd[j][k]);
					k++;
				}
				printf("\n");
				j++;
				k = 0;
			}
			printf("\n");

			j = 0;
			while (tabcmd[j])
			{
				cmdpath = ft_cmdpath(path, tabcmd[j][0]);
				while (cmdpath[i])
				{
					printf("%s\n",cmdpath[i]);
					i++;
				}
				ft_clean(cmdpath);
				printf("\n");
				j++;
				i = 0;
			}
			ft_clean(path);
			ft_clean3d(tabcmd);
			printf("      %s\n", argv[argc - 1]);
		}
	}
	return (0);
}
