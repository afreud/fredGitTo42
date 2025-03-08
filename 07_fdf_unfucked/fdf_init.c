
#include "fdf.h"

static void	ft_prep(t_xdata *xdata)
{
	(*xdata).map.width = 0;
	(*xdata).map.height = 0;
	(*xdata).map.pts_3d = NULL;
	(*xdata).map.pts_2d = NULL;
	xdata->mlx = NULL;
	xdata->mlx_win = NULL;
	(*xdata).img.mlx_img = NULL;
	(*xdata).img.addr = NULL;
}

void	ft_mlxexit(t_xdata *xdata, int err, char ***s)
{
	if (s)
		ft_clean3(s);
	if ((*xdata).map.pts_3d)
		ft_clrtab((*xdata).map.pts_3d);
	if ((*xdata).map.pts_2d)
		ft_clrtab((*xdata).map.pts_2d);
	if ((*xdata).img.mlx_img)
		mlx_destroy_image(xdata->mlx, (*xdata).img.mlx_img);
	if (xdata->mlx_win)
		mlx_destroy_window(xdata->mlx, xdata->mlx_win);
	if (xdata->mlx)
	{
		mlx_destroy_display(xdata->mlx);
		free (xdata->mlx);
	}
	if (err < 0)
		perror("Problem creating array");
	else
		perror(strerror(err));
	exit(err);
}

static void	ft_init_map(char *path, t_xdata *xdata)
{
	char	***spts;

	spts = ft_spts(path);
	if (!spts)
	{
		perror("Problem map");
		exit(EXIT_FAILURE);
	}
	(*xdata).map.width = ft_width(spts);
	(*xdata).map.height = ft_len3(spts);
	if (!(*xdata).map.width || !(*xdata).map.height)
		ft_mlxexit(xdata, -1, spts);
	(*xdata).map.pts_3d = ft_3d_points(spts);
	if (!(*xdata).map.pts_3d)
		ft_mlxexit(xdata, -1, spts);
	(*xdata).map.pts_2d = ft_2d_points(spts, (*xdata).map.pts_3d);
	if (!(*xdata).map.pts_2d)
		ft_mlxexit(xdata, -1, spts);
	ft_clean3(spts);
	spts = NULL;
}

static void	ft_init_mlx(char *path, t_xdata *xdata)
{
	xdata->mlx = mlx_init();
	if (!xdata->mlx)
		ft_mlxexit(xdata, errno, NULL);
	xdata->mlx_win = mlx_new_window(xdata->mlx, WIN_X, WIN_Y, path);
	if (!xdata->mlx_win)
		ft_mlxexit(xdata, errno, NULL);
	(*xdata).img.mlx_img = mlx_new_image(xdata->mlx,WIN_X,WIN_Y);
	if (!(*xdata).img.mlx_img)
		ft_mlxexit(xdata, errno, NULL);
	(*xdata).img.addr = mlx_get_data_addr((*xdata).img.mlx_img, &(*xdata).img.bpp, &(*xdata).img.line_len, &(*xdata).img.endian);
	if (!(*xdata).img.addr)
		ft_mlxexit(xdata, errno, NULL);
}

void	ft_init(char *path, t_xdata *xdata)
{
	ft_prep(xdata);
	ft_init_map(path, xdata);
	ft_init_mlx(path, xdata);
}
