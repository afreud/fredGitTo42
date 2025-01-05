
#include "pushswap.h"

t_clist	*ft_clnew(int n)
{
	t_clist	*new;
	new = (t_clist *)malloc(sizeof(t_clist));
	if (new)
	{
		new->nb = n;
		new->next = new;
		new->prev = new;
	}
	return (new);
}

void	ft_cladd_back(t_clist **start, t_clist *new)
{
	t_clist	*current;

	if (!(*start))
	{
		*start = new;
		return ;
	}
	current = *start;
	while (current->next != *start)
		current = current->next;
	new->next = *start;
	new->prev = current;
	(*start)->prev = new;
	start = &current;
	(*start)->next = new;
}

t_clist	*ft_creat_list(int argc, char **argv)
{
	t_clist	*start;
	t_clist	*new;
	int i;

	i = 0;
	start = NULL;
	new = NULL;
	if (argc > 2)
	{
		while (argv[++i])
		{
			new = ft_clnew(ft_atoi(argv[i]));
			ft_cladd_back(&start, new);
		}
	}
	return (start);
}

