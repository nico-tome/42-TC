/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_log.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 23:28:26 by ntome             #+#    #+#             */
/*   Updated: 2025/12/08 15:54:52 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_philo_bonus.h"

void	ft_write_log(t_philosopher *philo, char *msg)
{
	long long	time;

	sem_wait(philo->semaphores->writing);
	sem_wait(philo->semaphores->check);
	if (!*philo->running)
	{
		sem_post(philo->semaphores->check);
		sem_post(philo->semaphores->writing);
		return ;
	}
	time = ft_get_time() - philo->params->start;
	printf("%lld %d %s", time, philo->idx, msg);
	sem_post(philo->semaphores->check);
	sem_post(philo->semaphores->writing);
}
