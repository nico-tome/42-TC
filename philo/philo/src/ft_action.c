/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:04:14 by ntome             #+#    #+#             */
/*   Updated: 2026/01/09 22:13:28 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

void	ft_take_fork(t_philosopher *philo)
{
	if (philo->idx % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_right);
		ft_write_log(philo, TAKING_FORK_MSG);
		pthread_mutex_lock(philo->fork_left);
		ft_write_log(philo, TAKING_FORK_MSG);
	}
	else
	{
		pthread_mutex_lock(philo->fork_left);
		ft_write_log(philo, TAKING_FORK_MSG);
		pthread_mutex_lock(philo->fork_right);
		ft_write_log(philo, TAKING_FORK_MSG);
	}
}

void	ft_eating(t_philosopher *philo)
{
	int	time;

	time = ft_get_time() - philo->params->start;
	pthread_mutex_lock(&philo->mutexs->check);
	philo->last_eat = time;
	pthread_mutex_unlock(&philo->mutexs->check);
	ft_write_log(philo, EATING_MSG);
	ft_mssleep(philo, philo->params->time_to_eat);
	pthread_mutex_lock(&philo->mutexs->check);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->mutexs->check);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
}

void	ft_sleeping(t_philosopher *philo)
{
	ft_write_log(philo, SLEEPING_MSG);
	ft_mssleep(philo, philo->params->time_to_sleep);
}
