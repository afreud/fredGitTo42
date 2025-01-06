
#include "pushswap.h"

struct clist;

int main(int argc, char **argv)
{
	t_clist *a;
	t_clist *b;
	int	i;
	int n;

	i = 0;
	b = NULL;
	a = ft_creat_list(argc, argv);
	if (!a)
		exit(EXIT_FAILURE);
	t_clist *cp_a = a;
	if (argc > 1 && argc < 4)
		ft_sort_small(argc, &a);
	printf("A	Pk0\n");
	while (i++ < ft_lstlen(a))
	{
		n = cp_a->nb;
		printf("%d\n", n);
		n = cp_a->pk0;
		printf("	%d\n", n);
		cp_a = cp_a->next;
	}
	
	i = ft_lstlen(a);
	printf("\nlen A: %d\n", i);

	i = 0;
	ft_pb(&a, &b);
	n = b->nb;
	printf("\nB\n%d\n", n);

	ft_index(a);
	i = 0;
	cp_a = a;
	printf("\nA	Pk0\n");
	while (i++ < ft_lstlen(a))
	{
		n = cp_a->nb;
		printf("%d\n", n);
		n = cp_a->pk0;
		printf("	%d\n", n);
		cp_a = cp_a->next;
	}

	i = ft_lstlen(a);
	printf("\nlen A: %d\n", i);


	ft_clr_lst(&a);
	ft_clr_lst(&b);
	return (0);
}
