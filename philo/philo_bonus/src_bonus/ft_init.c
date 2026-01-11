/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:29:37 by ntome             #+#    #+#             */
/*   Updated: 2026/01/11 15:13:16 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_philo_bonus.h"
#include <semaphore.h>

void	ft_init_value(t_simulation *simulation, int idx)
{
	simulation->philosophers[idx].idx = idx;
	simulation->philosophers[idx].eat_count = 0;
	simulation->philosophers[idx].last_eat = 0;
	simulation->philosophers[idx].semaphores = &simulation->semaphores;
	simulation->philosophers[idx].params = &simulation->params;
	simulation->philosophers[idx].running = &simulation->running;
}

int	ft_init_semaphores(t_simulation *simulation)
{
	int	num;

	num = simulation->params.philo_num;
	sem_unlink(RUN_SEM);
	sem_unlink(CHECK_SEM);
	sem_unlink(WRITE_SEM);
	sem_unlink(FORK_SEM);
	simulation->semaphores.running = sem_open(RUN_SEM, O_CREAT, 644, 1);
	simulation->semaphores.check = sem_open(CHECK_SEM, O_CREAT, 644, 1);
	simulation->semaphores.writing = sem_open(WRITE_SEM, O_CREAT, 644, 1);
	simulation->semaphores.forks = sem_open(FORK_SEM, O_CREAT, 644, num);
	if (simulation->semaphores.forks == SEM_FAILED
		|| simulation->semaphores.writing == SEM_FAILED
		|| simulation->semaphores.check == SEM_FAILED
		|| simulation->semaphores.running == SEM_FAILED)
		return (0);
	return (1);
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
	simulation->philosophers = malloc(sizeof(t_philosopher) * params.philo_num);
	simulation->threads = malloc(sizeof(pthread_t) * params.philo_num);
	if (!simulation->philosophers || !simulation->threads)
		ft_free_simulation(simulation);
	if (!ft_init_semaphores(simulation))
	{
		ft_free_semaphores(simulation);
		ft_free_simulation(simulation);
	}
	i = 0;
	while (i < params.philo_num)
		ft_init_value(simulation, i++);
	if (!ft_init_threads(simulation))
	{
		ft_free_semaphores(simulation);
		ft_free_simulation(simulation);
	}
}
