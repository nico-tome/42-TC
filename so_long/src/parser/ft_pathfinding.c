/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:30:02 by ntome             #+#    #+#             */
/*   Updated: 2025/11/12 23:45:29 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"
#include "../../includes/ft_parsing.h"
#include "../../includes/ft_error.h"

t_vec2	ft_get_spawn_pos(t_map map)
{
	t_vec2	spawn_pos;

	spawn_pos.y = 0;
	while (map.map[spawn_pos.y])
	{
		spawn_pos.x = 0;
		while (map.map[spawn_pos.y][spawn_pos.x])
		{
			if (map.map[spawn_pos.y][spawn_pos.x] == SPAWN_TILE)
				return (spawn_pos);
			spawn_pos.x++;
		}
		spawn_pos.y++;
	}
	return (spawn_pos);
}

int	ft_get_total_collectible(t_map map)
{
	int		result;
	t_vec2	coord;

	coord.y = 0;
	result = 0;
	while (map.map[coord.y])
	{
		coord.x = 0;
		while (map.map[coord.y][coord.x])
		{
			if (map.map[coord.y][coord.x] == COLLECTIBLE_TILE)
				result++;
			coord.x++;
		}
		coord.y++;
	}
	return (result);
}

t_pf_infos	ft_pathfinding_rec(t_pf_infos pf_infos, t_map map, t_vec2 pos)
{
	t_vec2	next_pos;

	pf_infos.tiles_visited[pos.y][pos.x] = '1';
	next_pos.y = pos.y;
	if (map.map[pos.y][pos.x] == SPAWN_TILE)
		pf_infos.tiles_count.spawn++;
	else if (map.map[pos.y][pos.x] == EXIT_TILE)
		pf_infos.tiles_count.end++;
	else if (map.map[pos.y][pos.x] == COLLECTIBLE_TILE)
		pf_infos.tiles_count.collectible++;
	next_pos.x = pos.x + 1;
	if (pf_infos.tiles_visited[pos.y][pos.x + 1] != '1')
		pf_infos = ft_pathfinding_rec(pf_infos, map, next_pos);
	next_pos.x = pos.x - 1;
	if (pf_infos.tiles_visited[pos.y][pos.x - 1] != '1')
		pf_infos = ft_pathfinding_rec(pf_infos, map, next_pos);
	next_pos.x = pos.x;
	next_pos.y = pos.y + 1;
	if (pf_infos.tiles_visited[pos.y + 1][pos.x] != '1')
		pf_infos = ft_pathfinding_rec(pf_infos, map, next_pos);
	next_pos.y = pos.y - 1;
	if (pf_infos.tiles_visited[pos.y - 1][pos.x] != '1')
		pf_infos = ft_pathfinding_rec(pf_infos, map, next_pos);
	return (pf_infos);
}

int	ft_check_pathfinding(t_map map)
{
	t_vec2		spawn_pos;
	t_pf_infos	pathfinding_infos;
	int			total_collectible;

	pathfinding_infos = ft_setup_pathfinding_infos(map);
	if (!pathfinding_infos.tiles_visited)
		return (MALLOC_ERROR_CODE);
	pathfinding_infos.tiles_count = ft_init_tiles_count();
	spawn_pos = ft_get_spawn_pos(map);
	total_collectible = ft_get_total_collectible(map);
	pathfinding_infos = ft_pathfinding_rec(pathfinding_infos, map, spawn_pos);
	ft_free_pf_infos(pathfinding_infos, map);
	if (pathfinding_infos.tiles_count.end == 0)
		return (MAP_IMPOSSIBLE_MAP_ERROR_CODE);
	if (pathfinding_infos.tiles_count.collectible != total_collectible)
		return (MAP_IMPOSSIBLE_MAP_ERROR_CODE);
	return (MAP_OK);
}
