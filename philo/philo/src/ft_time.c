/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:56:04 by ntome             #+#    #+#             */
/*   Updated: 2025/12/03 17:32:41 by ntome            ###   ########.fr       */
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
	while (ft_get_time() - start < (long long)sleep_time)
	{
		if (ft_get_time() - start >= philo->params->time_to_die)
			break ;
		usleep(10);
	}
}
