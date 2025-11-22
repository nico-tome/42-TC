/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_image_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:35:00 by ntome             #+#    #+#             */
/*   Updated: 2025/11/22 16:45:55 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/ft_so_long_bonus.h"

void	ft_free_textures1(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_n.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_s.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_e.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_o.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_ne.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_no.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_se.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_so.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_full.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_nt.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_t_center.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_st.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_st_end.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_c_left.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_c_center.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_c_right.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.ground.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.exit_close.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.exit_open.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.spawn.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.coin_f0.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.coin_f1.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.coin_f2.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.coin_f3.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.player_up_f0.image);
}
void	ft_free_textures2(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->t_set.player_down_f0.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.player_left_f0.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.player_right_f0.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.tile_selected.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.enemy_v_f0.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.enemy_v_f1.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.enemy_v_f2.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.enemy_v_f3.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.enemy_h_f0.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.enemy_h_f1.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.enemy_h_f2.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.enemy_h_f3.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.spike_f0.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.spike_f1.image);
}
void	ft_free_textures(t_mlx *mlx)
{
	ft_free_textures1(mlx);
	ft_free_textures2(mlx);
	mlx_destroy_image(mlx->mlx, mlx->t_set.spike_f2.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.spike_f3.image);
}
