#include "fdf.h"

void	ft_exit(t_xdata *xdata)
{
	mlx_destroy_image((*xdata).mlx, (*xdata).img.mlx_img);
	mlx_destroy_window((*xdata).mlx, (*xdata).mlx_win);
    mlx_destroy_display((*xdata).mlx);
	free((*xdata).mlx);
	ft_clrtab((*xdata).map.pts_2d);
	ft_clrtab((*xdata).map.pts_3d);
	exit(EXIT_SUCCESS);
}

int ft_key_input(int key, t_xdata *xdata)
{
	if (key == XK_Escape)
		ft_exit(xdata);
	return (0);
}

int	ft_red_cross(t_xdata *xdata)
{
	mlx_destroy_image((*xdata).mlx, (*xdata).img.mlx_img);
	mlx_destroy_window((*xdata).mlx, (*xdata).mlx_win);
    mlx_destroy_display((*xdata).mlx);
	free((*xdata).mlx);
	ft_clrtab((*xdata).map.pts_2d);
	ft_clrtab((*xdata).map.pts_3d);
	return (0);
}

int ft_no_event(t_xdata *xdata)
{
	(void)xdata;
	return (0);
}
