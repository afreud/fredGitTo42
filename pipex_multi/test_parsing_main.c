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
		int j;
		int k =0;

		j = 0;
		char	***cmds_t;
		char	***cmdpath_t;
		cmds_t = NULL;
		cmdpath_t = NULL;
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

		j = 0;
		k = 0;
		cmdpath_t = ft_cmdpath_t(cmds_t);
		if (!cmdpath_t)
		{
			printf("HAHAHA");
			return (-1);
		}
		while (cmdpath_t[j])
		{
			while (cmdpath_t[j][k])
			{
				printf("%s\n",cmdpath_t[j][k]);
				k++;
			}
			printf("\n");
			j++;
			k = 0;
		}
		ft_clean3d(cmdpath_t);
		ft_clean3d(cmds_t);
		printf("      %s\n", argv[argc - 1]);
	}
	return (0);
}
