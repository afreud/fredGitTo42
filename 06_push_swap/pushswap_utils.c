#include "pushswap.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nbr;
	int	c;

	i = 0;
	nbr = 0;
	c = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		c = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nbr *= 10;
		nbr += (nptr[i] - 48);
		i++;
	}
	return (nbr * c);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
		i++;
	}
	return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

bool	ft_islower(t_clist *a, t_clist *tgt_lst)
{
	t_clist	*current;
	t_clist	*buffer;
	bool	min;

	current = tgt_lst;
	buffer = NULL;
	min = 1;
	while (buffer != tgt_lst)
	{
		buffer = current->next;
		if (a->nb > current->nb)
			min = 0;
		current = buffer;
	}
	return (min);
}
