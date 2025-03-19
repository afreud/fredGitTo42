#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

void	ft_fill(char **tab, char target, t_point size, int x, int y)
{
	if (x < 0 || y < 0 || x >= size.x || y >= size.y)
		return ;
	if (tab[y][x] != target || tab[y][x] == 'F')
		return ;
	tab[y][x] = 'F';
	if (x + 1 < size.x && tab[y][x + 1] == target)
		ft_fill(tab, target, size, x + 1, y);
	if (x - 1 >= 0 && tab[y][x - 1] == target)
		ft_fill(tab, target, size, x - 1, y);
	if (y + 1 < size.y && tab[y + 1][x] == target)
		ft_fill(tab, target, size, x, y + 1);
	if (y - 1 >= 0 && tab[y - 1][x] == target)
		ft_fill(tab, target, size, x, y - 1);
}

void 	flood_fill(char **tab, t_point size, t_point begin)
{
	if (size.x == 0 || size.y == 0)
		return ;
	char target = tab[begin.y][begin.x];
	ft_fill(tab, target, size, begin.x, begin.y);
}

void	print_tab(char **s)
{
	int	i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			write(1, &s[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

char **make_area(char *zone[])
{
	char **s;
	int	i;
	int	j;

	i = 0;
	j = 0;
	s = malloc(sizeof(char **) * 6);
	while (i < 5)
	{
		s[i] = malloc(sizeof(char) * 9);
		j = 0;
		while (j < 8)
		{
			s[i][j] = zone[i][j];
			j++;
		}
		s[i][j] = '\0';
		i++;
	}
	s[i] = NULL;
	return (s);
}

//#include "test_functions.h"
//#include "flood_fill.h"
int main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
		NULL
	};
	area = make_area(zone);
	print_tab(area);
	printf("\n");
	printf("\n");
	printf("\n");
	flood_fill(area, size, begin);
	print_tab(area);
	int i = 0;
	while (area[i])
	{
		free(area[i]);
		area[i++] = NULL;
	}
	free(area);
	area = NULL;
	return (0);
}
