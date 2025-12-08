/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:52:30 by ntome             #+#    #+#             */
/*   Updated: 2025/12/08 15:53:24 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_philo_bonus.h"

int	ft_check_running(t_philosopher *philo)
{
	int	running;

	sem_wait(philo->semaphores->check);
	running = *philo->running;
	sem_post(philo->semaphores->check);
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
