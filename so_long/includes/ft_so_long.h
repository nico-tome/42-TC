/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:50:37 by ntome             #+#    #+#             */
/*   Updated: 2025/11/18 14:26:07 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../lib/MacroLibX/includes/mlx.h"
# include "../lib/MacroLibX/includes/mlx_extended.h"
# include "../lib/libft/libft.h"
# include "ft_colors.h"
# include "ft_keys.h"

# define TRUE 1
# define FALSE 0
# define FREE_SPACE_TILE '0'
# define WALL_TILE '1'
# define COLLECTIBLE_TILE 'C'
# define EXIT_TILE 'E'
# define SPAWN_TILE 'P'
# define TILESET "01CEP"
# define TILE_SIZE 16

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

typedef struct s_vec_d2
{
	double	x;
	double	y;
}				t_vec_d2;

typedef struct s_grid
{
	int	n;
	int	s;
	int	o;
	int	e;
}				t_grid;

typedef struct s_map
{
	char	**map;
	int		size;
}				t_map;

typedef struct s_game_infos
{
	int			move_count;
	int			coin_collected;
	t_map		map;
	t_vec_d2	player_co;
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
	t_texture	wall_ne;
	t_texture	wall_no;
	t_texture	wall_se;
	t_texture	wall_so;
	t_texture	wall_full;
	t_texture	wall_nt;
	t_texture	wall_t_center;
	t_texture	wall_st;
	t_texture	wall_c_left;
	t_texture	wall_c_center;
	t_texture	wall_c_right;
	t_texture	ground;
	t_texture	exit_close;
	t_texture	exit_open;
	t_texture	spawn;
	t_texture	coin;
	t_texture	player;
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
	double			tile_size;
}				t_mlx;

t_map		ft_get_map(char *file_path);
void		ft_init_textures(t_mlx *mlx);
void		ft_free_textures(t_mlx *mlx);
void		key_hook(int key, void *param);
void		mouse_hook(int button, void *param);
void		mouse_wheel_hook(int button, void *param);
void		window_hook(int event, void *param);
void		ft_mlx_putstr(t_mlx *mlx, t_vec2 coord, mlx_color color, char *str);
int			ft_get_str_size(char *str, int font_size);
void		ft_render_player(t_mlx *mlx);
void		ft_render_map(t_mlx *mlx);
t_texture	ft_get_wall_texture(t_mlx *mlx, t_vec2 read);

#endif
