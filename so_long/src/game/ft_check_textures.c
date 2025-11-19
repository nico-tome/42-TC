/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:56:57 by ntome             #+#    #+#             */
/*   Updated: 2025/11/19 23:04:57 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"

int	ft_check_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nTexture file not found: %s\n", path);
		return (0);
	}
	close(fd);
	return (1);
}

int	ft_check_textures(void)
{
	int			file_i;
	static char	*path_list[25] = {"./assets/player_up.png",
		"./assets/player_left.png", "./assets/player_right.png",
		"./assets/player_down.png", "./assets/ground.png",
		"./assets/exit_close.png", "./assets/exit_open.png",
		"./assets/spawn.png", "./assets/coin.png", "./assets/wall_n.png",
		"./assets/wall_s.png", "./assets/wall_e.png", "./assets/wall_o.png",
		"./assets/wall_ne.png", "./assets/wall_no.png",
		"./assets/wall_se.png", "./assets/wall_so.png",
		"./assets/wall_full.png", "./assets/wall_nt.png",
		"./assets/wall_st.png",	"./assets/wall_t_c.png",
		"./assets/wall_c_c.png", "./assets/wall_c_left.png",
		"./assets/wall_c_right.png, \0"};

	file_i = 0;
	while (path_list[file_i])
	{
		if (!ft_check_file(path_list[file_i]))
			return (0);
		file_i++;
	}
	return (1);
}
