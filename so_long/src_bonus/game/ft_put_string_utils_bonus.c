/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_string_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:46:02 by ntome             #+#    #+#             */
/*   Updated: 2025/11/20 14:11:32 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/ft_so_long_bonus.h"

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
