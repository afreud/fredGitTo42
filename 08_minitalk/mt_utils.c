
#include "mt.h"

void	ft_eot(char **s)
{
	if (*s)
	{
		write(1, "\nbye\n", 5);
		free(*s);
		*s = NULL;
	}
	exit(EXIT_SUCCESS);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*cptr;
	size_t	max;

	max = -1;
	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (size != 0 && nmemb > max / size)
		return (NULL);
	cptr = malloc(nmemb * size);
	if (cptr)
		ft_bzero(cptr, nmemb * size);
	return (cptr);
}

char	*ft_realloc(char *s, int l)
{
	char		*temp;
	static int	n = 1;

	if (!s)
	{
		write(1, "1er alloc\n", 10);
		s = ft_calloc((SIZE * n), sizeof(char));
		return (s);
	}
	if ((l + 2) == (SIZE * n))
	{
		write(1, "nvl alloc\n", 10);
		temp = ft_calloc((l + 1), sizeof(char));
		if (!temp)
		{
			free(s);
			return (NULL);
		}
		ft_strlcpy(temp, s, l + 1);
		free(s);
		s = ft_calloc((SIZE * ++n), sizeof(char));
		if (s)
			ft_strlcpy(s, temp, l + 1);
		free(temp);
		temp = NULL;
	}
	return (s);
}
