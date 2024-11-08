#include <stdlib.h>
#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set);

static int	ft_start(char const *s1, char const set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (set[j])
		{
			if (s1[i] != set[j])
				return(i);
			j++;
		}
		i++;
		j = 0;
	}
	return(i);
}

static int	ft_end(char const *s1, char const set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (i > 0)
	{
		while (set[j])
		{
			if (s1[i] != set[j])
				return(i);
			j++;
		}
		i--;
		j = 0;
	}
	return(i);

}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*d;
	int		start;
	int		end;

	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if ((d = malloc(sizeof(char) * (start - end + 1))) == NULL)
		return(NULL);
	while (start <= end)
		*d++ = s1[start++];
	*d = '\0';
	return(&d[0]);
}
