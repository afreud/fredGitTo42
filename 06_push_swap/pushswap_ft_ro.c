
#include "pushswap.h"

void	ft_ra(t_clist **list_a)
{
	*list_a = (*list_a)->next;
}

void	ft_rb(t_clist **list_b)
{
	*list_b = (*list_b)->next;
}

void	ft_rr(t_clist **list_a, t_clist **list_b)
{
	*list_a = (*list_a)->next;
	*list_b = (*list_b)->next;
}

void	ft_rra(t_clist **list_a)
{
	*list_a  = (*list_a)->prev;
}

void	ft_rrb(t_clist **list_b)
{
	*list_b  = (*list_b)->prev;
}

void	ft_rrr(t_clist **list_a, t_clist **list_b)
{
	*list_a  = (*list_a)->prev;
	*list_b  = (*list_b)->prev;
}
