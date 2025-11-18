/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:50:24 by ntome             #+#    #+#             */
/*   Updated: 2025/11/18 18:22:07 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"

void	ft_new_texture(t_mlx *mlx, t_texture *texture, char *path)
{
	mlx_image	image;
	int			width;
	int			height;

	image = mlx_new_image_from_file(mlx->mlx, path, &width, &height);
	texture->image = image;
	texture->image_width = width;
	texture->image_height = height;
}

void	ft_init_textures(t_mlx *mlx)
{
	ft_new_texture(mlx, &mlx->t_set.ground, "./assets/ground.png");
	ft_new_texture(mlx, &mlx->t_set.exit_close, "./assets/exit_close.png");
	ft_new_texture(mlx, &mlx->t_set.exit_open, "./assets/exit_open.png");
	ft_new_texture(mlx, &mlx->t_set.spawn, "./assets/spawn.png");
	ft_new_texture(mlx, &mlx->t_set.coin, "./assets/coin.png");
	ft_new_texture(mlx, &mlx->t_set.wall_n, "./assets/wall_n.png");
	ft_new_texture(mlx, &mlx->t_set.wall_s, "./assets/wall_s.png");
	ft_new_texture(mlx, &mlx->t_set.wall_e, "./assets/wall_e.png");
	ft_new_texture(mlx, &mlx->t_set.wall_o, "./assets/wall_o.png");
	ft_new_texture(mlx, &mlx->t_set.wall_ne, "./assets/wall_ne.png");
	ft_new_texture(mlx, &mlx->t_set.wall_no, "./assets/wall_no.png");
	ft_new_texture(mlx, &mlx->t_set.wall_se, "./assets/wall_se.png");
	ft_new_texture(mlx, &mlx->t_set.wall_so, "./assets/wall_so.png");
	ft_new_texture(mlx, &mlx->t_set.wall_full, "./assets/wall_full.png");
	ft_new_texture(mlx, &mlx->t_set.wall_nt, "./assets/wall_nt.png");
	ft_new_texture(mlx, &mlx->t_set.wall_st, "./assets/wall_st.png");
	ft_new_texture(mlx, &mlx->t_set.wall_t_center, "./assets/wall_t_c.png");
	ft_new_texture(mlx, &mlx->t_set.wall_c_center, "./assets/wall_c_c.png");
	ft_new_texture(mlx, &mlx->t_set.wall_c_left, "./assets/wall_c_left.png");
	ft_new_texture(mlx, &mlx->t_set.wall_c_right, "./assets/wall_c_right.png");
	ft_new_texture(mlx, &mlx->t_set.player, "./assets/player.png");
}

void	ft_free_textures(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->t_set.coin.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.spawn.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.ground.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.exit_open.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.exit_close.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_n.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_s.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_e.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_o.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_so.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_se.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_no.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_ne.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_full.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_t_center.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_st.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_nt.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_c_right.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_c_left.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.wall_c_center.image);
	mlx_destroy_image(mlx->mlx, mlx->t_set.player.image);
}
