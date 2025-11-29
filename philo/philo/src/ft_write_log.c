/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_log.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 23:28:26 by ntome             #+#    #+#             */
/*   Updated: 2025/11/29 10:41:10 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

void	ft_write_log(t_philosopher *philo, char *msg)
{
	int	time;

	time = ft_get_time();
	pthread_mutex_lock(philo->writing);
	printf("%d %d %s", time, philo->idx, msg);
	pthread_mutex_unlock(philo->writing);
}
