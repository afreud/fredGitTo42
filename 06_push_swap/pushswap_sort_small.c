#include "pushswap.h"


static void	ft_sort2(t_clist **list_a)
{
	if ((*list_a)->nb > (*list_a)->next->nb)
			ft_sa(list_a);
}

static void	ft_sort3(t_clist **list_a)
{
	int a;
	int b;
	int c;

	a = (*list_a)->nb;
	b = (*list_a)->next->nb;
	c = (*list_a)->next->next->nb;
	if (a > b && a > c)
		ft_ra(list_a);
	else if (b > a && b > c)
		ft_rra(list_a);
	if ((*list_a)->nb > (*list_a)->next->nb)
		ft_sa(list_a);
}

void	ft_sort_small(int argc, t_clist **list_a)
{
	if (argc == 3)	
		ft_sort2(list_a);
	else if (argc == 4)
		ft_sort3(list_a);
}
