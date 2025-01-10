
#include "pushswap.h"

static void	ft_cmprank(t_clist *current, int *t)
{
	int n;
	int np;
	n = current->rank;
	np = current->prev->rank;
	n++;
	if (n != np)
		*t = 0;
}

bool	ft_isa_ordered(t_clist *lst)
{
	t_clist	*current;
	t_clist *buffer;
	t_clist *start;
	int		t;

	current = ft_wbigger(lst);
	start = current;
	buffer = NULL;
	t = 1;
	while (buffer != start && t)
	{
		buffer = current->prev;
		if (ft_islower(current, lst))
		{
			if (current->prev != start)
				t = 0;
		}
		else
			ft_cmprank(current, &t);
		current = buffer;
	}
	return (t);
}

void	ft_reorder_a(t_clist **lst_a)
{
	t_clist	*big;

	big = ft_wbigger(*lst_a);
	ft_index(*lst_a);
	while ((*lst_a)->prev != big)
	{
		if (big->pk0 > 0)
			ft_ra(lst_a);
		if (big->pk0 < 0)
			ft_rra(lst_a);
	}
}

void	ft_reorder_b(t_clist **lst_b)
{
	t_clist	*big;

	big = ft_wbigger(*lst_b);
	ft_index(*lst_b);
	while (big->pk0 > 0)
	{
		ft_rb(lst_b);
		(big->pk0)--;	
	}
	while (big->pk0 < 0)
	{
		ft_rrb(lst_b);
		(big->pk0)++;
	}
}

void	ft_final_push(t_clist **lst_a, t_clist **lst_b)
{
	int	lb;

	lb = ft_lstlen(*lst_b);
	while (lb--)
	{
		ft_pa(lst_a, lst_b);
	}
}
