/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:09:20 by ntome             #+#    #+#             */
/*   Updated: 2025/11/29 11:28:16 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

int	main(int ac, char **av)
{
	t_params		params;
	t_simulation	simulation;

	if (!ft_check_args(&params, ac, av))
	{
		write(2, "Args error !\n", 13);
		exit(EXIT_FAILURE);
	}
	simulation.running = 1;
	ft_init_philos(&simulation, params);
}
