/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:53:53 by ntome             #+#    #+#             */
/*   Updated: 2025/11/21 23:12:30 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/ft_so_long_bonus.h"
#include "../../includes_bonus/ft_error_bonus.h"
#include "../../includes_bonus/ft_parsing_bonus.h"

void	ft_free_map(t_map map)
{
	int	i;

	i = 0;
	while (map.map[i])
	{
		free(map.map[i]);
		i++;
	}
	free(map.map);
}

void	update(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx->frame++;
	mlx_clear_window(mlx->mlx, mlx->win, (mlx_color){.rgba = COLOR_BLACK});
	if (mlx->page == GAME_PAGE)
	{
		ft_render_map(mlx);
		ft_render_player(mlx);
		ft_render_enemys(mlx);
		ft_check_death(mlx);
		ft_print_move_count(mlx);
	}
	if (mlx->page == EDITOR_PAGE)
	{
		ft_render_map(mlx);
		ft_render_enemys(mlx);
		ft_render_cursore(mlx);
		ft_render_help_text(mlx);
	}
	if (mlx->page == END_PAGE)
		ft_render_end_page(mlx);
	if (mlx->page == DEATH_PAGE)
		ft_render_death_page(mlx);
}

void	ft_init_event(t_mlx *mlx)
{
	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, key_hook, mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_MOUSEDOWN, mouse_hook, mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_WINDOW_EVENT, window_hook, mlx);
}

void	ft_init_app(t_map map, char *file_path)
{
	static t_mlx			mlx;
	mlx_window_create_info	info;

	mlx.mlx = mlx_init();
	info = (mlx_window_create_info){0};
	info.title = "SO LONG";
	info.width = 1280;
	info.height = 720;
	mlx.win = mlx_new_window(mlx.mlx, &info);
	mlx.page = GAME_PAGE;
	mlx.window_size = (t_vec2){.x = 1280, .y = 720};
	mlx.game_i.map = map;
	mlx.frame = -1;
	mlx.file_path = file_path;
	ft_init_textures(&mlx);
	ft_init_player(&mlx);
	ft_load_enemys(&mlx, map);
	mlx.tile_size = ft_get_tile_size(&mlx);
	ft_init_camera_pos(&mlx);
	ft_init_event(&mlx);
	mlx_add_loop_hook(mlx.mlx, update, &mlx);
	mlx_loop(mlx.mlx);
	ft_free_textures(&mlx);
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_context(mlx.mlx);
}

int	main(int ac, char **av)
{
	t_map	map;
	int		map_validity;

	if (ac != 2)
		ft_exit_error(ARGS_MORE_ERROR_CODE);
	map = ft_get_map(av[1]);
	map_validity = ft_check_map(map);
	if (ft_is_error_code(map_validity))
	{
		ft_free_map(map);
		ft_exit_error(map_validity);
	}
	if (!ft_check_textures())
	{
		ft_free_map(map);
		ft_exit_error(TEXTURE_ERROR_CODE);
	}
	ft_init_app(map, av[1]);
	ft_free_map(map);
}
