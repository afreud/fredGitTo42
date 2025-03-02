
#include "fdf.h"

static void	ft_add_pixel(t_img *img, int x, int y, int colo)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)pixel = colo;
}

static void	ft_scopeneg(int *x, int *y, int dx, int dy, int *pk)
{
	if (dx > 0)
		++*x;
	else
		--*x;
	if (*pk >= 0)
	{
		if (dy > 0)
			++*y;
		else
			--*y;
		*pk += 2 * dy - 2 * dx;
	}
	else
		*pk += 2 * dy;
}

static void	ft_scopepos(int *x, int *y, int dx, int dy, int *pk)
{
	if (dy > 0)
		++*y;
	else
		--*y;
	if (*pk >= 0)
	{
		if (dx > 0)
			++*x;
		else
			--*x;
		*pk += 2 * dx - 2 * dy;
	}
	else
		*pk += 2 * dx;
}

static void	ft_draw_line(int *pt_start, int *pt_end, t_img *img)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int pk;

	x = pt_start[0];
	y = pt_start[1];
	dx = pt_end[0] - pt_start[0];
	dy = pt_end[1] - pt_start[1];
	if (ft_abs(dy / dx) < 1)
		pk = (2 * dy) - (2 * dx);
	else
		pk = (2 * dx) - (2 * dy);
	ft_add_pixel(img, x, y, 0x00FF0000);
	while (x <= pt_end[0] && y <= pt_end[1])
	{
		if (ft_abs(dy / dx) < 1)
			ft_scopeneg(&x, &y, dx, dy, &pk);
		else
			ft_scopepos(&x, &y, dx, dy, &pk);
		ft_add_pixel(img, x, y, 0x00FF0000);
	}
}

void	ft_pixels(t_xdata *xdata)
{
	int	i;

	i = 0;
	while ((*xdata).map.pts_2d[i])
	{
		if ((*xdata).map.pts_2d[i][0] < (*xdata).map.width)
			ft_draw_line((*xdata).map.pts_2d[i], (*xdata).map.pts_2d[i + 1], &(*xdata).img);
		if ((*xdata).map.pts_2d[i][1] < (*xdata).map.height)
			ft_draw_line((*xdata).map.pts_2d[i], (*xdata).map.pts_2d[i + (*xdata).map.width], &(*xdata).img);
		i++;
	}
}

