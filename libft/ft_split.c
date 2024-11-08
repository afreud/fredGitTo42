#include <stdlib.h>

char **ft_split(char const *s, char c);

static int	ft_len(char *str)
{
	int c;

	c = 0;
	while (*str == c)
		str++;
	while (*str != c && *str != '\0')
	{
		c++;
		str++;
	}
	return(c);
}

static int	ft_wc(char *str, char c)
{
	int	i;
	int c;

	i = 0;
	c = 0;
	while (str[i] != '\0' )
	{
		if (str[i] != c && str[i + 1] == c)
			c++;
		else if (str[i] != c && str[i + 1] == '\0' )
			c++;
		i++;
	}
	return(c);

static char *ft_putstr(char *d, char *s, char c)
{
	int	i;

	i = 0;
	if ((d = malloc(sizeof(char) * (ft_len(s) + 1)) == NULL))
		return(NULL);
	while (*s != c && *s != '\0')
		d[i++] = *s++;
	d[i] = '\0';
	return(d);
}


char **ft_split(char const *s, char c)
{
	int	i;
	int	t;
	char * strs;

	i = 0;
	t = 1;
	if ((strs = malloc(sizeof(char *) * (ft_wc(s) + 1))) == NULL)
		return(NULL);
	while (*s)
	{
		if (*s != c && t = 1)
		{
			strs[i++] = ft_putstr(strs[i], s, c);
			t =  0;
		}
		if (*s != c && *(s + 1) == c )
			t = 1;
		s++;
	}
	strs[i] = NULL;
	return(strs);
}
