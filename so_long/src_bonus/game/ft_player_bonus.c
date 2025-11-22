/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:38:15 by ntome             #+#    #+#             */
/*   Updated: 2025/11/22 17:13:51 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/ft_so_long_bonus.h"

void	ft_check_camera_scroll(t_mlx *mlx, int tile_size)
{
	t_vec2	player_pos;
	t_vec2	camera_pos;
	t_vec2	window_center;
	int		line_len;

	window_center.x = mlx->window_size.x / tile_size;
	window_center.y = mlx->window_size.y / tile_size;
	line_len = ft_strlen(mlx->game_i.map.map[0]);
	camera_pos = mlx->game_i.camera_pos;
	player_pos.x = mlx->game_i.player_co.x * mlx->tile_size - camera_pos.x;
	player_pos.y = mlx->game_i.player_co.y * mlx->tile_size - camera_pos.y;
	if (player_pos.x >= mlx->window_size.x / 2 && mlx->game_i.player_dir == 1
		&& line_len - (camera_pos.x / tile_size) > window_center.x)
		mlx->game_i.camera_pos.x += mlx->tile_size;
	else if (player_pos.x <= mlx->window_size.x / 2
		&& mlx->game_i.player_dir == -1 && camera_pos.x > 0)
		mlx->game_i.camera_pos.x -= mlx->tile_size;
	if (player_pos.y >= mlx->window_size.y / 2 && mlx->game_i.player_dir == 2
		&& mlx->game_i.map.size - (camera_pos.y / tile_size) > window_center.y)
		mlx->game_i.camera_pos.y += mlx->tile_size;
	else if (player_pos.y <= mlx->window_size.y / 2
		&& mlx->game_i.player_dir == -2 && camera_pos.y > 0)
		mlx->game_i.camera_pos.y -= mlx->tile_size;
}

int	ft_count_total_coin(t_map map)
{
	t_vec2	read;
	int		count;

	count = 0;
	read.y = 0;
	while (map.map[read.y])
	{
		read.x = 0;
		while (map.map[read.y][read.x])
		{
			if (map.map[read.y][read.x] == COLLECTIBLE_TILE)
				count++;
			read.x++;
		}
		read.y++;
	}
	return (count);
}

void	ft_init_player(t_mlx *mlx)
{
	t_vec2	read;
	char	tile;

	read = (t_vec2){0, 0};
	tile = mlx->game_i.map.map[read.y][read.x];
	while (mlx->game_i.map.map[read.y] && tile != SPAWN_TILE)
	{
		read.x = 0;
		while (mlx->game_i.map.map[read.y][read.x] && tile != SPAWN_TILE)
		{
			tile = mlx->game_i.map.map[read.y][read.x];
			if (tile != SPAWN_TILE)
				read.x++;
		}
		if (tile != SPAWN_TILE)
			read.y++;
	}
	mlx->game_i.player_co = read;
	mlx->game_i.player_dir = 1;
	mlx->game_i.coin_collected = 0;
	mlx->game_i.coin_to_collect = ft_count_total_coin(mlx->game_i.map);
	mlx->game_i.move_count = 0;
}

void	ft_check_end_map(t_mlx *mlx)
{
	t_vec2	co;

	co.x = mlx->game_i.player_co.x;
	co.y = mlx->game_i.player_co.y;
	if (mlx->game_i.map.map[co.y][co.x] == EXIT_TILE)
	{
		if (mlx->game_i.coin_collected == mlx->game_i.coin_to_collect)
			mlx->page = END_PAGE;
	}
}

void	ft_move_player(t_mlx *mlx, int key)
{
	t_vec2	pos;
	int		move_y;
	int		move_x;

	if (key == KEY_Q)
		ft_attack(mlx);
	pos = mlx->game_i.player_co;
	move_y = 0 - (key == KEY_W) + (key == KEY_S);
	move_x = 0 - (key == KEY_A) + (key == KEY_D);
	if (mlx->game_i.map.map[pos.y + move_y][pos.x + move_x] != WALL_TILE)
	{
		mlx->game_i.player_co.y += move_y;
		mlx->game_i.player_co.x += move_x;
		mlx->game_i.move_count++;
		mlx->game_i.player_dir = 0 - (key == KEY_A) + (key == KEY_D);
		mlx->game_i.player_dir += 2 * (0 - (key == KEY_W) + (key == KEY_S));
	}
	if (mlx->game_i.map.map[pos.y + move_y][pos.x + move_x] == COLLECTIBLE_TILE)
	{
		mlx->game_i.coin_collected++;
		mlx->game_i.map.map[pos.y + move_y][pos.x + move_x] = FREE_SPACE_TILE;
	}
	ft_check_camera_scroll(mlx, mlx->tile_size);
	ft_check_end_map(mlx);
}
