/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:09:20 by ntome             #+#    #+#             */
/*   Updated: 2026/01/11 15:07:58 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"
#include <pthread.h>

void	ft_exit(t_simulation *simulation)
{
	pthread_mutex_lock(&simulation->mutexs.check);
	simulation->running = 0;
	pthread_mutex_unlock(&simulation->mutexs.check);
	ft_free_threads(simulation, simulation->params.philo_num);
	ft_free_mutexs(simulation, simulation->params.philo_num);
	ft_free_simulation(simulation);
}

int	ft_check_death(t_simulation *simulation, int i)
{
	long long	time;

	time = ft_get_time() - simulation->params.start;
	pthread_mutex_lock(&simulation->mutexs.check);
	if (time - simulation->philosophers[i].last_eat
		> simulation->params.time_to_die)
	{
		pthread_mutex_unlock(&simulation->mutexs.check);
		return (1);
	}
	pthread_mutex_unlock(&simulation->mutexs.check);
	return (0);
}

int	ft_check_fills(t_simulation *simulation, int i)
{
	pthread_mutex_lock(&simulation->mutexs.check);
	if (simulation->philosophers[i].eat_count
		> simulation->params.need_to_eat && simulation->params.need_to_eat > 0)
	{
		pthread_mutex_unlock(&simulation->mutexs.check);
		return (1);
	}
	pthread_mutex_unlock(&simulation->mutexs.check);
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
		usleep(10);
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
	usleep(10);
	ft_monitoring(&simulation);
}
