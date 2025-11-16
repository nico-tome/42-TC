/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_string_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:46:02 by ntome             #+#    #+#             */
/*   Updated: 2025/11/16 18:09:01 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"

void	ft_mlx_putstr(t_mlx *mlx, t_vec2 coord, mlx_color color, char *str)
{
	mlx_string_put(mlx->mlx, mlx->win, coord.x, coord.y, color, str);
}

int	ft_get_str_size(char *str, int font_size)
{
	int	size;

	size = ft_strlen(str);
	size *= font_size;
	return (size);
}
