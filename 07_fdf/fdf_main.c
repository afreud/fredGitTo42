#include "fdf.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_xdata 	xdata;

	if (ac < 2)
		exit(EXIT_FAILURE);
	ft_init(av[1], &xdata);
	int **t3 = xdata.map.pts_3d;
	int	i=0;
	while (t3[i])
	{
		printf("%d: %d,%d\n", i, t3[i][0], t3[i][1]);
		i++;
	}
	ft_mlxexit(&xdata);
//	ft_pixels(&xdata);
//	mlx_put_image_to_window(xdata.mlx, xdata.mlx_win, xdata.img.mlx_img, 0, 0);
//	mlx_loop_hook(xdata.mlx, &ft_no_event, &xdata);
//	mlx_hook(xdata.mlx_win, KeyPress, KeyPressMask, &ft_key_input, &xdata);
//	mlx_loop(xdata.mlx);
	return (0);
}

