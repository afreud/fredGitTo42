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
		nbr += (nptr[i] - 48) % 10;
		i++;
	}
	return (nbr * c);
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
		current =buffer;
	}
	return (min);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

t_clist	*ft_wbigger(t_clist *lst)
{
	t_clist	*current;
	t_clist	*buffer;
	t_clist	*big;

	current = lst;
	buffer = NULL;
	big = lst;
	while (buffer != lst)
	{
		buffer = current->next;
		if (current->nb > big->nb)
			big = current;
		current = buffer;
	}
	return (big);
}

static void	ft_rank0(t_clist *lst)
{
	t_clist	*current;
	t_clist *buffer;

	current = lst;
	buffer = NULL;
	while (buffer != lst)
	{
		buffer = current->next;
		current->rank = 0;
		current = buffer;
	}
}

static t_clist	*ft_find2rank(t_clist *lst)
{
	t_clist	*current;
	t_clist	*buffer;
	t_clist	*tosend;
	
	current = lst;
	buffer = NULL;
	while (current->rank)
		current = current->next;
	tosend = current;
	while (buffer != lst)
	{
		buffer = current->next;
		if (!(current->rank) && current->nb < tosend->nb)
			tosend = current;
		current = buffer;
	}
	return (tosend);
}

void	ft_ranking(t_clist *lst)
{
	t_clist	*buffer;
	int		l;

	l = ft_lstlen(lst);
	ft_rank0(lst);
	buffer = NULL;
	while (l)
	{
		buffer = ft_find2rank(lst);
		buffer->rank = l;
		l--;
	}
}

void	ft_set_bool(t_clist *lst, int max_rank)
{
	t_clist	*current;
	t_clist	*buffer;

	current = lst;
	buffer = NULL;
	while (buffer != lst)
	{
		buffer = current->next;
		if (current->rank > max_rank)
			current->send = 1;
		else
			current->send = 0;
		current = buffer;
	}
}
