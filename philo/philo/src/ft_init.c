/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:29:37 by ntome             #+#    #+#             */
/*   Updated: 2025/11/30 17:02:06 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

void	ft_init_value(t_simulation *simulation, int idx)
{
	int	idx2;

	idx2 = (idx + 1) % simulation->params.philo_num;
	simulation->philosophers[idx].idx = idx;
	simulation->philosophers[idx].eat_count = 0;
	simulation->philosophers[idx].last_eat = 0;
	simulation->philosophers[idx].fork_left = &simulation->forks[idx];
	if (simulation->params.philo_num == 1)
		simulation->philosophers[idx].fork_right = NULL;
	else
		simulation->philosophers[idx].fork_right = &simulation->forks[idx2];
	simulation->philosophers[idx].mutexs = &simulation->mutexs;
	simulation->philosophers[idx].params = &simulation->params;
}

int	ft_init_forks(t_simulation *simulation)
{
	int	fork_idx;
	int	fork_count;

	fork_idx = 0;
	fork_count = 0;
	while (fork_idx < simulation->params.philo_num)
	{
		if (!pthread_mutex_init(&simulation->forks[fork_idx], NULL))
			fork_count++;
		fork_idx++;
	}
	if (fork_count != simulation->params.philo_num)
		ft_free_mutexs(simulation, fork_count);
	return (fork_count == simulation->params.philo_num);
}

int	ft_init_threads(t_simulation *simulation)
{
	int	thread_idx;
	int	thread_count;

	thread_idx = 0;
	thread_count = 0;
	while (thread_idx < simulation->params.philo_num)
	{
		if (!pthread_create(&simulation->threads[thread_idx], NULL,
				ft_routine, &simulation->philosophers[thread_idx]))
			thread_count++;
		thread_idx++;
	}
	if (thread_count != simulation->params.philo_num)
		ft_free_threads(simulation, thread_count);
	return (thread_count == simulation->params.philo_num);
}

void	ft_init_philos(t_simulation *simulation, t_params params)
{
	int	i;

	simulation->params = params;
	simulation->forks = malloc(sizeof(pthread_mutex_t) * params.philo_num);
	simulation->philosophers = malloc(sizeof(t_philosopher) * params.philo_num);
	simulation->threads = malloc(sizeof(pthread_t) * params.philo_num);
	if (!simulation->philosophers || !simulation->forks || !simulation->threads)
		ft_free_simulation(simulation);
	if (!ft_init_forks(simulation))
		ft_free_simulation(simulation);
	i = 0;
	while (i < params.philo_num)
		ft_init_value(simulation, i++);
	if (!ft_init_threads(simulation))
	{
		ft_free_mutexs(simulation, params.philo_num);
		ft_free_simulation(simulation);
	}
}
