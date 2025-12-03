/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_log.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 23:28:26 by ntome             #+#    #+#             */
/*   Updated: 2025/12/03 17:39:13 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

void	ft_write_log(t_philosopher *philo, char *msg)
{
	long long	time;

	pthread_mutex_lock(&philo->mutexs->writing);
	pthread_mutex_lock(&philo->mutexs->check);
	if (!*philo->running)
	{
		pthread_mutex_unlock(&philo->mutexs->check);
		pthread_mutex_unlock(&philo->mutexs->writing);
		return ;
	}
	time = ft_get_time() - philo->params->start;
	printf("%lld %d %s", time, philo->idx, msg);
	pthread_mutex_unlock(&philo->mutexs->check);
	pthread_mutex_unlock(&philo->mutexs->writing);
}
