/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:04:14 by ntome             #+#    #+#             */
/*   Updated: 2026/01/11 15:08:34 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"
#include <pthread.h>

void	ft_take_fork(t_philosopher *philo)
{
	if (philo->params->philo_num == 1)
	{
		ft_write_log(philo, TAKING_FORK_MSG);
		ft_mssleep(philo, philo->params->time_to_die);
		return ;
	}
	if (philo->idx % 2 == 1)
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

	if (philo->params->philo_num == 1)
		return ;
	time = ft_get_time() - philo->params->start;
	pthread_mutex_lock(&philo->mutexs->check);
	philo->last_eat = time;
	pthread_mutex_unlock(&philo->mutexs->check);
	ft_write_log(philo, EATING_MSG);
	ft_mssleep(philo, philo->params->time_to_eat);
	pthread_mutex_lock(&philo->mutexs->check);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->mutexs->check);
	if (philo->idx % 2 == 1)
	{
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
	}
	else
	{
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
	}
}

void	ft_sleeping(t_philosopher *philo)
{
	ft_write_log(philo, SLEEPING_MSG);
	ft_mssleep(philo, philo->params->time_to_sleep);
}
