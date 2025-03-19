#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		char	*s1 = argv[1];
		char	*s2 = argv[2];
		int	i = 0, j =0;
		while (s2[j])
		{
			while (s1[i] && s2[j] && s1[i] == s2[j])
			{
				i++;
				j++;
			}
			j++;
		}
		if (!s1[i])
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
