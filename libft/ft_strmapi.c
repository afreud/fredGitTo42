#include <stdlib.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int	i;

	i = 0;
	if ((str = malloc(sizeof(char) * ft_strlen(s) + 1)) == NULL)
		return(NULL);
	while (s[i] != '\0')
	{
		*str++ = *(f)(i, s[i]);
		i++;
	}
	return(&str[0]);
}
