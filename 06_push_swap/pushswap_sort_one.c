#include "pushswap.h"

static void	ft_sort_nl(t_clist *a, t_clist **lst, t_clist **tgt_lst)
{
	int	i;

	i = a->pk0;
	while (i > 0)
	{
		ft_ra(lst);
		i--;
	}
	while (i < 0)
	{
		ft_rra(lst);
		i++;
	}
	ft_pb(lst, tgt_lst);
}

static void	ft_sort_pos(t_clist *a, t_clist **lst, t_clist **tgt_lst)
{
	int	i;
	int	j;

	i = a->pk0;
	j = a->target->pk0;
	while (i && j)
	{
		ft_rr(lst, tgt_lst);
		i--;
		j--;
	}
	while (i--)
		ft_ra(lst);
	while (j > 1)
	{
		ft_rb(tgt_lst);
		j--;
	}
	ft_pb(lst, tgt_lst);
	if ((*lst)->nb > (*lst)->next->nb && j == 1)
		ft_ss(lst, tgt_lst);
	else if (j == 1)
		ft_sb(tgt_lst, 1);
}

static void	ft_sort_neg(t_clist *a, t_clist **lst, t_clist **tgt_lst)
{
	int	i;
	int	j;

	i = a->pk0;
	j = a->target->pk0;
	while (i && j)
	{
		ft_rrr(lst, tgt_lst);
		i++;
		j++;
	}
	while (i++)
		ft_rra(lst);
	while (j++)
		ft_rrb(tgt_lst);
	ft_pb(lst, tgt_lst);
}

static void	ft_sort_dif(t_clist *a, t_clist **lst, t_clist **tgt_lst)
{
	t_clist	*b;
	int		max_cost;
	int		rpk0_a;
	int		rpk0_b;

	b = a->target;
	max_cost = ft_abs(a->pk0 - b->pk0);
	rpk0_b = ft_lstlen(b) - b->index;
	rpk0_a = ft_lstlen(a) - a->index;
	if ((max_cost >= b->index) && (max_cost >= a->index))
		ft_diff_ro(a->index, b->index, lst, tgt_lst);
	else if ((max_cost > rpk0_b) && (max_cost > rpk0_a))
		ft_diff_rro(rpk0_a, rpk0_b, lst, tgt_lst);
	else
		ft_diff(a->pk0, b->pk0, lst, tgt_lst);
}

bool	ft_sort_one(t_clist **lst, t_clist **tgt_lst)
{
	t_clist	*tosend;

	tosend = ft_tosend(*lst, *tgt_lst);
	if (!tosend)
		return (0);
	if (tosend->target == NULL)
		ft_sort_nl(tosend, lst, tgt_lst);
	else if (tosend->pk0 >= 0 && tosend->target->pk0 >= 0)
		ft_sort_pos(tosend, lst, tgt_lst);
	else if (tosend->pk0 <= 0 && tosend->target->pk0 <= 0)
		ft_sort_neg(tosend, lst, tgt_lst);
	else
		ft_sort_dif(tosend, lst, tgt_lst);
	return (1);
}
