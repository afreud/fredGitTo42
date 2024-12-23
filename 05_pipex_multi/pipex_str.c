#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
		i++;
	}
	return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
}

char	*ft_cjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	if (!(s1) || !(s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	dest = malloc(sizeof(char) * len);
	if (dest == NULL)
		return (NULL);
	while (*s1)
		dest[i++] = *s1++;
	dest[i++] = '/';
	while (*s2)
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}
