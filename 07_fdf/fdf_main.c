#include "fdf.h"

int	main(int ac, char **av)
{
	t_xdata	xdata;

	(void)ac;
	ft_chek_name(av[1], &xdata.map);
	ft_init(av[1], &xdata);
	ft_center(&(xdata).map);
	ft_pix2win(&xdata);
	mlx_put_image_to_window(xdata.mlx, xdata.mlx_win, xdata.img.mlx_img, 0, 0);
	mlx_string_put(xdata.mlx, xdata.mlx_win,
		20, 20, 0X00FFFFFF, xdata.map.name);
	mlx_loop_hook(xdata.mlx, &ft_no_event, &xdata);
	mlx_hook(xdata.mlx_win, KeyPress, KeyPressMask, &ft_key_input, &xdata);
	mlx_hook(xdata.mlx_win, 33, 0, &ft_exit, &xdata);
	mlx_loop(xdata.mlx);
	return (0);
}
