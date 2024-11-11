#include <stdlib.h>

char **ft_split(char const *s, char c);

static int	ft_len(const char *str, char c)
{
	int sum;

	sum = 0;
	while (*str == c)
		str++;
	while (*str != c && *str != '\0')
	{
		sum++;
		str++;
	}
	return(sum);
}

static int	ft_wc(const char *str, char c)
{
	int	i;
	int sum;

	i = 0;
	sum = 0;
	while (str[i] != '\0' )
	{
		if (str[i] != c && str[i + 1] == c)
			sum++;
		else if (str[i] != c && str[i + 1] == '\0' )
			sum++;
		i++;
	}
	return(sum);
}

static char *ft_putstr(const char *s, char c)
{
	int	i;
	char *dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_len(s, c) + 1));
	if (dest == NULL)
		return(NULL);
	while (*s != c && *s != '\0')
		dest[i++] = *s++;
	dest[i] = '\0';
	return(dest);
}


char **ft_split(char const *s, char c)
{
	int	i;
	int	t;
	char **strs;

	i = 0;
	t = 1;
	if ((strs = malloc(sizeof(char *) * (ft_wc(s, c) + 1))) == NULL)
		return(NULL);
	while (*s)
	{
		if (*s != c && t == 1)
		{
			strs[i] = ft_putstr(s, c);
			t =  0;
			i++;
		}
		if (*s != c && *(s + 1) == c )
			t = 1;
		s++;
	}
	strs[i] = NULL;
	return(strs);
}
