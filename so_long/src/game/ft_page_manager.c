/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_page_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:29:49 by ntome             #+#    #+#             */
/*   Updated: 2025/11/16 21:13:28 by ntome            ###   ########.fr       */
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

void	ft_render_tile(t_mlx *mlx, t_vec2 co, char tile, int t_s)
{
	mlx_color	*grid;
	mlx_image	image;

	grid = malloc(sizeof(mlx_color) * (t_s * t_s));
	if (grid)
	{
		if (tile == WALL_TILE)
			image = mlx->t_set.wall_n.image;
		else if (tile == SPAWN_TILE)
			image = mlx->t_set.spawn.image;
		else if (tile == EXIT_TILE)
			image = mlx->t_set.exit_close.image;
		else if (tile == COLLECTIBLE_TILE)
			image = mlx->t_set.coin.image;
		else if (tile == SPAWN_TILE)
			image = mlx->t_set.spawn.image;
		else
			image = mlx->t_set.ground.image;
		mlx_get_image_region(mlx->mlx, image, 0, 0, t_s, t_s, grid);
		mlx_pixel_put_region(mlx->mlx, mlx->win, co.x, co.y, t_s, t_s, grid);
	}
}

void	ft_render_map(t_mlx *mlx)
{
	t_vec2	coord;
	t_vec2	read;

	coord.y = 0;
	read.y = 0;
	while (mlx->game_i.map.map[read.y])
	{
		read.x = 0;
		coord.x = 0;
		while (mlx->game_i.map.map[read.y][read.x])
		{
			ft_render_tile(mlx, coord, mlx->game_i.map.map[read.y][read.x], 64);
			coord.x += 64;
			read.x++;
		}
		read.y++;
		coord.y += 64;
	}
}
