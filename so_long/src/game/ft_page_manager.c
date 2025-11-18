/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_page_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:29:49 by ntome             #+#    #+#             */
/*   Updated: 2025/11/18 22:31:54 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"

void	ft_render_tile(t_mlx *mlx, t_vec_d2 co, char tile, t_vec2 read)
{
	mlx_image	image;
	t_texture	texture;
	double		size;

	if (tile == WALL_TILE)
		texture = ft_get_wall_texture(mlx, read);
	else if (tile == SPAWN_TILE)
		texture = mlx->t_set.spawn;
	else if (tile == EXIT_TILE
		&& mlx->game_i.coin_to_collect == mlx->game_i.coin_collected)
		texture = mlx->t_set.exit_open;
	else if (tile == EXIT_TILE)
		texture = mlx->t_set.exit_close;
	else if (tile == COLLECTIBLE_TILE)
		texture = mlx->t_set.coin;
	else if (tile == SPAWN_TILE)
		texture = mlx->t_set.spawn;
	else
		texture = mlx->t_set.ground;
	image = texture.image;
	size = ((double)mlx->tile_size / texture.image_height);
	mlx_put_transformed_image_to_window(mlx->mlx, mlx->win, image,
		co.x, co.y, size, size, 0);
}

void	ft_render_map(t_mlx *mlx)
{
	t_vec_d2	coord;
	t_vec2		read;
	char		tile;

	coord.y = 0;
	read.y = 0;
	while (mlx->game_i.map.map[read.y])
	{
		read.x = 0;
		coord.x = 0;
		while (mlx->game_i.map.map[read.y][read.x])
		{
			tile = mlx->game_i.map.map[read.y][read.x];
			ft_render_tile(mlx, coord, tile, read);
			coord.x += mlx->tile_size;
			read.x++;
		}
		read.y++;
		coord.y += mlx->tile_size;
	}
}

void	ft_render_player(t_mlx *mlx)
{
	t_vec_d2	co;
	double		scale;
	mlx_image	image;

	co.x = mlx->game_i.player_co.x * mlx->tile_size;
	co.y = mlx->game_i.player_co.y * mlx->tile_size;
	scale = ((double)mlx->tile_size / mlx->t_set.player.image_height);
	image = mlx->t_set.player.image;
	mlx_put_transformed_image_to_window(mlx->mlx, mlx->win, image,
		co.x, co.y, scale, scale, 0);
}

void	ft_print_move_count(t_mlx *mlx)
{
	char	*count;

	count = ft_itoa(mlx->game_i.move_count);
	mlx_string_put(mlx->mlx, mlx->win, 20, mlx->window_size.y - 50,
		(mlx_color){.rgba = COLOR_RED}, count);
	free(count);
}
