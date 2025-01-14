
#include "pushswap.h"

int main(int argc, char **argv)
{
	t_clist *a;
	t_clist *b;

	a = ft_creat_list(argc, argv);
	b = NULL;
	if (!a)
		exit(EXIT_FAILURE);
	ft_sort_all(&a, &b);
	ft_clr_lst(&a);
	ft_clr_lst(&b);
	return (0);
}
