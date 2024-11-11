

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	if(argc > 1)
	{
		int i = 0;

		char *str = argv[1];
		char **strs = ft_split(str);
		while (strs[i] != NULL)
		{
			printf("%s\n", strs[i]);
			i++;
		}
		i = 0;
		while (strs[i] != NULL)
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
	return (0);
}
