

#include <stdio.h>
#include <stdlib.h>

int	ft_wc(char *str)
{
	int	c;

	c = 0;
	while (*str == ' ')
		str++;
	while (*str != '\0')
	{
		if ((*str != ' ' && *(str + 1) == ' ')
		|| (*str != ' ' && *(str + 1) == '\0'))
			c++;
		str++;
	}
	return (c);
}

int	ft_wlen(char *str)
{
	int	i;

	i = 0;
	while (*str == ' ')
		str++;
	while (*str != ' ' && *str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char	**ft_split(char *str)
{
	int i;
	int j;
	char	**tab_of_strs;

	i = 0;
	j = 0;
	tab_of_strs = malloc(sizeof(char *) * (ft_wc(str) + 1));
	tab_of_strs[i] = malloc(sizeof(char) * (ft_wlen(str) + 1));
	while (*str != '\0')
	{
		if (*str != ' ')
			tab_of_strs[i][j++] = *str;
		if (*str != ' ' && *(str + 1) == ' ' && i <= ft_wc(&str[0]))
		{
			tab_of_strs[i++][j] = '\0';
			j = 0;
			tab_of_strs[i] = malloc(sizeof(char) * ft_wlen(str +1) + 1);
		}
		str++;
	}
	tab_of_strs[i++][j] = '\0';
	tab_of_strs[i] = NULL;
	return (tab_of_strs);
}

int main (int argc, char **argv)
{
	if(argc > 1)
	{
		int i = 0;

		i = 0;
		char *str = argv[1];
		char **tab_of_strs = ft_split(str);
		while (tab_of_strs[i] != NULL)
		{
			printf("%s\n", tab_of_strs[i]);
			i++;
		}
		i = 0;
		while (tab_of_strs[i] != NULL)
		{
			free(tab_of_strs[i]);
			i++;
		}
		free(tab_of_strs);
	}
	return (0);
}
