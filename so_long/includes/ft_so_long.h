/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:50:37 by ntome             #+#    #+#             */
/*   Updated: 2025/11/16 20:55:25 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../lib/MacroLibX/includes/mlx.h"
# include "../lib/MacroLibX/includes/mlx_extended.h"
# include "../lib/libft/libft.h"
# include "ft_colors.h"

# define TRUE 1
# define FALSE 0
# define FREE_SPACE_TILE '0'
# define WALL_TILE '1'
# define COLLECTIBLE_TILE 'C'
# define EXIT_TILE 'E'
# define SPAWN_TILE 'P'
# define TILESET "01CEP"

typedef enum e_page
{
	MAIN_MENU,
	SETTINGS,
	EDIT_PAGE,
	GAME_PAGE,
}			t_page;

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

typedef struct s_game_infos
{
	int		move_count;
	int		coin_collected;
	t_map	map;
}				t_game_infos;

typedef struct s_texture
{
	mlx_image	image;
	int			image_width;
	int			image_height;
}				t_texture;

typedef struct s_textures
{
	t_texture	wall_n;
	t_texture	wall_s;
	t_texture	wall_e;
	t_texture	wall_o;
	t_texture	ground;
	t_texture	exit_close;
	t_texture	exit_open;
	t_texture	spawn;
	t_texture	coin;
}			t_textures;

typedef struct s_mlx
{
	mlx_context		mlx;
	mlx_window		win;
	t_vec2			window_size;
	int				need_update;
	t_page			page;
	t_textures		t_set;
	t_game_infos	game_i;
}				t_mlx;

t_map	ft_get_map(char *file_path);
void	ft_init_textures(t_mlx *mlx);
void	ft_free_textures(t_mlx *mlx);
void	key_hook(int key, void *param);
void	mouse_hook(int button, void *param);
void	mouse_wheel_hook(int button, void *param);
void	window_hook(int event, void *param);
void	ft_mlx_putstr(t_mlx *mlx, t_vec2 coord, mlx_color color, char *str);
int		ft_get_str_size(char *str, int font_size);
void	ft_draw_menu_page(t_mlx *mlx);
void	ft_draw_settings_page(t_mlx *mlx);
void	ft_render_map(t_mlx *mlx);

#endif
