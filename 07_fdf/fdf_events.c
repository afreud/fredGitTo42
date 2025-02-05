#include "fdf.h"

int ft_key_input(int key, t_xdata *xdata)
{
	if (key == XK_Escape)
		mlx_destroy_window(xdata->mlx, xdata->mlx_win);
	return (0);
}

int ft_no_event(t_xdata *xdata)
{
	return (0);
}
