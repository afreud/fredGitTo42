#include "pushswap.h"

static void	ft_cmprank(t_clist *current, int *t)
{
	int	n;
	int	np;

	n = current->rank;
	np = current->prev->rank;
	n++;
	if (n != np)
		*t = 0;
}

bool	ft_isa_ordered(t_clist *lst)
{
	t_clist	*current;
	t_clist	*buffer;
	t_clist	*start;
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

void	ft_rot_a(int t, t_clist *big_b, t_clist **lst_a, t_clist **lst_b)
{
		if (t == 1)
		{
			if (big_b && big_b->pk0 > 0)
			{
				ft_rr(lst_a, lst_b);
				(big_b->pk0)--;
			}
			else
				ft_ra(lst_a);
		}
		if (t == -1)
		{
			if (big_b && big_b->pk0 < 0)
			{
				ft_rrr(lst_a, lst_b);
				(big_b->pk0)++;
			}
			else
				ft_rra(lst_a);
		}

}

void	ft_reorder_a(t_clist **lst_a, t_clist **lst_b)
{
	t_clist	*big_a;
	t_clist	*big_b;

	big_a = ft_wbigger(*lst_a);
	big_b = ft_wbigger(*lst_b);
	ft_index2(*lst_a, *lst_b);
	while ((*lst_a)->prev != big_a)
	{
		if (big_a->pk0 > -1 && big_a->pk0 != (ft_lstlen(*lst_a) / 2))
		{
			ft_rot_a(1, big_b, lst_a, lst_b);
		}
		if (big_a->pk0 < -1 || big_a->pk0 == (ft_lstlen(*lst_a) / 2))
		{
			ft_rot_a(-1, big_b, lst_a, lst_b);
		}
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
