/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:50:04 by ntome             #+#    #+#             */
/*   Updated: 2025/11/19 21:14:20 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"
#include "../../includes/ft_parsing.h"
#include "../../includes/ft_error.h"

void	ft_malloc_error_free(t_parser_infos *map_infos, t_map *map)
{
	if (map_infos->row_tiles)
		free(map_infos->row_tiles);
	if (map_infos->row_size)
		free(map_infos->row_size);
	if (map->map)
		free(map->map);
	ft_exit_error(MALLOC_ERROR_CODE);
}

t_parser_infos	ft_parse_map(t_map map, t_parser_infos map_infos)
{
	t_vec2			coord;

	map_infos.row_tiles = malloc(sizeof(t_tiles_count) * map.size);
	map_infos.row_size = malloc(sizeof(int) * map.size);
	if (!map_infos.row_size || !map_infos.row_tiles)
		ft_malloc_error_free(&map_infos, &map);
	coord.y = -1;
	while (map.map[++coord.y])
	{
		map_infos.row_size[coord.y] = (int)ft_strlen(map.map[coord.y]);
		map_infos.row_tiles[coord.y] = ft_init_tiles_count();
		coord.x = 0;
		while (map.map[coord.y][coord.x++])
		{
			if (map.map[coord.y][coord.x] == WALL_TILE)
				map_infos.row_tiles[coord.y].wall++;
			else if (map.map[coord.y][coord.x] == SPAWN_TILE)
				map_infos.row_tiles[coord.y].spawn++;
			else if (map.map[coord.y][coord.x] == EXIT_TILE)
				map_infos.row_tiles[coord.y].end++;
			else if (map.map[coord.y][coord.x] == COLLECTIBLE_TILE)
				map_infos.row_tiles[coord.y].collectible++;
		}
	}
	return (map_infos);
}

int	ft_get_tile_sum(t_tiles_count tiles)
{
	int	sum;

	sum = tiles.collectible;
	sum += tiles.end;
	sum += tiles.spawn;
	sum += tiles.wall;
	return (sum);
}

int	ft_check_tiles_infos(t_parser_infos map_infos, t_map map)
{
	t_vec2			row;
	t_tiles_count	tiles_sum;

	tiles_sum = ft_init_tiles_count();
	row.y = -1;
	while (map.map[++row.y])
	{
		row.x = -1;
		while (map.map[row.y][++row.x])
		{
			if (!ft_strchr(TILESET, map.map[row.y][row.x]))
				return (MAP_WRONG_TILE_INDEX_ERROR_CODE);
		}
		tiles_sum.end += map_infos.row_tiles[row.y].end;
		tiles_sum.spawn += map_infos.row_tiles[row.y].spawn;
		tiles_sum.wall += map_infos.row_tiles[row.y].wall;
		tiles_sum.collectible += map_infos.row_tiles[row.y].collectible;
	}
	if (tiles_sum.spawn != 1)
		return (MAP_SPAWN_ERROR_CODE);
	if (tiles_sum.end != 1)
		return (MAP_END_ERROR_CODE);
	if (tiles_sum.collectible < 1)
		return (MAP_NO_COLLECTIBLE_ERROR_CODE);
	return (MAP_OK);
}

int	ft_check_size_close_map(t_parser_infos map_infos, t_map map)
{
	int	row;
	int	size;

	size = map_infos.row_size[0];
	row = 0;
	while (row < map.size)
	{
		if (map_infos.row_size[row] != size)
			return (MAP_WRONG_SIZE_ERROR_CODE);
		if (row == 0 || row == map.size - 1)
		{
			if (map_infos.row_tiles[row].wall != map_infos.row_size[row] - 1)
				return (MAP_NOT_CLOSE_ERROR_CODE);
		}
		if (map.map[row][0] != WALL_TILE || map.map[row][size - 1] != WALL_TILE)
			return (MAP_NOT_CLOSE_ERROR_CODE);
		row++;
	}
	return (MAP_OK);
}
