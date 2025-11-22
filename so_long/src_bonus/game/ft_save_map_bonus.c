/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 01:25:26 by ntome             #+#    #+#             */
/*   Updated: 2025/11/22 01:59:17 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/ft_so_long_bonus.h"

void	ft_save_map(t_mlx *mlx)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(mlx->file_path, O_WRONLY);
	if (fd != -1)
	{
		i = 0;
		while (i < mlx->game_i.map.size)
		{
			line = ft_strjoin(mlx->game_i.map.map[i], "\n");
			write(fd, line, ft_strlen(line));
			free(line);
			i++;
		}
		close(fd);
	}
}
