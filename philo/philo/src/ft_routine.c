/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:52:30 by ntome             #+#    #+#             */
/*   Updated: 2026/01/11 14:59:56 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

int	ft_check_running(t_philosopher *philo)
{
	int	running;

	pthread_mutex_lock(&philo->mutexs->check);
	running = *philo->running;
	pthread_mutex_unlock(&philo->mutexs->check);
	return (running);
}

void	*ft_routine(void *param)
{
	t_philosopher	*philo;

	philo = param;
	if (philo->idx % 2 == 0)
		usleep(50);
	while (ft_check_running(philo))
	{
		ft_take_fork(philo);
		ft_eating(philo);
		ft_sleeping(philo);
		ft_write_log(philo, THINKING_MSG);
	}
	return (param);
}
