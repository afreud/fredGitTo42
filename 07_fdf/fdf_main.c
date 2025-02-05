#include "fdf.h"

int main()
{
	void	*mlx;
	void	*mlx_win;
	char	*path = "42.fdf";
	int		**t2d;
	char	***pts = ft_init_pts(path);
	t_xdata 	xdata;
	t2d = ft_2d_points(pts);

	xdata.mlx = mlx_init();
	if (!xdata.mlx)
		return (MLX_ERROR);
	xdata.mlx_win = mlx_new_window(xdata.mlx, WIN_X, WIN_Y, "F.D.F.");
	if (!xdata.mlx_win)
	{
		free(xdata.mlx);
		return (MLX_ERROR);
	}
	xdata.img.mlx_img = mlx_new_image(mlx,WIN_X,WIN_Y);
	xdata.img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);

	mlx_loop_hook(xdata.mlx, &ft_no_event, &data);
	mlx_hook(xdata.mlx_win, KeyPress, KeyPressMask, &ft_key_input, &xdata);
	mlx_loop(xdata.mlx);

	mlx_destroy_image(mlx, xdata.img.mlx_img;
	free(xdata.img.mlx_img);
	free(xdata.img.addr);
    mlx_destroy_display(mlx);
	free(mlx);
	ft_clrtab(t2d);
	pts = ft_clean3(pts);
	return (0);
}
