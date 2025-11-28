/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:20:12 by ntome             #+#    #+#             */
/*   Updated: 2025/11/28 15:42:14 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

void	ft_free_mutexs(t_simulation *simulation, int mutex_count)
{
	int	mutex_idx;

	mutex_idx = 0;
	while (mutex_idx < mutex_count)
	{
		pthread_mutex_destroy(&simulation->forks[mutex_idx]);
		mutex_idx++;
	}
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
	if (simulation->forks)
		free(simulation->forks);
	exit(EXIT_FAILURE);
}
