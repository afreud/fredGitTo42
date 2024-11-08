
void ft_lstiter(t_list *lst, void (*f)(void *));

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst);
		lst = lst -> next;
	}
}
