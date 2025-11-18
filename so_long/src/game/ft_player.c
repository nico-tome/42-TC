/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:38:15 by ntome             #+#    #+#             */
/*   Updated: 2025/11/19 00:34:22 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"

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

	read.y = 0;
	read.x = 0;
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
		{
			mlx->page = END_PAGE;
			mlx->need_update = TRUE;
		}
	}
}

void	ft_move_player(t_mlx *mlx, int key)
{
	t_vec2	pos;
	int		move_y;
	int		move_x;

	pos = mlx->game_i.player_co;
	move_y = 0 - (key == KEY_W) + (key == KEY_S);
	move_x = 0 - (key == KEY_A) + (key == KEY_D);
	if (mlx->game_i.map.map[pos.y + move_y][pos.x + move_x] != WALL_TILE)
	{
		mlx->game_i.player_co.y += move_y;
		mlx->game_i.player_co.x += move_x;
		mlx->need_update = TRUE;
		mlx->game_i.move_count++;
		mlx->game_i.player_dir = 0 - (key == KEY_A) + (key == KEY_D);
		mlx->game_i.player_dir += 2 * (0 - (key == KEY_W) + (key == KEY_S));
	}
	if (mlx->game_i.map.map[pos.y + move_y][pos.x + move_x] == COLLECTIBLE_TILE)
	{
		mlx->game_i.coin_collected++;
		mlx->game_i.map.map[pos.y + move_y][pos.x + move_x] = FREE_SPACE_TILE;
		mlx->need_update = TRUE;
	}
	ft_check_end_map(mlx);
}
