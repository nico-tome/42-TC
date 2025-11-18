/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_texture_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 00:54:51 by ntome             #+#    #+#             */
/*   Updated: 2025/11/18 14:17:02 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"

t_grid	ft_get_wall_surroundings(t_mlx *mlx, t_vec2 read)
{
	t_grid	grid;

	if (read.y != 0)
		grid.n = mlx->game_i.map.map[read.y - 1][read.x] == WALL_TILE;
	else
		grid.n = 2;
	if (read.y != mlx->game_i.map.size - 1)
		grid.s = mlx->game_i.map.map[read.y + 1][read.x] == WALL_TILE;
	else
		grid.s = 2;
	if (read.x != 0)
		grid.o = mlx->game_i.map.map[read.y][read.x - 1] == WALL_TILE;
	else
		grid.o = 2;
	if (read.x != (int)ft_strlen(mlx->game_i.map.map[read.y]) - 1)
		grid.e = mlx->game_i.map.map[read.y][read.x + 1] == WALL_TILE;
	else
		grid.e = 2;
	return (grid);
}

t_texture	ft_get_wall_texture(t_mlx *mlx, t_vec2 read)
{
	t_grid	grid;

	grid = ft_get_wall_surroundings(mlx, read);
	if (grid.n == 2 && grid.e && !grid.s && grid.o)
		return (mlx->t_set.wall_n);
	if (grid.n && grid.e == 2 && grid.s && !grid.o)
		return (mlx->t_set.wall_e);
	if (!grid.n && grid.e && grid.s == 2 && grid.o)
		return (mlx->t_set.wall_s);
	if (grid.n && !grid.e && grid.s && grid.o == 2)
		return (mlx->t_set.wall_o);
	if (grid.n != 1 && grid.e && grid.s && grid.o != 1)
		return (mlx->t_set.wall_ne);
	if (grid.n != 1 && grid.e != 1 && grid.s && grid.o)
		return (mlx->t_set.wall_no);
	if (grid.n && grid.e && grid.s == 2 && grid.o == 2)
		return (mlx->t_set.wall_so);
	if (grid.n && grid.e == 2 && grid.s == 2 && grid.o)
		return (mlx->t_set.wall_se);
	if (grid.n == 2 && grid.e && grid.s && grid .o)
		return (mlx->t_set.wall_nt);
	if (grid.n && !grid.e && grid.s && !grid.o)
		return (mlx->t_set.wall_t_center);
	if (grid.n && !grid.e && !grid.s && !grid.o)
		return (mlx->t_set.wall_st);
	if (!grid.n && grid.e && !grid.s && grid.o)
		return (mlx->t_set.wall_c_center);
	if (!grid.n && !grid.e && !grid.s && grid.o)
		return (mlx->t_set.wall_c_right);
	if (!grid.n && grid.e && !grid.s && !grid.o)
		return (mlx->t_set.wall_c_left);
	return (mlx->t_set.wall_full);
}
