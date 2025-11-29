/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:52:30 by ntome             #+#    #+#             */
/*   Updated: 2025/11/29 18:09:11 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"
#include <pthread.h>

void	*ft_routine(void *param)
{
	t_philosopher	*philo;

	philo = param;
	if (philo->idx % 2 == 0)
		usleep(50);
	while (1)
	{
		ft_write_log(philo, THINKING_MSG);
		ft_take_fork(philo);
		ft_eating(philo);
		ft_sleeping(philo);
		pthread_mutex_lock(philo->check);
		if (philo->fork_right)
	}
	return (param);
}
