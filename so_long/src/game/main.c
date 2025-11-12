/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:53:53 by ntome             #+#    #+#             */
/*   Updated: 2025/11/12 20:44:59 by ntome            ###   ########.fr       */
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
	ft_printf("YAY !\n");
}
