
#include "fdf.h"

int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{

}

void	ft_draw_line(int *pt_start, int *pt_end)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	scope;
	int pk;

	x = pt_start[0];
	y = pt_start[1];
	dx = pt_end[0] - pt_start[0];
	dy = pt_end[1] - pt_start[1];
	scope = ft_abs(dy / dx);

	if (scope < 1)
	{
		pk = (2 * dy) - (2 * dx);
		if (dx > 0)
			x++;
		else
			x--;
		if (pk >= 0)
		{
			if (dy > 0)
				y++;
			else
				y--;
			pk += 2 * dy - 2 * dx;
		}
		else
			pk += 2 * dy;
	}
	else
	{
		pk = (2 * dx) - (2 * dy);
		if (dy > 0)
			y++;
		else
			y--;
		if (pk >= 0)
		{
			if (dx > 0)
				x++;
			else
				x--;
			pk += 2 * dx - 2 * dy;
		}
		else
			pk += 2 * dx;
	}
		while (x <= pt_end[0] && y <= pt_end[1])
		{
			mlx_pixel_put(ptr, win, x, y, colo);
			if (scope < 1)
			{

			}
			else
			{

			}
		}
}
