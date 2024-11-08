#include <stdlib.h>

t_list *ft_lstlast(t_list *lst);

t_list *ft_lstlast(t_list *lst)
{
	if (lst = NULL)
		return(lst);
	while (lst -> next != NULL)
		lst = lst -> next;
	return(lst);
}
