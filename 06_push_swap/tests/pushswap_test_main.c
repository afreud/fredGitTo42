
#include "pushswap.h"

struct clist;

void	ft_print_ab(t_clist *cp_a,t_clist *cp_b)
{
	int	i = 0;
	int n;
	t_clist *z;
	t_clist *w;

	if (cp_a)
	{
		ft_set_bool(cp_a, 3);
		z = ft_tosend(cp_a, cp_b);
		if (z)
		{
			n = z->nb;
			printf("\n\nTo send: %d\n", n);
		}
		if (cp_b && z)
		{
			w = ft_target(z, cp_b);
			n = w->nb;
			printf("Target: %d\n", n);
		}
	}

	printf("\nA	Rk	Bl\n\n");
	while ( cp_a && i++ < ft_lstlen(cp_a))
	{
		n = cp_a->nb;
		printf("%d\n", n);
		n = cp_a->rank;
		printf("	%d\n", n);
		n = cp_a->send;
		printf("		%d\n", n);
		cp_a = cp_a->next;
	}

}
int main(int argc, char **argv)
{
	t_clist *a;
	t_clist *b;

	a = ft_creat_list(argc, argv);
	b = NULL;
	if (!a)
		exit(EXIT_FAILURE);

//	ft_ranking(a);
//	ft_set_bool(a, (ft_lstlen(a) / 2));
//	ft_print_ab(a, b);
//	printf("\nCommands:\n--------\n");
	ft_sort_all(&a, &b);
//	ft_print_ab(a, b);

	ft_clr_lst(&a);
	ft_clr_lst(&b);
	return (0);
}
