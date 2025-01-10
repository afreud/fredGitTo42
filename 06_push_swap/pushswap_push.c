
#include "pushswap.h"

void	ft_pb(t_clist **list_a, t_clist **list_b)
{
	t_clist	*temp_a;

	if (!(*list_a))
		return ;
	temp_a = (*list_a)->next;
	(*list_a)->prev->next = (*list_a)->next;
	(*list_a)->next->prev = (*list_a)->prev;
	if (*list_b)
	{
		(*list_a)->next = (*list_b);
		(*list_a)->prev = (*list_b)->prev;
		(*list_b)->prev->next = (*list_a);
		(*list_b)->prev = (*list_a);
	}
	else
	{
		(*list_a)->next = *list_a;
		(*list_a)->prev = *list_a;
	}
	*list_b = *list_a;
	if (temp_a == *list_a)
		*list_a = NULL;
	else
		*list_a = temp_a;
	write(1, "pb\n", 3);
}

void	ft_pa(t_clist **list_a, t_clist **list_b)
{
	t_clist	*temp_b;

	if (!(*list_b))
		return ;
	temp_b = (*list_b)->next;
	(*list_b)->prev->next = (*list_b)->next;
	(*list_b)->next->prev = (*list_b)->prev;
	if (*list_a)
	{
		(*list_b)->next = (*list_a);
		(*list_b)->prev = (*list_a)->prev;
		(*list_a)->prev->next = (*list_b);
		(*list_a)->prev = (*list_b);
	}
	else
	{
		(*list_b)->next = *list_b;
		(*list_b)->prev = *list_b;
	}
	*list_a = *list_b;
	if (temp_b == *list_b)
		*list_b = NULL;
	else
		*list_b = temp_b;
	write(1, "pa\n", 3);
}
