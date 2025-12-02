/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_log.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 23:28:26 by ntome             #+#    #+#             */
/*   Updated: 2025/12/01 23:23:48 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

void	ft_write_log(t_philosopher *philo, char *msg)
{
	long long	time;

	pthread_mutex_lock(&philo->mutexs->writing);
	time = ft_get_time() - philo->params->start;
	printf("%lld %d %s", time, philo->idx, msg);
	pthread_mutex_unlock(&philo->mutexs->writing);
}
