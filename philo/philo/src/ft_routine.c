/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:52:30 by ntome             #+#    #+#             */
/*   Updated: 2025/11/28 23:41:20 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

void	*ft_routine(void *param)
{
	t_philosopher *philo;

	philo = param;
	ft_printf("start routine\n");
	while (1)
	{
		ft_take_fork(philo);
		ft_eating(philo);
		ft_sleeping(philo);
		ft_write_log(philo, THINKING_MSG);
	}
	return (param);
}
