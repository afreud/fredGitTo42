
#include "mt.h"

void	ft_eot(char *s, int *l, int pid)
{
	if (l)
	{
		write(1, s, *l);
		kill(pid, SIGUSR1);
		kill(pid, SIGUSR2);
		*l = 0;
	}
	else
	{
		if (s)
		{
			free(s);
			s = NULL;
		}
		exit(EXIT_SUCCESS);
	}
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
	char	*temp;

	if (!s)
		return (NULL);
	temp = malloc(sizeof(char) * (l + 1));
	if (!temp)
	{
		free(s);
		s = NULL;
		return (NULL);
	}
	ft_strlcpy(temp, s, l + 1);
	free(s);
	s = malloc(sizeof(char) * (l + 1 + 1024));
	if (s)
	{
		ft_bzero(s, sizeof(s));
		ft_strlcpy(s, temp, l + 1);
	}
	free(temp);
	temp = NULL;
	return (s);
}
