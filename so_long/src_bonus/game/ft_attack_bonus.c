/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attack_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:51:53 by ntome             #+#    #+#             */
/*   Updated: 2025/11/22 17:24:26 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/ft_so_long_bonus.h"

int	ft_is_monster(t_mlx *mlx, t_vec2 co)
{
	t_enemy	enemy;
	int		enemy_i;

	enemy_i = 0;
	while (enemy_i < mlx->game_i.enemys_count)
	{
		enemy = mlx->game_i.enemys[enemy_i];
		if (enemy.pos.x == co.x && enemy.pos.y == co.y)
			return (enemy_i);
		enemy_i++;
	}
	return (-1);
}

void	ft_attack(t_mlx *mlx)
{
	t_vec2	player_pos;
	int		is_enemy;

	player_pos.x = mlx->game_i.player_co.x;
	player_pos.y = mlx->game_i.player_co.y;
	ft_printf("%d;%d\n", player_pos.x, player_pos.y);
	if (mlx->game_i.player_dir == 1)
		player_pos.x++;
	else if (mlx->game_i.player_dir == -1)
		player_pos.x--;
	else if (mlx->game_i.player_dir == 2)
		player_pos.y++;
	else
		player_pos.y--;
	ft_printf("%d;%d\n", player_pos.x, player_pos.y);
	is_enemy = ft_is_monster(mlx, player_pos);
	if (is_enemy > -1)
		mlx->game_i.enemys[is_enemy].dead = 1;
}
