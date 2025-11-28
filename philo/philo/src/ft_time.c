/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:56:04 by ntome             #+#    #+#             */
/*   Updated: 2025/11/28 22:26:43 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

int	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec / 1000 + time.tv_sec * 1000);
}

void	ft_mssleep(t_philosopher *philo, int sleep_time)
{
	int	sleep_total;

	sleep_total = 0;
	while (sleep_total < sleep_time)
	{
		usleep(10);
		sleep_total += 10;
		if (ft_get_time() - philo->last_eat >= philo->params->time_to_die)
			return;
	}
}
