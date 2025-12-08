/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:20:12 by ntome             #+#    #+#             */
/*   Updated: 2025/12/08 16:15:42 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_philo_bonus.h"

void	ft_free_semaphores(t_simulation *simulation)
{
	if (simulation->semaphores.check != SEM_FAILED)
		sem_close(simulation->semaphores.check);
	if (simulation->semaphores.running != SEM_FAILED)
		sem_close(simulation->semaphores.running);
	if (simulation->semaphores.writing)
		sem_close(simulation->semaphores.writing);
	if (simulation->semaphores.forks != SEM_FAILED)
		sem_close(simulation->semaphores.forks);
}

void	ft_free_threads(t_simulation *simulation, int thread_count)
{
	int	thread_idx;

	thread_idx = 0;
	while (thread_idx < thread_count)
	{
		pthread_join(simulation->threads[thread_idx], NULL);
		thread_idx++;
	}
}

void	ft_free_simulation(t_simulation *simulation)
{
	if (simulation->philosophers)
		free(simulation->philosophers);
	if (simulation->threads)
		free(simulation->threads);
	exit(EXIT_FAILURE);
}
