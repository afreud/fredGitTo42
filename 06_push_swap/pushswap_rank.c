#include "pushswap.h"

static void	ft_rank0(t_clist *lst)
{
	t_clist	*current;
	t_clist	*buffer;

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
