
#include "pushswap.h"

char	**ft_clean2(char **strs)
{
	int i;

	i = 0;
	if (strs)
	{
		while (strs[i])
		{
			free(strs[i]);
			strs[i] = NULL;
			i++;
		}
		free(strs);
	}
	return (NULL);
}

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

t_clist	*ft_lstfill(char **strs)
{
	t_clist	*start;
	t_clist	*new;
	int i;

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
//	if (ft_args_ko(argc, argv))
//		return (NULL);
	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		if (strs)
			start = ft_lstfill(strs);
		strs = ft_clean2(strs);
	}
	else
		start = ft_lstfill(&argv[1]);
	if (start)
	{
		ft_index(start);
		ft_ranking(start);
	}
	return (start);
}
