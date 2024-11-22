
#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
 int main()
{
	int	r;

	
//	int		d = -1020;
//	int		i = -12340;
//	int		x = 45678;
	unsigned int u = 1;
//	char	c = '0';
	char	*s = "";

//	r = ft_printf("Me modulo : %%\n");
//	printf("%d\n", r);
//	r = printf("Org modulo : %%\n");
//	printf("%d\n\n", r);
//
//	r = ft_printf("Me s: %s\n", s);
//	printf("%d\n", r);
//	r = printf("Org s: %s\n", s);
//	printf("%d\n\n", r);
//
	r = ft_printf("Me p: %p\n", -1);
	printf("%d\n", r);
	r = printf("Org p: %p\n", -1);
	printf("%d\n\n", r);

//	r = ft_printf("Me c: %c \n", c);
//	printf("%d\n", r);
//	r = printf("Org c: %c \n", c);
//	printf("%d\n\n", r);
//
//	r = ft_printf("Me d: %d\n", d);
//	printf("%d\n", r);
//	r = printf("Org d: %d\n", d);
//	printf("%d\n\n", r);
//
//	r = ft_printf("Me i: %i\n", i);
//	printf("%d\n", r);
//	r = printf("Org i: %i\n", i);
//	printf("%d\n\n", r);
//
	r = ft_printf("Me u: %u\n", -1);
	printf("%d\n", r);
	r = printf("Org u: %u\n", -1);
	printf("%d\n\n", r);

//	r = ft_printf("Me x: %x\n", x);
//	printf("%d\n", r);
//	r = printf("Org x: %x\n", x);
//	printf("%d\n\n", r);
//
//	r = ft_printf("Me X: %X\n", x);
//	printf("%d\n", r);
//	r = printf("Org u: %X\n", x);
//	printf("%d\n\n", r);
//
//	r = ft_printf("%s", "");
//	printf("%d\n", r);
//	printf("\n");
//	printf("\n");
//
//	r = printf("%s", "");
//	printf("%d\n", r);
//	printf("\n");
//	printf("\n");
//
	r = ft_printf(" NULL %s NULL ", NULL);
	printf("\n");
	printf("%d\n", r);
	printf("\n");
	r = printf(" NULL %s NULL ", NULL);
	printf("\n");
	printf("%d\n", r);
	printf("\n");
	
	printf("p LG_min LG_max\n");
	r = printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("\n");
	printf("%d\n", r);
	printf("\n");
	r = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("\n");
	printf("%d\n", r);
	printf("\n");

	printf("p ULG_max -ULG_max\n");
	r = printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	printf("\n");
	printf("%d\n", r);
	printf("\n");
	r = ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	printf("\n");
	printf("%d\n", r);
	printf("\n");

	printf("u LONG_MAX\n");
	r = printf(" %u ", LONG_MAX);
	printf("\n");
	printf("%d\n", r);
	r = ft_printf(" %u ", LONG_MAX);
	printf("\n");
	printf("%d\n", r);
	printf("\n");

	printf("u LONG_MIN\n");
	r = printf(" %u ", LONG_MIN);
	printf("\n");
	printf("%d\n", r);
	r = ft_printf(" %u ", LONG_MIN);
	printf("\n");
	printf("%d\n", r);
	printf("\n");

	printf("u ULG_max\n");
	r = printf(" %u ", ULONG_MAX);
	printf("\n");
	printf("%d\n", r);
	r = ft_printf(" %u ", ULONG_MAX);
	printf("\n");
	printf("%d\n", r);
	printf("\n");

	printf("9223372036854775807LL\n");
	r = printf(" %u ", 9223372036854775807LL);
	printf("\n");
	printf("%d\n", r);
	r = ft_printf(" %u ", 9223372036854775807LL);
	printf("\n");
	printf("%d\n", r);
	printf("\n");

	r = printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n");
	printf("%d\n", r);
	r = ft_printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n");
	printf("%d\n", r);
	printf("\n");


	return (0);
}
