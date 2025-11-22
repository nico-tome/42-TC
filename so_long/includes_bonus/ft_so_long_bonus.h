/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:50:37 by ntome             #+#    #+#             */
/*   Updated: 2025/11/22 01:40:35 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_BONUS_H
# define FT_SO_LONG_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "../lib/MacroLibX/includes/mlx.h"
# include "../lib/MacroLibX/includes/mlx_extended.h"
# include "../lib/libft/libft.h"
# include "ft_colors_bonus.h"
# include "ft_keys_bonus.h"

# define TRUE 1
# define FALSE 0
# define FREE_SPACE_TILE '0'
# define WALL_TILE '1'
# define COLLECTIBLE_TILE 'C'
# define EXIT_TILE 'E'
# define SPAWN_TILE 'P'
# define SPIKE_TILE 'S'
# define ENEMY_V 'V'
# define ENEMY_H 'H'
# define TILESET "01CEPSVH"
# define TILE_SIZE 16
# define TILE_MAX_SIZE 64
# define TILE_MIN_SIZE 32

typedef enum e_page
{
	GAME_PAGE,
	EDITOR_PAGE,
	DEATH_PAGE,
	END_PAGE,
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

typedef struct s_enemy
{
	t_vec2	pos;
	int		vel;
	char	type;
}				t_enemy;


typedef struct s_game_infos
{
	int		move_count;
	int		coin_collected;
	int		coin_to_collect;
	t_map	map;
	t_vec2	player_co;
	int		player_dir;
	t_vec2	camera_pos;
	int		enemys_count;
	t_enemy	*enemys;
}				t_game_infos;

typedef struct s_texture
{
	mlx_image	image;
	int			frame_count;
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
	t_texture	coin_f0;
	t_texture	coin_f1;
	t_texture	coin_f2;
	t_texture	coin_f3;
	t_texture	player_up_f0;
	t_texture	player_up_f1;
	t_texture	player_up_f2;
	t_texture	player_up_f3;
	t_texture	player_down_f0;
	t_texture	player_down_f1;
	t_texture	player_down_f2;
	t_texture	player_down_f3;
	t_texture	player_left_f0;
	t_texture	player_left_f1;
	t_texture	player_left_f2;
	t_texture	player_left_f3;
	t_texture	player_right_f0;
	t_texture	player_right_f1;
	t_texture	player_right_f2;
	t_texture	player_right_f3;
	t_texture	tile_selected;
	t_texture	enemy_v_f0;
	t_texture	enemy_v_f1;
	t_texture	enemy_v_f2;
	t_texture	enemy_v_f3;
	t_texture	enemy_h_f0;
	t_texture	enemy_h_f1;
	t_texture	enemy_h_f2;
	t_texture	enemy_h_f3;
	t_texture	spike_f0;
	t_texture	spike_f1;
	t_texture	spike_f2;
	t_texture	spike_f3;
}			t_textures;

typedef struct s_mlx
{
	mlx_context		mlx;
	mlx_window		win;
	t_vec2			window_size;
	int				frame;
	t_page			page;
	t_textures		t_set;
	t_game_infos	game_i;
	double			tile_size;
	char			*file_path;
	char			brush;
	int				show_help;
}				t_mlx;

t_map		ft_get_map(char *file_path);
void		ft_init_textures(t_mlx *mlx);
void		ft_init_player(t_mlx *mlx);
void		ft_free_textures(t_mlx *mlx);
void		key_hook(int key, void *param);
void		mouse_hook(int button, void *param);
void		window_hook(int event, void *param);
void		ft_mlx_putstr(t_mlx *mlx, t_vec2 coord, mlx_color color, char *str);
int			ft_get_str_size(char *str, int font_size);
void		ft_render_player(t_mlx *mlx);
void		ft_render_map(t_mlx *mlx);
t_texture	ft_get_wall_texture(t_mlx *mlx, t_vec2 read);
void		ft_move_player(t_mlx *mlx, int key);
void		ft_print_move_count(t_mlx *mlx);
void		ft_render_end_page(t_mlx *mlx);
double		ft_get_tile_size(t_mlx *mlx);
int			ft_check_textures(void);
void		ft_init_camera_pos(t_mlx *mlx);
t_texture   ft_animation_coin(t_mlx *mlx);
t_texture   ft_animation_spikes(t_mlx *mlx);
void		ft_render_cursore(t_mlx *mlx);
void		ft_render_enemys(t_mlx *mlx);
void		ft_load_enemys(t_mlx *mlx, t_map map);
void		ft_render_help_text(t_mlx *mlx);
t_texture	ft_animation_enemy_h(t_mlx *mlx);
t_texture	ft_animation_enemy_v(t_mlx *mlx);
void		ft_check_death(t_mlx *mlx);
void		ft_render_death_page(t_mlx *mlx);
void		ft_switch_brush(t_mlx *mlx, int key);
void		ft_change_tile(t_mlx *mlx);
void		ft_move_cursore(t_mlx *mlx, int key);
void		ft_check_camera_scroll(t_mlx *mlx, int tile_size);
void		ft_save_map(t_mlx *mlx);
void		ft_free_enemys(t_mlx *mlx);

#endif
