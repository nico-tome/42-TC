/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_log.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 23:28:26 by ntome             #+#    #+#             */
/*   Updated: 2025/11/29 18:07:00 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

void	ft_write_log(t_philosopher *philo, char *msg)
{
	long long	time;

	time = ft_get_time() - philo->params->start;
	pthread_mutex_lock(philo->writing);
	printf("%lld %d %s", time, philo->idx, msg);
	pthread_mutex_unlock(philo->writing);
}
