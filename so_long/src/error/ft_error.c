/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:19:25 by ntome             #+#    #+#             */
/*   Updated: 2025/11/19 22:30:25 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_error.h"

void	ft_args_error(int error_type)
{
	ft_printf("%s (%d): ", ERROR_TYPE_ARGS, error_type);
	if (error_type == ARGS_LESS_ERROR_CODE)
		ft_printf("%s\n", ARGS_LESS_ERROR);
	else if (error_type == ARGS_MORE_ERROR_CODE)
		ft_printf("%s\n", ARGS_MORE_ERROR);
	else
		ft_printf("Unknown args error.\n");
}

void	ft_file_error(int error_type)
{
	ft_printf("%s (%d): ", ERROR_TYPE_FILE, error_type);
	if (error_type == FILE_TYPE_ERROR_CODE)
		ft_printf("%s\n", FILE_TYPE_ERROR);
	else if (error_type == FILE_OPEN_ERROR_CODE)
		ft_printf("%s\n", FILE_OPEN_ERROR);
	else if (error_type == FILE_EMPTY_ERROR_CODE)
		ft_printf("%s\n", FILE_EMPTY_ERROR);
	else
		ft_printf("Unknown file error.\n");
}

void	ft_map_error(int error_type)
{
	ft_printf("%s (%d): ", ERROR_TYPE_MAP, error_type);
	if (error_type == MAP_WRONG_SIZE_ERROR_CODE)
		ft_printf("%s\n", MAP_WRONG_SIZE_ERROR);
	else if (error_type == MAP_NOT_CLOSE_ERROR_CODE)
		ft_printf("%s\n", MAP_NOT_CLOSE_ERROR);
	else if (error_type == MAP_SPAWN_ERROR_CODE)
		ft_printf("%s\n", MAP_SPAWN_ERROR);
	else if (error_type == MAP_END_ERROR_CODE)
		ft_printf("%s\n", MAP_END_ERROR);
	else if (error_type == MAP_NO_COLLECTIBLE_ERROR_CODE)
		ft_printf("%s\n", MAP_NO_COLLECTIBLE_ERROR);
	else if (error_type == MAP_IMPOSSIBLE_MAP_ERROR_CODE)
		ft_printf("%s\n", MAP_IMPOSSIBLE_ERROR);
	else if (error_type == MAP_WRONG_TILE_INDEX_ERROR_CODE)
		ft_printf("%s\n", MAP_TILE_ERROR);
	else
		ft_printf("Unknown map error.\n");
}

void	ft_exit_error(int error_type)
{
	ft_printf("Error\n");
	if (error_type >= 10 && error_type <= 19)
		ft_args_error(error_type);
	else if (error_type >= 20 && error_type <= 29)
		ft_file_error(error_type);
	else if (error_type >= 30 && error_type <= 39)
		ft_map_error(error_type);
	else if (error_type == MALLOC_ERROR_CODE)
		ft_printf("%s\n", MALLOC_ERROR);
	else if (error_type == TEXTURE_ERROR_CODE)
		ft_printf("%s\n", TEXTURE_ERROR);
	else
		ft_printf("Unknown error type.");
	exit(EXIT_FAILURE);
}
