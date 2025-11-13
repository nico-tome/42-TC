/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:53:53 by ntome             #+#    #+#             */
/*   Updated: 2025/11/13 22:16:37 by ntome            ###   ########.fr       */
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

void	ft_init_app(void)
{
	mlx_context mlx = mlx_init();

    mlx_window_create_info window_info = { 0 };
    window_info.title = "Hello World!";
    window_info.width = 400;
    window_info.height = 400;
    mlx_window win = mlx_new_window(mlx, &window_info);

    mlx_image target = mlx_new_image(mlx, 100, 100);

    mlx_window_create_info target_info = { 0 };
    target_info.render_target = target;
    mlx_window target_win = mlx_new_window(mlx, &target_info);

    {
        // All of this will be rendered in `target`
        mlx_clear_window(mlx, target_win, (mlx_color){ .rgba = 0xC16868FF });
        mlx_string_put(mlx, target_win, 10, 10, (mlx_color){ .rgba = 0xFF2066FF }, "text");
        mlx_pixel_put(mlx, target_win, 20, 40, (mlx_color){ .rgba = 0xFF0000FF });
    }

    mlx_put_image_to_window(mlx, win, target, 10, 10); // Render the target to the real window

    mlx_destroy_window(mlx, target_win);
    mlx_destroy_image(mlx, target);

    mlx_destroy_window(mlx, win);

    mlx_destroy_context(mlx);
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
	ft_init_app();
}
