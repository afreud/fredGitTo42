#include <stdlib.h>

void ft_lstclear(t_list **lst, void (*del)(void *));

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list **s_buffer;

	while (*lst)
	{
		s_buffer = lst;
		lst = &(*lst) -> next;
		(*del)(*s_buffer);
		free(*s_buffer);
	}
}
