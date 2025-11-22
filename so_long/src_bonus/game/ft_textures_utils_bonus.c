/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:50:24 by ntome             #+#    #+#             */
/*   Updated: 2025/11/22 15:56:35 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/ft_so_long_bonus.h"

void	ft_new_texture(t_mlx *mlx, t_texture *texture, char *path)
{
	mlx_image	image;
	int			width;
	int			height;
	char		*full_path;

	full_path = ft_strjoin("./assets/", path);
	image = mlx_new_image_from_file(mlx->mlx, full_path, &width, &height);
	texture->image = image;
	texture->image_width = width;
	texture->image_height = height;
	free(full_path);
}

void	ft_load_player_sprite(t_mlx *mlx)
{
	ft_new_texture(mlx, &mlx->t_set.player_up_f0, "player_up.png");
	ft_new_texture(mlx, &mlx->t_set.player_left_f0, "player_left.png");
	ft_new_texture(mlx, &mlx->t_set.player_right_f0, "player_right.png");
	ft_new_texture(mlx, &mlx->t_set.player_down_f0, "player_down.png");
	ft_new_texture(mlx, &mlx->t_set.enemy_h_f0, "enemy_h0.png");
	ft_new_texture(mlx, &mlx->t_set.enemy_h_f1, "enemy_h1.png");
	ft_new_texture(mlx, &mlx->t_set.enemy_h_f2, "enemy_h2.png");
	ft_new_texture(mlx, &mlx->t_set.enemy_h_f3, "enemy_h3.png");
	ft_new_texture(mlx, &mlx->t_set.enemy_v_f0, "enemy_v0.png");
	ft_new_texture(mlx, &mlx->t_set.enemy_v_f1, "enemy_v1.png");
	ft_new_texture(mlx, &mlx->t_set.enemy_v_f2, "enemy_v2.png");
	ft_new_texture(mlx, &mlx->t_set.enemy_v_f3, "enemy_v3.png");
}

void	ft_load_walls(t_mlx *mlx)
{
	ft_new_texture(mlx, &mlx->t_set.wall_n, "wall_n.png");
	ft_new_texture(mlx, &mlx->t_set.wall_s, "wall_s.png");
	ft_new_texture(mlx, &mlx->t_set.wall_e, "wall_e.png");
	ft_new_texture(mlx, &mlx->t_set.wall_o, "wall_o.png");
	ft_new_texture(mlx, &mlx->t_set.wall_ne, "wall_ne.png");
	ft_new_texture(mlx, &mlx->t_set.wall_no, "wall_no.png");
	ft_new_texture(mlx, &mlx->t_set.wall_se, "wall_se.png");
	ft_new_texture(mlx, &mlx->t_set.wall_so, "wall_so.png");
	ft_new_texture(mlx, &mlx->t_set.wall_full, "wall_full.png");
	ft_new_texture(mlx, &mlx->t_set.wall_nt, "wall_nt.png");
	ft_new_texture(mlx, &mlx->t_set.wall_st, "wall_st.png");
	ft_new_texture(mlx, &mlx->t_set.wall_st_end, "wall_st_end.png");
	ft_new_texture(mlx, &mlx->t_set.wall_t_center, "wall_t_c.png");
	ft_new_texture(mlx, &mlx->t_set.wall_c_center, "wall_c_c.png");
	ft_new_texture(mlx, &mlx->t_set.wall_c_left, "wall_c_left.png");
	ft_new_texture(mlx, &mlx->t_set.wall_c_right, "wall_c_right.png");
}

void	ft_init_textures(t_mlx *mlx)
{
	ft_new_texture(mlx, &mlx->t_set.ground, "ground.png");
	ft_new_texture(mlx, &mlx->t_set.exit_close, "exit_close.png");
	ft_new_texture(mlx, &mlx->t_set.exit_open, "exit_open.png");
	ft_new_texture(mlx, &mlx->t_set.spawn, "spawn.png");
	ft_new_texture(mlx, &mlx->t_set.tile_selected, "tile_selected.png");
	ft_new_texture(mlx, &mlx->t_set.coin_f0, "coin0.png");
	ft_new_texture(mlx, &mlx->t_set.coin_f1, "coin1.png");
	ft_new_texture(mlx, &mlx->t_set.coin_f2, "coin2.png");
	ft_new_texture(mlx, &mlx->t_set.coin_f3, "coin3.png");
	ft_new_texture(mlx, &mlx->t_set.spike_f0, "spike2.png");
	ft_new_texture(mlx, &mlx->t_set.spike_f1, "spike3.png");
	ft_new_texture(mlx, &mlx->t_set.spike_f2, "spike0.png");
	ft_new_texture(mlx, &mlx->t_set.spike_f3, "spike1.png");
	ft_load_walls(mlx);
	ft_load_player_sprite(mlx);
}
