
#include "pushswap.h"

struct clist;

void	ft_print_ab(t_clist *cp_a,t_clist *cp_b)
{
	int	i = 0;
	int n;
	t_clist *z;
	t_clist *w;

	z = ft_tosend(cp_a, cp_b);
	n = z->nb;
	printf("\n\nTo send: %d\n", n);
	w = ft_target(z, cp_b);
	n = w->nb;
	printf("Target: %d\n", n);

	printf("\nA	Pk0	Cost\n\n");
	while (i++ < ft_lstlen(cp_a))
	{
		n = cp_a->nb;
		printf("%d\n", n);
		n = cp_a->pk0;
		printf("	%d\n", n);
		n = cp_a->push_cost;
		printf("		%d\n", n);
		cp_a = cp_a->next;
	}
	i = 0;
	printf("\n\nB	Pk0\n");
	while (i++ < ft_lstlen(cp_b))
	{
		n = cp_b->nb;
		printf("%d\n", n);
		n = cp_b->pk0;
		printf("	%d\n", n);
		cp_b = cp_b->next;
	}

}
int main()
{
	t_clist *a;
	t_clist *b;
	char	*arga[] = { "8", "3", "2", "20", "200" "6", "7", "9", NULL};
	char	*argb[] = {"10", "5","4", "1", "13", NULL};

	a = ft_creat_list(2, arga);
	b = ft_creat_list(7, argb);
	if (!a)
		exit(EXIT_FAILURE);
//	if (argc > 1 && argc <= 4)
//		ft_sort_small(argc, &a);

	ft_print_ab(a, b);

	printf("\nCommands:\n--------\n");
	ft_sort_one(&a, &b);

	ft_print_ab(a, b);

	ft_clr_lst(&a);
	ft_clr_lst(&b);
	return (0);
}
