
#include "fdf.h"

static void	ft_add_pixel(t_img *img, int x, int y, int colo)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = colo;
}

static void	ft_scopeneg(int *x, int *y, int *delta, int *pk)
{
	if (delta[0] > 0)
		++*x;
	else
		--*x;
	if (*pk >= 0)
	{
		if (delta[1] > 0)
			++*y;
		else
			--*y;
		*pk += 2 * ft_abs(delta[1]) - 2 * ft_abs(delta[0]);
	}
	else
		*pk += 2 * ft_abs(delta[1]);
}

static void	ft_scopepos(int *x, int *y, int *delta, int *pk)
{
	if (delta[1] > 0)
		++*y;
	else
		--*y;
	if (*pk >= 0)
	{
		if (delta[0] > 0)
			++*x;
		else
			--*x;
		*pk += 2 * ft_abs(delta[0]) - 2 * ft_abs(delta[1]);
	}
	else
		*pk += 2 * ft_abs(delta[0]);
}

void	ft_draw_line(long *pt_start, long *pt_end, t_img *img, int colo)
{
	int	x;
	int	y;
	int	delta[2];
	int	pk;

	x = (int)pt_start[0];
	y = (int)pt_start[1];
	delta[0] = (int)pt_end[0] - (int)pt_start[0];
	delta[1] = (int)pt_end[1] - (int)pt_start[1];
	if (ft_abs(delta[1]) < ft_abs(delta[0]))
		pk = (2 * ft_abs(delta[1])) - (2 * ft_abs(delta[0]));
	else
		pk = (2 * ft_abs(delta[0])) - (2 * ft_abs(delta[1]));
	ft_add_pixel(img, x, y, colo);
	while (x != pt_end[0] || y != pt_end[1])
	{
		if (ft_abs(delta[1]) < ft_abs(delta[0]))
			ft_scopeneg(&x, &y, delta, &pk);
		else
			ft_scopepos(&x, &y, delta, &pk);
		ft_add_pixel(img, x, y, colo);
	}
}

void	ft_pix2win(t_xdata *xdata)
{
	int	i;

	i = 0;
	while ((*xdata).map.pts_2d[i])
	{
		if ((i + 1) % (*xdata).map.width)
			ft_draw_line((*xdata).map.pts_2d[i], (*xdata).map.pts_2d[i + 1],
				&(*xdata).img, ft_colo((*xdata).map.pts_3d[i][2]));
		if ((i - 1) < ((*xdata).map.height - 1) * (*xdata).map.width - 1)
			ft_draw_line((*xdata).map.pts_2d[i],
				(*xdata).map.pts_2d[i + (*xdata).map.width],
				&(*xdata).img, ft_colo((*xdata).map.pts_3d[i][2]));
		i++;
	}
}
