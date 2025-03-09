
#include "fdf.h"

float	ft_delta(t_map *map, int n)
{
	int	i;
	int	max;
	int	min;

	i = 0;
	min = INT_MAX;
	max = INT_MIN;
	while ((*map).pts_2d[i])
	{
		if ((*map).pts_2d[i][n] > max)
			max = (*map).pts_2d[i][n];
		if ((*map).pts_2d[i][n] < min)
			min = (*map).pts_2d[i][n];
		i++;
	}
	return (max - min);
}

int	ft_offset_x(t_map *map)
{
	int	i;
	int	max;
	int	min;
	int	moy;

	i = 0;
	min = INT_MAX;
	max = INT_MIN;
	while ((*map).pts_2d[i])
	{
		if ((*map).pts_2d[i][0] > max)
			max = (*map).pts_2d[i][0];
		if ((*map).pts_2d[i][0] < min)
			min = (*map).pts_2d[i][0];
		i++;
	}
	moy = (max + min) / 2;
	return ((WIN_X / 2) - moy);
}

int	ft_offset_y(t_map *map)
{
	int	i;
	int	max;
	int	min;
	int	moy;

	i = 0;
	min = INT_MAX;
	max = INT_MIN;
	while ((*map).pts_2d[i])
	{
		if ((*map).pts_2d[i][1] > max)
			max = (*map).pts_2d[i][1];
		if ((*map).pts_2d[i][1] < min)
			min = (*map).pts_2d[i][1];
		i++;
	}
	moy = (max + min) / 2;
	return ((WIN_Y / 2) - moy);
}

float	ft_scale(t_map *map)
{
	float	sx;
	float	sy;

	sx = (WIN_X * 80) / (ft_delta(map, 0) * 100);
	sy = (WIN_Y * 80) / (ft_delta(map, 1) * 100);
	if (sx < sy)
		return (sx);
	else
		return (sy);
}

void	ft_center(t_map *map)
{
	int		i;
	float	scale;
	int		offset_x;
	int		offset_y;

	i = 0;
	scale = ft_scale (map);
	while (map->pts_2d[i])
	{
		map->pts_2d[i][0] *= scale;
		map->pts_2d[i][1] *= scale;
		i++;
	}
	i = 0;
	offset_x = ft_offset_x(map);
	offset_y = ft_offset_y(map);
	while (map->pts_2d[i])
	{
		map->pts_2d[i][0] += offset_x;
		map->pts_2d[i][1] += offset_y;
		i++;
	}
}
