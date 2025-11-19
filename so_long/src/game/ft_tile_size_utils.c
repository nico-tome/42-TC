/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tile_size_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:24:53 by ntome             #+#    #+#             */
/*   Updated: 2025/11/20 00:23:49 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"

double	ft_get_best_size(t_vec2 map_size, t_vec2 window_size)
{
	double	size;

	if (map_size.x > map_size.y)
		size = (double)window_size.x / map_size.x;
	else
		size = (double)window_size.y / map_size.y;
	return (size);
}

void	ft_get_tile_size(t_mlx *mlx)
{
	t_vec2	map_size;
	t_vec2	window_size;
	double	size;

	map_size.x = ft_strlen(mlx->game_i.map.map[0]);
	map_size.y = mlx->game_i.map.size;
	mlx_get_window_size(mlx->mlx, mlx->win, &window_size.x, &window_size.y);
	size = ft_get_best_size(map_size, window_size);
	if (size < TILE_MIN_SIZE)
		mlx->tile_size = TILE_MIN_SIZE;
	else if (size > TILE_MAX_SIZE)
		mlx->tile_size = TILE_MAX_SIZE;
	else
		mlx->tile_size = size;
}
