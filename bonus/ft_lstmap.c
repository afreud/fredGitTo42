#include <stdlib.h>
#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *s_newlst;
	t_list *s_current;
	t_list *s_buffer;

	s_newlst = (struct s_list *)malloc(sizeof(t_list));
	while (lst && s_newlst)
	{
		if ( ( s_current = ft_lstnew((*f)(lst)) ) == NULL );
			return(NULL);
		ft_lstadd_back(&s_newlst, s_current);
		s_buffer = lst;
		lst = lst -> next;
		(*del)(s_buffer);
		free(s_buffer);
	}
	return(s_newlst);
}
