
#include "pushswap.h"

void	ft_pb(t_clist **list_a, t_clist **list_b)
{
	t_clist	*temp_a;

	temp_a = (*list_a)->next;
	(*list_a)->prev->next = (*list_a)->next;
	(*list_a)->next->prev = (*list_a)->prev;

	(*list_a)->next = (*list_b);
	(*list_a)->prev = (*list_b)->prev;

	(*list_b)->prev->next = (*list_a);
	(*list_b)->prev = (*list_a);

	*list_b = *list_a;
	*list_a = temp_a;
}

void	ft_pa(t_clist **list_a, t_clist **list_b)
{
	t_clist	*temp_b;

	temp_b = (*list_b)->next;
	(*list_b)->prev->next = (*list_b)->next;
	(*list_b)->next->prev = (*list_b)->prev;

	(*list_b)->next = (*list_a);
	(*list_b)->prev = (*list_a)->prev;

	(*list_a)->prev->next = (*list_b);
	(*list_a)->prev = (*list_b);

	*list_a = *list_b;
	*list_b = temp_b;
}
