#include "pushswap.h"

void	ft_clr_lst(t_clist **lst)
{
	t_clist	*buffer;
	t_clist	*current;

	current = *lst;
	buffer = NULL;
	while (buffer != *lst)
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
	int		i;

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

t_clist	*ft_wbigger(t_clist *lst)
{
	t_clist	*current;
	t_clist	*buffer;
	t_clist	*big;

	current = lst;
	buffer = NULL;
	big = lst;
	while (buffer != lst)
	{
		buffer = current->next;
		if (current->nb > big->nb)
			big = current;
		current = buffer;
	}
	return (big);
}

void	ft_index(t_clist *lst)
{
	int	i;
	int	l;

	if (lst)
	{
		i = 0;
		l = ft_lstlen(lst);
		while (i < l)
		{
			lst->index = i;
			if (i <= l / 2)
				lst->pk0 = i;
			if (i > l / 2)
				lst->pk0 = i - l;
			lst = lst->next;
			i++;
		}
	}
}

void	ft_index2(t_clist *lst_a, t_clist *lst_b)
{
	ft_index(lst_a);
	ft_index(lst_b);
}
