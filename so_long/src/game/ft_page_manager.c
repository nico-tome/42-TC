/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_page_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:29:49 by ntome             #+#    #+#             */
/*   Updated: 2025/11/19 23:35:05 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"

void	ft_render_end_page(t_mlx *mlx)
{
	char	*str;

	str = ft_strjoin("GG ! Moves count: ", ft_itoa(mlx->game_i.move_count));
	mlx_set_font(mlx->mlx, "default");
	mlx_set_font_scale(mlx->mlx, "default", 30);
	mlx_string_put(mlx->mlx, mlx->win, 50, 50,
		(mlx_color){.rgba = COLOR_GREEN}, str);
	mlx_string_put(mlx->mlx, mlx->win, 50, 100,
		(mlx_color){.rgba = COLOR_GREEN}, "Click to quit.");
	free(str);
}

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
	read.y = mlx->game_i.camera_pos.y / mlx->tile_size;
	while (mlx->game_i.map.map[read.y])
	{
		read.x = mlx->game_i.camera_pos.x / mlx->tile_size;
		coord.x = 0;
		tile = mlx->game_i.map.map[read.y][read.x];
		while (tile && coord.x < mlx->window_size.x)
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

	co.x = mlx->game_i.player_co.x * mlx->tile_size - mlx->game_i.camera_pos.x;
	co.y = mlx->game_i.player_co.y * mlx->tile_size - mlx->game_i.camera_pos.y;
	scale = ((double)mlx->tile_size / mlx->t_set.player_up.image_height);
	if (mlx->game_i.player_dir == 1)
		image = mlx->t_set.player_right.image;
	else if (mlx->game_i.player_dir == -1)
		image = mlx->t_set.player_left.image;
	else if (mlx->game_i.player_dir == -2)
		image = mlx->t_set.player_up.image;
	else if (mlx->game_i.player_dir == 2)
		image = mlx->t_set.player_down.image;
	mlx_put_transformed_image_to_window(mlx->mlx, mlx->win, image,
		co.x, co.y, scale, scale, 0);
}

void	ft_print_move_count(t_mlx *mlx)
{
	char	*count;
	char	*str;

	count = ft_itoa(mlx->game_i.move_count);
	str = ft_strjoin("moves count: ", count);
	mlx_string_put(mlx->mlx, mlx->win, 20, 720 - 50,
		(mlx_color){.rgba = COLOR_RED}, str);
	free(str);
	free(count);
}
