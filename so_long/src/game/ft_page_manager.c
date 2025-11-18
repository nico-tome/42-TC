/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_page_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:29:49 by ntome             #+#    #+#             */
/*   Updated: 2025/11/18 01:35:56 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"

void	ft_draw_menu_page(t_mlx *mlx)
{
	mlx_color	color;
	t_vec2		coord;

	color.rgba = COLOR_BLUE;
	coord.y = 20;
	coord.x = mlx->window_size.x / 2 - ft_get_str_size("MAIN MENU", 16) / 2;
	ft_mlx_putstr(mlx, coord, color, "MAIN MENU");
}

void	ft_draw_settings_page(t_mlx *mlx)
{
	mlx_color	color;
	t_vec2		coord;

	color.rgba = COLOR_GREEN;
	coord.y = 20;
	coord.x = mlx->window_size.x / 2 - ft_get_str_size("SETTINGS", 16) / 2;
	ft_mlx_putstr(mlx, coord, color, "SETTINGS");
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
