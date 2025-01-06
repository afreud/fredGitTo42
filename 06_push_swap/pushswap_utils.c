
#include "pushswap.h"

static t_clist	*ft_target(t_clist *a, t_clist *lst_b)
{
	t_clist	*current;
	t_clist	*buffer;
	t_clist	*target;
	int		min;

	if (!lst_b)
		return (NULL);
	current = lst_b;
	buffer = NULL;
	target = lst_b;
	min = lst_b->nb;
	if (ft_islower(a, lst_b))
		return (ft_wbigger(lst_b));
	while (buffer != lst_b)
	{
		buffer = current->next;
		if (a->nb > current->nb && current->nb > min)
		{
			min = current->nb;
			target = current;
		}
		current = buffer;
	}
	return (target);
}

static void	ft_cost(t_clist *a, t_clist *b)
{
	if (!b)
		a->push_cost = ft_abs(a->pk0);
	else if (a->pk0 <= 0 && b->pk0 <= 0)
	{
		if (a->pk0 <= b->pk0)
			a->push_cost = ft_abs(a->pk0);
		else
			a->push_cost = ft_abs(b->pk0);

	}
	else if (a->pk0 >= 0 && b->pk0 >= 0)
	{
		if (a->pk0 <= b->pk0)
			a->push_cost = b->pk0;
		else
			a->push_cost = a->pk0;
	}
	else
	{
		if (a->pk0 >= b->index)
			a->push_cost = a->pk0;
		else if (b->pk0 >= a->index)
			a->push_cost = b->pk0;
		if (a->pk0 < 0 && a->pk0 <= (b->pk0 - ft_lstlen(b)))
			a->push_cost = ft_abs(a->pk0);
		if (b->pk0 < 0 && b->pk0 <= (a->pk0 - ft_lstlen(a)))
			a->push_cost = ft_abs(b->pk0);
		else
			a->push_cost = ft_abs(a->pk0 - b->pk0);
	}
}

static void	ft_set_cost(t_clist *lst_a, t_clist *lst_b)
{
	t_clist	*current;
	t_clist *buffer;
	t_clist	*target;

	current = lst_a;
	buffer = NULL;
	target = NULL;
	while (buffer != lst_a)
	{
		buffer = current->next;
		target = ft_target(current, lst_b);
		ft_cost(current, target);
		current->target = target;
		current = buffer;
	}

}

t_clist *ft_tosend(t_clist *lst, t_clist *tgt_lst)
{
	t_clist	*current;
	t_clist	*buffer;
	t_clist	*tosend;

	if (!lst)
		return (NULL);
	ft_index2(lst, tgt_lst);
	ft_set_cost(lst, tgt_lst);
	current = lst;
	buffer = NULL;
	tosend = lst;
	while (buffer != lst)
	{
		buffer = current->next;
		if (current->push_cost < tosend->push_cost)
			tosend = current;
		current = buffer;
	}
	return (tosend);
}
