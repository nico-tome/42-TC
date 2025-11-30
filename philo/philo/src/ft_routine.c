/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:52:30 by ntome             #+#    #+#             */
/*   Updated: 2025/11/30 14:05:55 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

void	*ft_routine(void *param)
{
	int				stop;
	t_philosopher	*philo;

	philo = param;
	if (philo->idx % 2 == 0)
		usleep(50);
	while (1)
	{
		stop = 0;
		ft_write_log(philo, THINKING_MSG);
		ft_take_fork(philo);
		ft_eating(philo);
		ft_sleeping(philo);
		pthread_mutex_lock(&philo->mutexs->check);
		if (!philo->running)
			stop = 1;
		pthread_mutex_unlock(&philo->mutexs->check);
		if (stop)
			break;
	}
	return (param);
}
