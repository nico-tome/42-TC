/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_handling_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:08:48 by ntome             #+#    #+#             */
/*   Updated: 2025/11/22 16:43:01 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/ft_so_long_bonus.h"
#include "../../includes_bonus/ft_parsing_bonus.h"

void	ft_input_editor(t_mlx *mlx, int key)
{
	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		ft_move_cursore(mlx, key);
	if ((key >= KEY_1 && key <= KEY_7) || key == KEY_0)
		ft_switch_brush(mlx, key);
	if (key == KEY_SPACE)
		ft_change_tile(mlx);
	if (key == KEY_H)
		mlx->show_help *= -1;
	if (key == KEY_X)
		ft_save_map(mlx);
}

void	ft_key_enter(t_mlx *mlx)
{
	if (mlx->page == GAME_PAGE)
	{
		mlx->game_i.map = ft_get_map(mlx->file_path);
		ft_load_enemys(mlx, mlx->game_i.map);
		mlx->brush = WALL_TILE;
		mlx->page = EDITOR_PAGE;
	}
	else if (mlx->page == EDITOR_PAGE
		&& ft_check_map(mlx->game_i.map) == MAP_OK)
	{
		ft_init_player(mlx);
		ft_init_camera_pos(mlx);
		mlx->page = GAME_PAGE;
	}
}

void	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx->key_down[key] = 1;
	if (key == 41)
		mlx_loop_end(mlx->mlx);
	else if (mlx->page == GAME_PAGE && key != KEY_ENTER)
		ft_move_player(mlx, key);
	else if (mlx->page == EDITOR_PAGE && key != KEY_ENTER)
		ft_input_editor(mlx, key);
	else if (key == KEY_ENTER)
		ft_key_enter(mlx);
}

void	mouse_hook(int button, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (mlx->page == END_PAGE || mlx->page == DEATH_PAGE)
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
