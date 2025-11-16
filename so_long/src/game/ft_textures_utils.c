/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:50:24 by ntome             #+#    #+#             */
/*   Updated: 2025/11/16 21:32:22 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"

void	ft_init_textures(t_mlx *mlx)
{
	mlx->t_set.ground.image = mlx_new_image_from_file(mlx->mlx,
		"../../assets/ground.png", &mlx->t_set.ground.image_height,
		&mlx->t_set.ground.image_width);
	mlx->t_set.exit_close.image = mlx_new_image_from_file(mlx->mlx,
		"../../assets/exit_close.png", &mlx->t_set.exit_close.image_width,
		&mlx->t_set.exit_close.image_height);
	mlx->t_set.spawn.image = mlx_new_image_from_file(mlx->mlx,
		"../../assets/spawn.png", &mlx->t_set.spawn.image_width,
		&mlx->t_set.spawn.image_height);
	mlx->t_set.coin.image = mlx_new_image_from_file(mlx->mlx,
		"../../assets/coin.png", &mlx->t_set.coin.image_width, 
		&mlx->t_set.coin.image_height);
	mlx->t_set.wall_n.image = mlx_new_image_from_file(mlx->mlx,
		"../../assets/wall_n.png", &mlx->t_set.wall_n.image_width,
		&mlx->t_set.wall_n.image_height);
	mlx->t_set.wall_s.image = mlx_new_image_from_file(mlx->mlx,
		"../../assets/wall_s.png", &mlx->t_set.wall_s.image_width,
		&mlx->t_set.wall_s.image_height);
	mlx->t_set.wall_e.image = mlx_new_image_from_file(mlx->mlx,
		"../../assets/wall_e.png", &mlx->t_set.wall_e.image_width,
		&mlx->t_set.wall_e.image_height);
	mlx->t_set.wall_o.image = mlx_new_image_from_file(mlx->mlx,
		"../../assets/wall_o.png", &mlx->t_set.wall_o.image_width,
		&mlx->t_set.wall_o.image_height);
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
}
