/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:21:28 by ntome             #+#    #+#             */
/*   Updated: 2025/11/20 14:08:54 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_BONUS_H
# define FT_ERROR_BONUS_H

# include "ft_so_long_bonus.h"

# define ARGS_MORE_ERROR_CODE 10
# define ARGS_LESS_ERROR_CODE 11
# define FILE_TYPE_ERROR_CODE 20
# define FILE_OPEN_ERROR_CODE 21
# define FILE_EMPTY_ERROR_CODE 22
# define MAP_WRONG_SIZE_ERROR_CODE 30
# define MAP_NOT_CLOSE_ERROR_CODE 31
# define MAP_SPAWN_ERROR_CODE 32
# define MAP_END_ERROR_CODE 33
# define MAP_NO_COLLECTIBLE_ERROR_CODE 34
# define MAP_IMPOSSIBLE_MAP_ERROR_CODE 35
# define MAP_WRONG_TILE_INDEX_ERROR_CODE 36
# define MALLOC_ERROR_CODE 42
# define TEXTURE_ERROR_CODE 50
# define ERROR_TYPE_ARGS "ARGS ERROR"
# define ARGS_MORE_ERROR "Too many args (./so_long *.ber)"
# define ARGS_LESS_ERROR "Not enought args (./so_long *.ber)"
# define ERROR_TYPE_FILE "FILE ERROR"
# define FILE_TYPE_ERROR "Wrong file type ! (only *.ber file accepted)"
# define FILE_OPEN_ERROR "Can't open the file !"
# define FILE_EMPTY_ERROR "No data to read !"
# define ERROR_TYPE_MAP "MAP ERROR"
# define MAP_WRONG_SIZE_ERROR "The map is not rectangular."
# define MAP_NOT_CLOSE_ERROR "The map is not surrounded by walls."
# define MAP_SPAWN_ERROR "The number of spawn tile is not 1."
# define MAP_END_ERROR "The number of end tile is not 1."
# define MAP_NO_COLLECTIBLE_ERROR "There is no collectible in the map."
# define MAP_IMPOSSIBLE_ERROR "The map is impossible. (coin/end unreachable !)"
# define MAP_TILE_ERROR "Unallowed character found. (Only 0 1 C E P allowed !)"
# define MALLOC_ERROR "Malloc Error !"
# define TEXTURE_ERROR "Texture Error !"

void	ft_exit_error(int error_type);
int		ft_is_error_code(int code);
int		ft_is_succes_code(int code);

#endif
