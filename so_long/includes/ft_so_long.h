/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:50:37 by ntome             #+#    #+#             */
/*   Updated: 2025/11/11 19:16:07 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../lib/MacroLibX/includes/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/printf/ft_printf.h"

# define TRUE 1
# define FALSE 0
# define FREE_SPACE_TILE '0'
# define WALL_TILE '1'
# define COLLECTIBLE_TILE 'C'
# define EXIT_TILE 'E'
# define SPAWN_TILE 'P'

typedef struct s_vec2
{
	int	x;
	int	y;
}				t_vec2;

typedef struct s_map
{
	char	**map;
	int		size;
}				t_map;

t_map	ft_get_map(char *file_path);

#endif
