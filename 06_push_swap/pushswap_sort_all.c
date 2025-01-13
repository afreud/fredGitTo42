
#include "pushswap.h"

void	ft_diff_ro(int idx_a, int idx_b, t_clist **lst_a, t_clist **lst_b)
{
	while (idx_a && idx_b)
	{
		ft_rr(lst_a, lst_b);
		--idx_a;
		--idx_b;
	}
	while (idx_a--)
		ft_ra(lst_a);
	while (idx_b > 1)
	{
		ft_rb(lst_b);
		idx_b--;
	}
	ft_pb(lst_a, lst_b);
	if ((*lst_a)->nb > (*lst_a)->next->nb && idx_b == 1)
		ft_ss(lst_a, lst_b);
	else if (idx_b == 1)
		ft_sb(lst_b, 1);
}

void	ft_diff_rro(int rpk0_a, int rpk0_b, t_clist **lst_a, t_clist **lst_b)
{
	while (rpk0_a && rpk0_b)
	{
		ft_rrr(lst_a, lst_b);
		--rpk0_a;
		--rpk0_b;
	}
	while (rpk0_a--)
		ft_rra(lst_a);
	while (rpk0_b--)
		ft_rrb(lst_b);
	ft_pb(lst_a, lst_b);
}

void	ft_diff(int pk0_a, int pk0_b, t_clist **lst_a, t_clist **lst_b)
{
	if (pk0_a > 0)
	{
		while (pk0_a--)
			ft_ra(lst_a);
		while (pk0_b++)
			ft_rrb(lst_b);
		ft_pb(lst_a, lst_b);
	}
	else
	{
		while (pk0_b--)
			ft_rb(lst_b);
		while (pk0_a++)
			ft_rra(lst_a);
		ft_pb(lst_a, lst_b);
	}
}

 static void	ft_final_push(t_clist **lst_a, t_clist **lst_b)
{
	int	lb;

	lb = ft_lstlen(*lst_b);
	while (lb--)
	{
		ft_pa(lst_a, lst_b);
	}
}

void	ft_sort_all(t_clist **lst_a, t_clist **lst_b)
{
	int	max_rank;

	max_rank = ft_lstlen(*lst_a);
	while (ft_lstlen(*lst_a) > 3 && !(ft_isa_ordered(*lst_a)))
	{
//		max_rank = (max_rank * 65) / 100;
//		max_rank = (max_rank * 10) / 100;
		max_rank = 3;
		if (max_rank < 3)
			max_rank = 3;
		ft_set_bool(*lst_a, max_rank);
		while (ft_sort_one(lst_a, lst_b))
			if (ft_isa_ordered(*lst_a))
				break ;
	}
	if (ft_lstlen(*lst_a) <= 3)
		ft_sort_small(lst_a, lst_b);
	else
		ft_reorder_a(lst_a, lst_b);
	if (*lst_b)
		ft_reorder_b(lst_b);
	ft_final_push(lst_a, lst_b);
}
