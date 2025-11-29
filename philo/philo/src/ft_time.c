/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:56:04 by ntome             #+#    #+#             */
/*   Updated: 2025/11/29 17:50:37 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"
#include <pthread.h>

long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec / 1000 + time.tv_sec * 1000);
}

void	ft_mssleep(t_philosopher *philo, int sleep_time)
{
	int	sleep_total;

	(void)philo;
	sleep_total = 0;
	while (sleep_total < sleep_time)
	{
		usleep(10);
		sleep_total += 10;
		//TODO mutex check running
	}
}
