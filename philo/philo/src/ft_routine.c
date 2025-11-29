/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:52:30 by ntome             #+#    #+#             */
/*   Updated: 2025/11/29 11:31:49 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

void	*ft_routine(void *param)
{
	t_philosopher	*philo;

	philo = param;
	ft_printf("start routine, id %d\n", philo->idx);
	if (philo->idx % 2 == 0)
		usleep(philo->params->time_to_eat);
	while (philo->eat_count < 10)
	{
		ft_take_fork(philo);
		ft_eating(philo);
		ft_sleeping(philo);
		ft_write_log(philo, THINKING_MSG);
	}
	return (param);
}
