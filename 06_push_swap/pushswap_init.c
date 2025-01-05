
#include "pushswap.h"

void	ft_clr_lst(t_clist **lst)
{
	t_clist	*buffer;
	t_clist	*current;

	current = *lst;
	buffer = NULL;
	while(buffer != *lst)
	{
		buffer = current->next;
		current->next = NULL;
		current->prev = NULL;
		free(current);
		current = buffer;
	}
	*lst = NULL;
}

int	ft_lstlen(t_clist *lst)
{
	t_clist	*buffer;
	int	i;

	if (!lst)
		return (0);
	i = 1;
	buffer = lst->next;
	while (buffer != lst)
	{
		buffer = buffer->next;
		i++;
	}
	return (i);
	
}
