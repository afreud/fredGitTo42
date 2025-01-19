#include "fdf.h"

int main()
{
//	void	*mlx;
//	void	*mlx_win;
	char	*path = "42.fdf";
	int		**t2d;

	char ***pts = ft_init_pts(path);
	t2d = ft_2d_points(pts);
//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "F.D.F.");
	int i=0, x=0, y=0;	///////////////////////
	printf("Points 2D\n-------\n");
	while (t2d[i])
	{
		x = t2d[i][0];
		y = t2d[i][1];
		printf("%d: %d,%d\n", i, x, y);
		i++;
	}
	ft_clrtab(t2d);
	pts = ft_clean3(pts);
	return (0);
}
