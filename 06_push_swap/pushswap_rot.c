
#include "pushswap.h"

void	ft_ra(t_clist **list_a)
{
	*list_a = (*list_a)->next;
	write(1, "ra\n", 3);
}

void	ft_rb(t_clist **list_b)
{
	*list_b = (*list_b)->next;
	write(1, "rb\n", 3);
}

void	ft_rr(t_clist **list_a, t_clist **list_b)
{
	*list_a = (*list_a)->next;
	*list_b = (*list_b)->next;
	write(1, "rr\n", 3);
}

void	ft_rra(t_clist **list_a)
{
	*list_a  = (*list_a)->prev;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_clist **list_b)
{
	*list_b  = (*list_b)->prev;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_clist **list_a, t_clist **list_b)
{
	*list_a  = (*list_a)->prev;
	*list_b  = (*list_b)->prev;
	write(1, "rrr\n", 4);
}
