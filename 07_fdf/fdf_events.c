#include "fdf.h"

int	ft_exit(t_xdata *xdata)
{
	mlx_destroy_image((*xdata).mlx, (*xdata).img.mlx_img);
	mlx_destroy_window((*xdata).mlx, (*xdata).mlx_win);
	mlx_destroy_display((*xdata).mlx);
	free((*xdata).mlx);
	ft_clrtab((*xdata).map.pts_2d);
	ft_clrtab((*xdata).map.pts_3d);
	free((*xdata).map.name);
	(*xdata).map.name = NULL;
	exit(EXIT_SUCCESS);
}

void	ft_rot(long **t3d, long **t2d, float add)
{
	long			x_tmp;
	long			y_tmp;
	int				i;
	static float	angle = 0;

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

void	ft_left(t_xdata *xdata)
{
	ft_rot((*xdata).map.pts_3d, (*xdata).map.pts_2d, 0.1);
	ft_center(&xdata->map);
	mlx_destroy_image((*xdata).mlx, (*xdata).img.mlx_img);
	(*xdata).img.mlx_img = mlx_new_image(xdata->mlx, WIN_X, WIN_Y);
	ft_pix2win(xdata);
	mlx_put_image_to_window((*xdata).mlx, (*xdata).mlx_win,
		(*xdata).img.mlx_img, 0, 0);
	mlx_string_put(xdata->mlx, xdata->mlx_win,
		20, 20, 0X00FFFFFF, (*xdata).map.name);
}

int	ft_key_input(int key, t_xdata *xdata)
{
	if (key == XK_Escape)
		ft_exit(xdata);
	if (key == XK_Right)
	{
		ft_rot((*xdata).map.pts_3d, (*xdata).map.pts_2d, -0.1);
		ft_center(&xdata->map);
		mlx_destroy_image((*xdata).mlx, (*xdata).img.mlx_img);
		(*xdata).img.mlx_img = mlx_new_image(xdata->mlx, WIN_X, WIN_Y);
		ft_pix2win(xdata);
		mlx_put_image_to_window((*xdata).mlx, (*xdata).mlx_win,
			(*xdata).img.mlx_img, 0, 0);
		mlx_string_put(xdata->mlx, xdata->mlx_win,
			20, 20, 0X00FFFFFF, (*xdata).map.name);
	}
	if (key == XK_Left)
		ft_left(xdata);
	return (0);
}

int	ft_no_event(t_xdata *xdata)
{
	(void)xdata;
	return (0);
}
