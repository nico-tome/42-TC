/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 22:41:26 by ntome             #+#    #+#             */
/*   Updated: 2025/11/12 14:39:44 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"
#include "../../includes/ft_parsing.h"
#include "../../includes/ft_error.h"

int	ft_check_map(t_map map)
{
	t_parser_infos	map_infos;
	int				error_code;
	
	map_infos = ft_parse_map(map);
	error_code = ft_check_tiles_infos(map_infos, map.size);
	if (ft_is_succes_code(error_code))
		error_code = ft_check_size_and_close_map(map_infos, map);
	if (ft_is_succes_code(error_code))
		error_code = ft_check_pathfinding(map, map_infos);
	free(map_infos.row_size);
	free(map_infos.row_tiles);
	return (error_code);
}
