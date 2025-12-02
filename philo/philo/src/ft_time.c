/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:56:04 by ntome             #+#    #+#             */
/*   Updated: 2025/12/01 23:33:43 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec / 1000 + time.tv_sec * 1000);
}

void	ft_mssleep(t_philosopher *philo, int sleep_time)
{
	long long	start;

	start = ft_get_time();
	while (ft_get_time() - start < sleep_time)
	{
		printf("time: %lld - %lld = %lld\n", ft_get_time(), start, ft_get_time() - start);
		if (ft_get_time() - start >= philo->params->time_to_die)
			break;
		usleep(10);
	}
}
