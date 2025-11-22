/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 22:07:48 by ntome             #+#    #+#             */
/*   Updated: 2025/11/21 22:29:18 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/ft_so_long_bonus.h"

int	ft_vec2_equal(t_vec2 vec1, t_vec2 vec2)
{
	if (vec1.x == vec2.x && vec1.y == vec2.y)
		return (TRUE);
	return (FALSE);
}

int	ft_check_monster(t_mlx *mlx)
{
	int		enemy_i;
	t_vec2	pos;

	pos = mlx->game_i.player_co;
	enemy_i = 0;
	while (enemy_i < mlx->game_i.enemys_count)
	{
		if (ft_vec2_equal(mlx->game_i.enemys[enemy_i].pos, pos))
			return (1);
		enemy_i++;
	}
	return (0);
}

int	ft_check_spike(t_mlx *mlx)
{
	t_vec2		pos;

	pos = mlx->game_i.player_co;
	if (mlx->game_i.map.map[pos.y][pos.x] == SPIKE_TILE)
	{
		if (ft_animation_spikes(mlx).image != mlx->t_set.spike_f0.image)
			return (1);
	}
	return (0);
}

void	ft_check_death(t_mlx *mlx)
{
	if (ft_check_monster(mlx))
		mlx->page = DEATH_PAGE;
	else if (ft_check_spike(mlx))
		mlx->page = DEATH_PAGE;
}

void	ft_render_death_page(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 1280 / 2 - 100, 720 / 2,
		(mlx_color){.rgba = COLOR_RED}, "LMAO YOU ARE DEAD (skill issue)");
	mlx_string_put(mlx->mlx, mlx->win, 1280 / 2 - 100, 720 / 2 + 50,
		(mlx_color){.rgba = COLOR_RED}, "Click or press escape to quit.");
}
