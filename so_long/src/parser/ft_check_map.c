/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 22:41:26 by ntome             #+#    #+#             */
/*   Updated: 2025/11/16 18:13:38 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"
#include "../../includes/ft_parsing.h"
#include "../../includes/ft_error.h"

t_tiles_count	ft_init_tiles_count(void)
{
	t_tiles_count	tiles_count;

	tiles_count.spawn = 0;
	tiles_count.collectible = 0;
	tiles_count.end = 0;
	tiles_count.wall = 0;
	return (tiles_count);
}

int	ft_check_map(t_map map)
{
	t_parser_infos	map_infos;
	int				error_code;

	map_infos.row_size = NULL;
	map_infos = ft_parse_map(map, map_infos);
	error_code = ft_check_size_close_map(map_infos, map);
	if (ft_is_succes_code(error_code))
		error_code = ft_check_tiles_infos(map_infos, map);
	if (ft_is_succes_code(error_code))
		error_code = ft_check_pathfinding(map);
	free(map_infos.row_size);
	free(map_infos.row_tiles);
	return (error_code);
}
