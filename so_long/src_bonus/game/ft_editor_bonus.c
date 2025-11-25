/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_editor_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:12:20 by ntome             #+#    #+#             */
/*   Updated: 2025/11/25 15:44:39 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/ft_so_long_bonus.h"

void	ft_render_cursore(t_mlx *mlx)
{
	t_vec_d2	co;
	double		scale;
	mlx_image	image;

	co.x = mlx->game_i.player_co.x * mlx->tile_size - mlx->game_i.camera_pos.x;
	co.y = mlx->game_i.player_co.y * mlx->tile_size - mlx->game_i.camera_pos.y;
	scale = ((double)mlx->tile_size / mlx->t_set.player_up_f0.image_height);
	image = mlx->t_set.tile_selected.image;
	mlx_put_transformed_image_to_window(mlx->mlx, mlx->win, image,
		co.x, co.y, scale, scale, 0);
}

void	ft_render_help_text(t_mlx *mlx)
{
	char	*c;
	char	*str;

	c = malloc(sizeof(char) * 2);
	if (c)
	{
		c[0] = mlx->brush;
		c[1] = '\0';
		str = ft_strjoin("Brush selected: ", c);
		mlx_string_put(mlx->mlx, mlx->win, 20, 720 - 130,
			(mlx_color){.rgba = COLOR_GREEN}, str);
		free(str);
		free(c);
	}
	if (mlx->show_help)
		return ;
	mlx_string_put(mlx->mlx, mlx->win, 20, 720 - 90,
		(mlx_color){.rgba = COLOR_RED}, "Press <space> to play.");
	mlx_string_put(mlx->mlx, mlx->win, 20, 720 - 70,
		(mlx_color){.rgba = COLOR_RED}, "Move with 'wasd'. Hide with H");
	mlx_string_put(mlx->mlx, mlx->win, 20, 720 - 50,
		(mlx_color){.rgba = COLOR_RED},
		"1: wall | 2:coin | 3: spawn | 4: exit | 5: spike | 6: enemy_v | ");
	mlx_string_put(mlx->mlx, mlx->win, 530, 720 - 50,
		(mlx_color){.rgba = COLOR_RED}, "7: enemy_h | 0: remove tile");
}

void	ft_change_tile(t_mlx *mlx)
{
	t_vec2	pos;

	pos.y = mlx->game_i.player_co.y;
	pos.x = mlx->game_i.player_co.x;
	mlx->game_i.map.map[pos.y][pos.x] = mlx->brush;
	free(mlx->game_i.enemys);
	ft_load_enemys(mlx, mlx->game_i.map);
}

void	ft_switch_brush(t_mlx *mlx, int key)
{
	if (key == KEY_7)
		mlx->brush = ENEMY_H;
	else if (key == KEY_6)
		mlx->brush = ENEMY_V;
	else if (key == KEY_5)
		mlx->brush = SPIKE_TILE;
	else if (key == KEY_4)
		mlx->brush = EXIT_TILE;
	else if (key == KEY_3)
		mlx->brush = SPAWN_TILE;
	else if (key == KEY_2)
		mlx->brush = COLLECTIBLE_TILE;
	else if (key == KEY_1)
		mlx->brush = WALL_TILE;
	else
		mlx->brush = FREE_SPACE_TILE;
}

void	ft_move_cursore(t_mlx *mlx, int key)
{
	t_vec2	pos;
	int		move_y;
	int		move_x;
	int		line_len;

	line_len = ft_strlen(mlx->game_i.map.map[0]);
	pos = mlx->game_i.player_co;
	move_y = 0 - (key == KEY_W) + (key == KEY_S);
	move_x = 0 - (key == KEY_A) + (key == KEY_D);
	if (pos.y + move_y >= 0 && pos.x + move_x >= 0
		&& pos.y + move_y < mlx->game_i.map.size && pos.x + move_x < line_len)
	{
		mlx->game_i.player_co.y += move_y;
		mlx->game_i.player_co.x += move_x;
		mlx->game_i.player_dir = 0 - (key == KEY_A) + (key == KEY_D);
		mlx->game_i.player_dir += 2 * (0 - (key == KEY_W) + (key == KEY_S));
	}
	ft_check_camera_scroll(mlx, mlx->tile_size);
}
