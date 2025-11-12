/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinding_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:53:09 by ntome             #+#    #+#             */
/*   Updated: 2025/11/12 23:46:08 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"
#include "../../includes/ft_parsing.h"

void	ft_free_pf_infos(t_pf_infos pathfinding_infos, t_map map)
{
	int	i;

	i = 0;
	while (i < map.size && pathfinding_infos.tiles_visited[i])
	{
		free(pathfinding_infos.tiles_visited[i]);
		i++;
	}
	free(pathfinding_infos.tiles_visited);
}

t_pf_infos	ft_setup_pathfinding_infos(t_map map)
{
	t_pf_infos	pf_infos;
	t_vec2		coord;

	coord.y = 0;
	pf_infos.tiles_visited = malloc(sizeof(char *) * map.size);
	while (pf_infos.tiles_visited && (coord.y < map.size))
	{
		pf_infos.tiles_visited[coord.y] = malloc(ft_strlen(map.map[0]));
		if (!pf_infos.tiles_visited[coord.y])
		{
			ft_free_pf_infos(pf_infos, map);
			return (pf_infos);
		}
		coord.x = 0;
		while (coord.x < (int)ft_strlen(map.map[0]))
		{
			if (map.map[coord.y][coord.x] == WALL_TILE)
				pf_infos.tiles_visited[coord.y][coord.x] = '1';
			else
				pf_infos.tiles_visited[coord.y][coord.x] = '0';
			coord.x++;
		}
		coord.y++;
	}
	return (pf_infos);
}
