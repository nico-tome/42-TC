/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:04:14 by ntome             #+#    #+#             */
/*   Updated: 2025/11/29 10:26:31 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

void	ft_take_fork(t_philosopher *philo)
{
	pthread_mutex_lock(philo->fork_right);
	ft_write_log(philo, TAKING_FORK_MSG);
	pthread_mutex_lock(philo->fork_left);
	ft_write_log(philo, TAKING_FORK_MSG);
}

void	ft_eating(t_philosopher *philo)
{
	int	time;

	time = ft_get_time();
	philo->last_eat = time;
	ft_write_log(philo, EATING_MSG);
	ft_mssleep(philo, philo->params->time_to_eat);
	philo->eat_count++;
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
}

void	ft_sleeping(t_philosopher *philo)
{
	ft_write_log(philo, SLEEPING_MSG);
	ft_mssleep(philo, philo->params->time_to_sleep);
}
