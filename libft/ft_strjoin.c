#include <stdlib.h>

char *ft_strjoin(char const *s1, char const *s2);

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((dest = malloc(sizeof(char) * len)) == NULL)
		return(NULL);
	while (*s1)
		*dest++ = *s1++;
	while (*s2)
		*dest++ = *s2++;
	dest = '\0';
	return(dest);
}
