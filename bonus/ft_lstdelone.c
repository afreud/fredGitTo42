#include <stdlib.h>

void ft_lstdelone(t_list *lst, void (*del)(void *));

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		(*del)(lst);
		free(lst -> content);
	}
}
