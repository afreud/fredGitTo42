
#include "pushswap.h"

struct clist;

int main(int argc, char **argv)
{
	t_clist *a;
	//t_clist *b;
	int	i;
	int n;

	i = 1;
	//b = NULL;
	a = ft_creat_list(argc, argv);
	if (!a)
		exit(EXIT_FAILURE);
	t_clist *cp_a = a;
	if (argc > 1 && argc < 4)
		ft_sort_small(argc, &a);
	while (i++ < argc)
	{
		n = cp_a->nb;
		printf("%d\n", n);
		cp_a = cp_a->next;
	}
	ft_clr_lst(&a);
	return (0);
}
