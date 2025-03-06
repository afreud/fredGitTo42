
#include "fdf.h"

float	ft_delta_x(t_map *map)
{
	int	i;
	int	max;
	int	min;

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
	return (max - min);
}

float	ft_delta_y(t_map *map)
{
	int	i;
	int	max;
	int	min;

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
	return (max - min);
}

float	ft_moy_x(t_map *map)
{
	int	i;
	int	max;
	int	min;

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
	return ((max + min) / 2);
}

float	ft_moy_y(t_map *map)
{
	int	i;
	int	max;
	int	min;

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
	return ((max + min) / 2);
}

float	ft_scale (t_map *map)
{
	float sx;
	float sy;

	sx = (WIN_X * 80) / (ft_delta_x(map) * 100);
	sy = (WIN_Y * 80) / (ft_delta_y(map) * 100);
	if (sx < sy)
		return (sx);
	else
		return (sy);
}

int	ft_offset_x(t_map *map)
{
	return (WIN_X / 2 - ft_moy_x(map) / 2);
}

int	ft_offset_y(t_map *map)
{
	return (WIN_Y / 2 - ft_moy_y(map) / 2);
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
