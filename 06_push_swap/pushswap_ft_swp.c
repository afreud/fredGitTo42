
#include "pushswap.h"

void	ft_sa(t_clist **list_a)
{
	t_clist	*buf_anext;
	t_clist	*buf_a;

	buf_anext = (*list_a)->next->next;
	buf_a = (*list_a)->next;
	(*list_a)->prev->next = (*list_a)->next;

	(*list_a)->next->next->prev = (*list_a);

	(*list_a)->next->next = (*list_a);
	(*list_a)->next->prev = (*list_a)->prev;

	(*list_a)->prev = (*list_a)->next;
	(*list_a)->next = buf_anext;
	
	*list_a = buf_a;
}

void	ft_sb(t_clist **list_b)
{
	t_clist	*buf_bnext;
	t_clist	*buf_b;

	buf_bnext = (*list_b)->next->next;
	buf_b = (*list_b)->next;
	(*list_b)->prev->next = (*list_b)->next;
	(*list_b)->next->next->prev = (*list_b);
	(*list_b)->next->next = (*list_b);
	(*list_b)->next->prev = (*list_b)->prev;
	(*list_b)->prev = (*list_b)->next;
	(*list_b)->next = buf_bnext;
	*list_b = buf_b;
}

void	ft_ss(t_clist **list_a, t_clist **list_b)
{
	ft_sa(list_a);
	ft_sb(list_b);
}
