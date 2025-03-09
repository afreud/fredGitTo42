
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
		*pk += 2 * ft_abs(dy) - 2 * ft_abs(dx);
	}
	else
		*pk += 2 * ft_abs(dy);
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
		*pk += 2 * ft_abs(dx) - 2 * ft_abs(dy);
	}
	else
		*pk += 2 * ft_abs(dx);
}

void	ft_draw_line(int *pt_start, int *pt_end, t_img *img, int colo)
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
	if (ft_abs(dy) < ft_abs(dx))
		pk = (2 * ft_abs(dy)) - (2 * ft_abs(dx));
	else
		pk = (2 * ft_abs(dx)) - (2 * ft_abs(dy));
	ft_add_pixel(img, x, y, colo);
	while (x != pt_end[0] || y != pt_end[1])
	{
		if (ft_abs(dy) < ft_abs(dx))
		{
			ft_scopeneg(&x, &y, dx, dy, &pk);
		}
		else
		{
			ft_scopepos(&x, &y, dx, dy, &pk);
		}
		ft_add_pixel(img, x, y, colo);
	}
}

int	ft_colo(int z)
{
	z /= 30;
	if (z <= -3)
		return (0X000000FF);
	else if (z > -3 && z < 0)
		return (0x0000FF00);
	else if (z == 0)
		return (0X0000FF00);
	else if (z > 0 && z <= 2)
		return (0X00E7FF00);
	else if (z > 2 && z <= 4)
		return (0X00FF6C00);
	else if (z > 4 && z <= 7)
		return (0X00FF0000);
	else if (z > 7 && z <= 10)
		return (0X00FF0000);
	else
		return (0X00FF00FF);
}

void	ft_pixels(t_xdata *xdata)
{
	int	i;

	i = 0;
	while ((*xdata).map.pts_2d[i])
	{
		if ((i + 1) % (*xdata).map.width)
			ft_draw_line((*xdata).map.pts_2d[i], (*xdata).map.pts_2d[i + 1], &(*xdata).img, ft_colo((*xdata).map.pts_3d[i][2]));
		if ((i - 1) <  ((*xdata).map.height - 1) * (*xdata).map.width - 1)
			ft_draw_line((*xdata).map.pts_2d[i], (*xdata).map.pts_2d[i + (*xdata).map.width], &(*xdata).img, ft_colo((*xdata).map.pts_3d[i][2]));
		i++;
	}
}
