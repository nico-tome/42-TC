/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tile_size_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:24:53 by ntome             #+#    #+#             */
/*   Updated: 2025/11/20 13:52:00 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"

double	ft_get_best_size(t_vec2 map_size, t_vec2 window_size)
{
	double	size;

	if (map_size.x / window_size.x > map_size.y / window_size.y)
		size = floor((double)window_size.x / map_size.x);
	else
		size = floor((double)window_size.y / map_size.y);
	return (size);
}

double	ft_get_tile_size(t_mlx *mlx)
{
	t_vec2	map_size;
	t_vec2	window_size;
	double	tile_size;

	map_size.x = ft_strlen(mlx->game_i.map.map[0]);
	map_size.y = mlx->game_i.map.size;
	mlx_get_window_size(mlx->mlx, mlx->win, &window_size.x, &window_size.y);
	tile_size = ft_get_best_size(map_size, window_size);
	if (tile_size < TILE_MIN_SIZE)
		tile_size = TILE_MIN_SIZE;
	else if (tile_size > TILE_MAX_SIZE)
		tile_size = TILE_MAX_SIZE;
	return (tile_size);
}

void	ft_init_camera_pos(t_mlx *mlx)
{
	double	line_len;
	t_vec2	spawn;
	t_vec2	window_size;
	t_map	map;
	int		tile_size;

	tile_size = mlx->tile_size;
	map = mlx->game_i.map;
	line_len = ft_strlen(mlx->game_i.map.map[0]) * mlx->tile_size;
	spawn = mlx->game_i.player_co;
	window_size = mlx->window_size;
	if (spawn.x * mlx->tile_size > mlx->window_size.x)
	{
		if (spawn.x * mlx->tile_size >= line_len - mlx->window_size.x)
			mlx->game_i.camera_pos.x = line_len - mlx->window_size.x;
		else
			mlx->game_i.camera_pos.x = spawn.x * mlx->tile_size;
	}
	if (spawn.y * mlx->tile_size > mlx->window_size.y)
	{
		if (spawn.y * mlx->tile_size >= map.size * tile_size - window_size.y)
			mlx->game_i.camera_pos.y = map.size * tile_size - window_size.y;
		else
			mlx->game_i.camera_pos.y = spawn.y * mlx->tile_size;
	}
}
