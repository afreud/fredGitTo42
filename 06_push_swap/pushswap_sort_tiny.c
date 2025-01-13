#include "pushswap.h"


static void	ft_sort2(t_clist **list_a)
{
	if ((*list_a)->nb > (*list_a)->next->nb)
		ft_sa(list_a, 1);
}

static void	ft_sort3(t_clist **list_a, t_clist **list_b)
{
	int		a;
	int		b;
	int		c;
	t_clist	*big;

	a = (*list_a)->nb;
	b = (*list_a)->next->nb;
	c = (*list_a)->next->next->nb;
	big = ft_wbigger(*list_b);
	ft_index2(*list_a, *list_b);
	if (a > b && a > c)
	{
		if (big && big->pk0 > 0)
			ft_rr(list_a, list_b);
		else
			ft_ra(list_a);
	}
	else if (b > a && b > c)
	{
		if (big && big->pk0 < 0)
			ft_rrr(list_a, list_b);
		else
			ft_rra(list_a);
	}
	if ((*list_a)->nb > (*list_a)->next->nb)
		ft_sa(list_a, 1);
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
