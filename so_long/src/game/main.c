/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:53:53 by ntome             #+#    #+#             */
/*   Updated: 2025/11/18 14:32:03 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_so_long.h"
#include "../../includes/ft_error.h"
#include "../../includes/ft_parsing.h"

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
	if (mlx->need_update)
	{
		mlx_clear_window(mlx->mlx, mlx->win, (mlx_color){.rgba = COLOR_BLACK});
		if (mlx->page == GAME_PAGE)
		{
			ft_render_map(mlx);
			ft_render_player(mlx);
		}
		mlx->need_update = FALSE;
	}
}

void	ft_init_player(t_mlx *mlx)
{
	mlx->game_i.player_co.x = 0;
	mlx->game_i.player_co.y = 0;
}

void	ft_init_app(t_map map)
{
	static t_mlx			mlx;
	mlx_window_create_info	info = { 0 };

	mlx.mlx = mlx_init();
	info.title = "SO LONG";
	info.width = 1280;
	info.height = 720;
	mlx.win = mlx_new_window(mlx.mlx, &info);
	mlx.page = GAME_PAGE;
	mlx.game_i.map = map;
	mlx.need_update = 1;
	ft_init_textures(&mlx);
	ft_init_player(&mlx);
	mlx.tile_size = (double)info.width / ft_strlen(mlx.game_i.map.map[0]);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_MOUSEDOWN, mouse_hook, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_MOUSEWHEEL, mouse_wheel_hook, NULL);
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, window_hook, &mlx);
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
	ft_init_app(map);
	ft_free_map(map);
}
