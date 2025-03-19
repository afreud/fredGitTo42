#include <unistd.h>


void	print_bits(unsigned char octet)
{
	int i = 7;

	while (i >= 0)
	{
		if (octet & (1 << i))
			write(1,"1",1);
		else
			write(1, "0", 1);
		i--;
	}

}

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 0;
	int j = 7;
	unsigned char res;

	while (i < 8)
	{
		if (octet & 1 << i)
			res += 1 << j;
		i++;
		j--;
	}
	return (res);
}

unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	g = octet << 4;
	unsigned char	d = octet >> 4;
	
	return (g | d);
}


int main()
{
	unsigned char octet = 156;
	print_bits(octet);
	write(1, "\n", 1);
	octet = reverse_bits(octet);
	print_bits(octet);
	write(1, "\n", 1);
	octet = swap_bits(octet);
	print_bits(octet);
	write(1, "\n", 1);
}
