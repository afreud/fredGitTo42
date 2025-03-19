
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

void	ft_cladd_b(t_clist **start, t_clist *new)
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

void	ft_cladd_f(t_clist **start, t_clist *new)
{
	t_clist	*current;

	if (!(*start))
	{
		*start = new;
		return ;
	}
	new->next = *start;
	new->prev = (*start)->prev;
	(*start)->prev = new;
	*start = &new;
}

void	ft_clrm_b(t_clist **start)
{
	(*start)->prev->prev->next = *start;
	(*start)->prev = (*start)->prev->prev;
	start = &(*start)->prev;
	free(*start);
	start = NULL;
}

void	ft_clrm_f(t_clist **start)
{
	t_clist **buffer;

	buffer = start;
	(*start)->next->prev = (*start)->prev;
	(*start)->prev->next = (*start)->next;
	*start = (*start)->next;
	free(buffer);
	buffer = NULL;
}

void	ft_clclr(t_clist **lst)
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

int	ft_cllen(t_clist *lst)
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
