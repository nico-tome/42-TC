/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:09:20 by ntome             #+#    #+#             */
/*   Updated: 2026/01/11 22:52:29 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_philo_bonus.h"
#include <semaphore.h>
#include <unistd.h>

void	ft_exit(t_simulation *simulation)
{
	sem_wait(simulation->semaphores.check);
	simulation->running = 0;
	sem_post(simulation->semaphores.check);
	ft_free_threads(simulation, simulation->params.philo_num);
	ft_free_semaphores(simulation);
	ft_free_simulation(simulation);
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

void	ft_end_all(t_simulation *simulation)
{
	int	i;

	i = 0;
	while (i <= simulation->params.philo_num)
	{
		sem_post(simulation->semaphores.running);
		i++;
	}
}

void	ft_monitoring(t_simulation *simulation)
{
	int	stop;
	int	i;
	int	time;
	int	tot_eat;

	stop = 0;
	while (!stop)
	{
		tot_eat = 0;
		i = 0;
		while (i < simulation->params.philo_num)
		{
			tot_eat = ft_check_fills(simulation, i);
			sem_wait(simulation->semaphores.check);
			time = ft_get_time() - simulation->params.start;
			stop = time - simulation->philosophers[i].last_eat >= simulation->params.time_to_die;
			i++;
			sem_post(simulation->semaphores.check);
		}
		if (tot_eat == simulation->params.philo_num)
			break ;
	}
	ft_end_all(simulation);
	sem_post(simulation->semaphores.check);
	ft_write_log(&simulation->philosophers[i - 1], DIED_MSG);
}

int	main(int ac, char **av)
{
	t_params		params;
	t_simulation	simulation;
	int				i;

	if (!ft_check_args(&params, ac, av))
	{
		write(2, "Args error !\n", 13);
		exit(EXIT_FAILURE);
	}
	simulation.running = 1;
	ft_init_philos(&simulation, params);
	i = 0;
	ft_monitoring(&simulation);
	while (i < params.philo_num)
	{
		waitpid(simulation.pids[i], 0, 0);
		i++;
	}
}
