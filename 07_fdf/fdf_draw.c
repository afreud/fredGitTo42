
#include "fdf.h"

void	ft_get_pixel(t_img img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)pixel = color;
}

void	ft_draw_line(int *pt_start, int *pt_end, t_img img)
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
		pk = (2 * dy) - (2 * dx);
	else
		pk = (2 * dx) - (2 * dy);
	while (x <= pt_end[0] && y <= pt_end[1])
	{
		ft_get_pixel(img, x, y, colo);
		if (scope < 1)
		{
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
	}
}
