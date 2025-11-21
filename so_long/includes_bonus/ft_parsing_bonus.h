/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:15:13 by ntome             #+#    #+#             */
/*   Updated: 2025/11/20 14:08:09 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_BONUS_H
# define FT_PARSING_BONUS_H

# include "ft_so_long_bonus.h"

# define MAP_OK 100

typedef struct s_tiles_count
{
	int	wall;
	int	spawn;
	int	end;
	int	collectible;
}				t_tiles_count;

typedef struct s_parser_infos
{
	int				*row_size;
	t_tiles_count	*row_tiles;
}				t_parser_infos;

typedef struct s_pathfinding_infos
{
	char			**tiles_visited;
	t_tiles_count	tiles_count;
}				t_pf_infos;

int				ft_check_map(t_map map);
t_parser_infos	ft_parse_map(t_map map, t_parser_infos map_infos);
int				ft_check_tiles_infos(t_parser_infos map_infos, t_map map);
int				ft_check_size_close_map(t_parser_infos map_infos, t_map map);
int				ft_check_pathfinding(t_map map);
t_pf_infos		ft_setup_pathfinding_infos(t_map map);
t_tiles_count	ft_init_tiles_count(void);
void			ft_free_pf_infos(t_pf_infos pathfinding_infos, t_map map);

#endif
