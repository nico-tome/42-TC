/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:13:00 by ntome             #+#    #+#             */
/*   Updated: 2025/11/22 17:24:03 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/ft_so_long_bonus.h"

int	ft_count_enemys(t_mlx *mlx)
{
	t_vec2	read;
	int		count;

	count = 0;
	read = (t_vec2){.x = 0, .y = 0};
	while (mlx->game_i.map.map[read.y])
	{
		read.x = 0;
		while (mlx->game_i.map.map[read.y][read.x])
		{
			if (mlx->game_i.map.map[read.y][read.x] == ENEMY_H
				|| mlx->game_i.map.map[read.y][read.x] == ENEMY_V)
				count++;
			read.x++;
		}
		read.y++;
	}
	return (count);
}

void	ft_load_enemys(t_mlx *mlx, t_map map)
{
	t_vec2	read;
	int		count;

	mlx->game_i.enemys_count = ft_count_enemys(mlx);
	mlx->game_i.enemys = malloc(sizeof(t_enemy) * (ft_count_enemys(mlx) + 1));
	if (!mlx->game_i.enemys)
		return ;
	read.y = 0;
	count = 0;
	while (map.map[read.y])
	{
		read.x = 0;
		while (map.map[read.y][read.x])
		{
			if (ft_strchr(ENEMYSET, map.map[read.y][read.x]))
			{
				mlx->game_i.enemys[count].dead = 0;
				mlx->game_i.enemys[count].pos = read;
				mlx->game_i.enemys[count].type = map.map[read.y][read.x];
				mlx->game_i.enemys[count++].vel = 1;
			}
			read.x++;
		}
		read.y++;
	}
}

void	ft_render_enemy(t_mlx *mlx, int enemy_i)
{
	t_vec_d2	co;
	double		scale;
	mlx_image	image;
	t_enemy		enemy;

	enemy = mlx->game_i.enemys[enemy_i];
	co.x = enemy.pos.x * mlx->tile_size - mlx->game_i.camera_pos.x;
	co.y = enemy.pos.y * mlx->tile_size - mlx->game_i.camera_pos.y;
	scale = ((double)mlx->tile_size / mlx->t_set.player_up_f0.image_height);
	if (co.x >= 0 && co.x <= mlx->window_size.x
		&& co.y >= 0 && co.y <= mlx->window_size.y)
	{
		if (enemy.type == ENEMY_V)
			image = ft_animation_enemy_v(mlx).image;
		else
			image = ft_animation_enemy_h(mlx).image;
		mlx_put_transformed_image_to_window(mlx->mlx, mlx->win, image,
			co.x, co.y, scale, scale, 0);
	}
}

void	ft_check_collision(t_mlx *mlx, int enemy_i)
{
	t_map	map;
	t_enemy	enemy;

	map = mlx->game_i.map;
	enemy = mlx->game_i.enemys[enemy_i];
	if (enemy.type == ENEMY_V && mlx->page == GAME_PAGE
		&& mlx->frame % 120 == 0)
	{
		if (map.map[enemy.pos.y][enemy.pos.x + enemy.vel] == WALL_TILE)
			mlx->game_i.enemys[enemy_i].vel *= -1;
		mlx->game_i.enemys[enemy_i].pos.x += mlx->game_i.enemys[enemy_i].vel;
	}
	else if (mlx->page == GAME_PAGE && mlx->frame % 120 == 0)
	{
		if (map.map[enemy.pos.y + enemy.vel][enemy.pos.x] == WALL_TILE)
			mlx->game_i.enemys[enemy_i].vel *= -1;
		mlx->game_i.enemys[enemy_i].pos.y += mlx->game_i.enemys[enemy_i].vel;
	}
}

void	ft_render_enemys(t_mlx *mlx)
{
	t_vec2	pos;
	int		i;
	int		vel;

	i = 0;
	while (i < mlx->game_i.enemys_count)
	{
		if (!mlx->game_i.enemys[i].dead)
		{
			ft_check_collision(mlx, i);
			pos.x = mlx->game_i.enemys[i].pos.x;
			pos.y = mlx->game_i.enemys[i].pos.y;
			vel = mlx->game_i.enemys[i].vel;
			if (mlx->game_i.map.map[pos.y][pos.x] == WALL_TILE)
			{
				if (mlx->game_i.enemys[i].type == ENEMY_V)
					mlx->game_i.enemys[i].pos.x += -1 * vel;
				else
					mlx->game_i.enemys[i].pos.y += -1 * vel;
			}
			ft_render_enemy(mlx, i);
		}
		i++;
	}
}
