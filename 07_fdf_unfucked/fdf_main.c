#include "fdf.h"

int main(int ac, char **av)
{
	t_xdata 	xdata;

	if (ac < 2)
		exit(EXIT_FAILURE);
	ft_init(av[1], &xdata);
	ft_center(&(xdata).map);
	ft_pixels(&xdata);
	mlx_put_image_to_window(xdata.mlx, xdata.mlx_win, xdata.img.mlx_img, 0, 0);

	mlx_loop_hook(xdata.mlx, &ft_no_event, &xdata);
	mlx_hook(xdata.mlx_win, KeyPress, KeyPressMask, &ft_key_input, &xdata);
	mlx_hook(xdata.mlx_win, 33, 0, &ft_exit, &xdata);
	mlx_loop(xdata.mlx);
	return (0);
}
