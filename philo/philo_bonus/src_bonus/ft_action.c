/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:04:14 by ntome             #+#    #+#             */
/*   Updated: 2026/01/11 23:11:17 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_philo_bonus.h"

void	ft_take_fork(t_philosopher *philo)
{
	if (philo->params->philo_num == 1)
	{
		ft_write_log(philo, TAKING_FORK_MSG);
		ft_mssleep(philo, philo->params->time_to_die);
		return ;
	}
	sem_wait(philo->semaphores->forks);
	ft_write_log(philo, TAKING_FORK_MSG);
	sem_wait(philo->semaphores->forks);
	ft_write_log(philo, TAKING_FORK_MSG);
}

void	ft_eating(t_philosopher *philo)
{
	int	time;

	if (philo->params->philo_num == 1)
		return ;
	time = ft_get_time() - philo->params->start;
	sem_wait(philo->semaphores->check);
	philo->last_eat = time;
	sem_post(philo->semaphores->check);
	ft_write_log(philo, EATING_MSG);
	ft_mssleep(philo, philo->params->time_to_eat);
	sem_wait(philo->semaphores->check);
	philo->eat_count++;
	sem_post(philo->semaphores->check);
	sem_post(philo->semaphores->forks);
	sem_post(philo->semaphores->forks);
}

void	ft_sleeping(t_philosopher *philo)
{
	if (philo->params->philo_num == 1)
		return ;
	ft_write_log(philo, SLEEPING_MSG);
	ft_mssleep(philo, philo->params->time_to_sleep);
}
