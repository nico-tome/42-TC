/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:51:36 by ntome             #+#    #+#             */
/*   Updated: 2025/11/21 16:31:55 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/ft_so_long_bonus.h"

t_texture	ft_animation_coin(t_mlx *mlx)
{
	int	frame;
	int	speed;

	speed = 2;
	frame = mlx->frame % (64 * speed);
	if (frame <= (16 * speed))
		return (mlx->t_set.coin_f0);
	else if (frame <= (32 * speed))
		return (mlx->t_set.coin_f1);
	else if (frame <= (48 * speed))
		return (mlx->t_set.coin_f2);
	else if (frame <= (64 * speed))
		return (mlx->t_set.coin_f3);
	else
		return (mlx->t_set.coin_f0);
}

t_texture	ft_animation_spikes(t_mlx *mlx)
{
	int	frame;
	int	speed;

	speed = 4;
	frame = mlx->frame % (96 * speed);
	if (frame <= (48 * speed))
		return (mlx->t_set.spike_f0);
	else if (frame <= (64 * speed))
		return (mlx->t_set.spike_f1);
	else if (frame <= (80 * speed))
		return (mlx->t_set.spike_f2);
	else if (frame <= (96 * speed))
		return (mlx->t_set.spike_f3);
	else
		return (mlx->t_set.spike_f0);
}

t_texture	ft_animation_enemy_v(t_mlx *mlx)
{
	int	frame;
	int	speed;

	speed = 2;
	frame = mlx->frame % (64 * speed);
	if (frame <= (16 * speed))
		return (mlx->t_set.enemy_v_f0);
	else if (frame <= (32 * speed))
		return (mlx->t_set.enemy_v_f1);
	else if (frame <= (48 * speed))
		return (mlx->t_set.enemy_v_f2);
	else if (frame <= (64 * speed))
		return (mlx->t_set.enemy_v_f3);
	else
		return (mlx->t_set.enemy_v_f0);
}

t_texture	ft_animation_enemy_h(t_mlx *mlx)
{
	int	frame;
	int	speed;

	speed = 2;
	frame = mlx->frame % (64 * speed);
	if (frame <= (16 * speed))
		return (mlx->t_set.enemy_h_f0);
	else if (frame <= (32 * speed))
		return (mlx->t_set.enemy_h_f1);
	else if (frame <= (48 * speed))
		return (mlx->t_set.enemy_h_f2);
	else if (frame <= (64 * speed))
		return (mlx->t_set.enemy_h_f3);
	else
		return (mlx->t_set.enemy_h_f0);
}
