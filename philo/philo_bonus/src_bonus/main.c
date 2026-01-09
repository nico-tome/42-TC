/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:09:20 by ntome             #+#    #+#             */
/*   Updated: 2026/01/09 21:56:21 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_philo_bonus.h"
#include <semaphore.h>

void	ft_exit(t_simulation *simulation)
{
	sem_wait(simulation->semaphores.check);
	simulation->running = 0;
	sem_post(simulation->semaphores.check);
	ft_free_threads(simulation, simulation->params.philo_num);
	ft_free_semaphores(simulation);
	ft_free_simulation(simulation);
}

int	ft_check_death(t_simulation *simulation, int i)
{
	long long	time;

	time = ft_get_time();
	sem_wait(simulation->semaphores.check);
	if (time - simulation->philosophers[i].last_eat
		> simulation->params.time_to_die)
	{
		sem_post(simulation->semaphores.forks);
		sem_post(simulation->semaphores.check);
		return (1);
	}
	sem_post(simulation->semaphores.check);
	return (0);
}

int	ft_check_fills(t_simulation *simulation, int i)
{
	sem_wait(simulation->semaphores.check);
	if (simulation->philosophers[i].eat_count
		> simulation->params.need_to_eat && simulation->params.need_to_eat > 0)
	{
		sem_post(simulation->semaphores.check);
		return (1);
	}
	sem_post(simulation->semaphores.check);
	return (0);
}

void	ft_monitoring(t_simulation *simulation)
{
	int	i;
	int	count;

	while (1)
	{
		i = 0;
		count = 0;
		while (i < simulation->params.philo_num)
		{
			if (ft_check_death(simulation, i))
			{
				ft_write_log(&simulation->philosophers[i], DIED_MSG);
				ft_exit(simulation);
			}
			count += ft_check_fills(simulation, i);
			if (count == simulation->params.philo_num)
				ft_exit(simulation);
			i++;
		}
	}
}

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
	ft_monitoring(&simulation);
}
