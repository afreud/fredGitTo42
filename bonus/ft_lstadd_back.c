#include <stdlib.h>

void ft_lstadd_back(t_list **lst, t_list *new);

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list **s_copy;

	s_copy = lst;
	while ((*s_copy) -> next != NULL)
		s_copy = &(*s_copy) -> next;
	(*s_copy) -> next = new;
}
