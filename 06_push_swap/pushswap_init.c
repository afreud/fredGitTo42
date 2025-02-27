#include "pushswap.h"

static t_clist	*ft_clnew(int n)
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

static void	ft_cladd_back(t_clist **start, t_clist *new)
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

static t_clist	*ft_lstfill(char **strs)
{
	t_clist	*start;
	t_clist	*new;
	int		i;

	i = 0;
	start = NULL;
	new = NULL;
	while (strs[i])
	{
		new = ft_clnew(ft_atoi(strs[i]));
		ft_cladd_back(&start, new);
		i++;
	}
	return (start);
}

t_clist	*ft_creat_list(int argc, char **argv)
{
	t_clist	*start;
	char	**strs;

	start = NULL;
	strs = NULL;
	if (argc == 1)
		return (NULL);
	else
	{
		strs = ft_creatab(&argv[1]);
		if (strs && ft_args_ok(strs))
			start = ft_lstfill(strs);
		if (!strs || !strs[0])
			write(1, "Error\n", 6);
		strs = ft_clean2(strs);
	}
	if (start)
	{
		ft_index(start);
		ft_ranking(start);
	}
	return (start);
}
