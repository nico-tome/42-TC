/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_handling_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:08:48 by ntome             #+#    #+#             */
/*   Updated: 2025/11/20 14:10:51 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/ft_so_long_bonus.h"

void	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (key == 41)
		mlx_loop_end(mlx->mlx);
	else if ((key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		&& mlx->page == GAME_PAGE)
		ft_move_player(mlx, key);
}

void	mouse_hook(int button, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (mlx->page == END_PAGE)
		mlx_loop_end(mlx->mlx);
	(void)button;
}

void	window_hook(int event, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (event == 0)
		mlx_loop_end(mlx->mlx);
}
