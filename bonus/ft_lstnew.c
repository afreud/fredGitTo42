#include <stdlib.h>

t_list *ft_lstnew(void *content);

t_list *ft_lstnew(void *content)
{
	t_list *s_new;

	s_new = (*struct s_list)malloc(sizeof(struct s_list));
	if (s_new = NULL)
		return(NULL);
	s_new -> content = content;
	s_new -> next = NULL;
	return(s_new);
}
