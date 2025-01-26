#include "pushswap.h"

static void	ft_sort2(t_clist **list_a)
{
	if ((*list_a)->nb > (*list_a)->next->nb)
		ft_sa(list_a, 1);
}

static void	ft_sort3(t_clist **l_a, t_clist **l_b)
{
	t_clist	*big;

	big = ft_wbigger(*l_b);
	ft_index2(*l_a, *l_b);
	if ((*l_a)->nb > (*l_a)->next->nb && (*l_a)->nb > (*l_a)->next->next->nb)
	{
		if (big && big->pk0 > 0)
			ft_rr(l_a, l_b);
		else
			ft_ra(l_a);
	}
	else if ((*l_a)->next->nb > (*l_a)->nb
		&& (*l_a)->next->nb > (*l_a)->next->next->nb)
	{
		if (big && big->pk0 < 0)
			ft_rrr(l_a, l_b);
		else
			ft_rra(l_a);
	}
	if ((*l_a)->nb > (*l_a)->next->nb)
		ft_sa(l_a, 1);
}

void	ft_sort_small(t_clist **list_a, t_clist **list_b)
{
	int	c;

	c = ft_lstlen(*list_a);
	if (c == 2)
		ft_sort2(list_a);
	else if (c == 3)
		ft_sort3(list_a, list_b);
}
