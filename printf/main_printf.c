
#include <stdio.h>
#include "ft_printf.h"

 int main()
{
	int	r;

	
	int		d = -1234;
	int		i = -1234;
	int		x = -1234;
	unsigned int u = 111;
	char	c = 'a';
	char	*s = "abcde";

	r = ft_printf("Me modulo : %%\n");
	printf("%d\n", r);
	r = printf("Org modulo : %%\n");
	printf("%d\n\n", r);

	r = ft_printf("Me s: %s\n", s);
	printf("%d\n", r);
	r = printf("Org s: %s\n", s);
	printf("%d\n\n", r);

	r = ft_printf("Me p: %p\n", s);
	printf("%d\n", r);
	r = printf("Org p: %p\n", s);
	printf("%d\n\n", r);

	r = ft_printf("Me c: %c \n", c);
	printf("%d\n", r);
	r = printf("Org c: %c \n", c);
	printf("%d\n\n", r);

	r = ft_printf("Me d: %d\n", d);
	printf("%d\n", r);
	r = printf("Org d: %d\n", d);
	printf("%d\n\n", r);

	r = ft_printf("Me i: %i\n", i);
	printf("%d\n", r);
	r = printf("Org i: %i\n", i);
	printf("%d\n\n", r);

	r = ft_printf("Me u: %u\n", u);
	printf("%d\n", r);
	r = printf("Org u: %u\n", u);
	printf("%d\n\n", r);

	r = ft_printf("Me x: %x\n", x);
	printf("%d\n", r);
	r = printf("Org x: %x\n", x);
	printf("%d\n\n", r);

	r = ft_printf("Me X: %X\n", x);
	printf("%d\n", r);
	r = printf("Org u: %X\n", x);
	printf("%d\n\n", r);
	return (0);
}
