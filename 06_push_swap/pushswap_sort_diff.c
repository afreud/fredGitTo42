
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
	while (idx_b && idx_b > 1)
		ft_rb(lst_b);
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
