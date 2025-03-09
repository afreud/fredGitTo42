#include "fdf.h"

int	ft_exit(t_xdata *xdata)
{
	mlx_destroy_image((*xdata).mlx, (*xdata).img.mlx_img);
	mlx_destroy_window((*xdata).mlx, (*xdata).mlx_win);
    mlx_destroy_display((*xdata).mlx);
	free((*xdata).mlx);
	ft_clrtab((*xdata).map.pts_2d);
	ft_clrtab((*xdata).map.pts_3d);
	exit(EXIT_SUCCESS);
}
void	ft_rot(int **t3d, int **t2d, float add)
{
	int			x_tmp;
	int			y_tmp;
	int			i;
	static	float	angle = 0;

	i = 0;
	angle += add;
	if (angle > 360)
		angle -= 360;
	if (angle < -360)
		angle += 360;
	while (t3d[i])
	{
		x_tmp = (t3d[i][0] * cos(angle)) - (t3d[i][1] * sin(angle));
		y_tmp = (t3d[i][0] * sin(angle)) + (t3d[i][1] * cos(angle));
		t2d[i][0] = (x_tmp - y_tmp) * cos(0.523599);
		t2d[i][1] = (x_tmp + y_tmp) * sin(0.523599) - t3d[i][2];
		i++;
	}
}

int ft_key_input(int key, t_xdata *xdata)
{
	if (key == XK_Escape)
		ft_exit(xdata);
	if (key == XK_Right)
	{
		ft_rot((*xdata).map.pts_3d, (*xdata).map.pts_2d, 0.1);
		ft_center(&xdata->map);
		mlx_destroy_image((*xdata).mlx, (*xdata).img.mlx_img);
		(*xdata).img.mlx_img = mlx_new_image(xdata->mlx,WIN_X,WIN_Y);
		ft_pixels(xdata);
		mlx_put_image_to_window((*xdata).mlx, (*xdata).mlx_win, (*xdata).img.mlx_img, 0, 0);
	}
	if (key == XK_Left)
	{
		ft_rot((*xdata).map.pts_3d, (*xdata).map.pts_2d, -0.1);
		ft_center(&xdata->map);
		mlx_destroy_image((*xdata).mlx, (*xdata).img.mlx_img);
		(*xdata).img.mlx_img = mlx_new_image(xdata->mlx,WIN_X,WIN_Y);
		ft_pixels(xdata);
		mlx_put_image_to_window((*xdata).mlx, (*xdata).mlx_win, (*xdata).img.mlx_img, 0, 0);
	}
	return (0);
}

int ft_no_event(t_xdata *xdata)
{
	(void)xdata;
	return (0);
}
