/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:22:30 by ntome             #+#    #+#             */
/*   Updated: 2025/12/08 12:39:11 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_philo_bonus.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	return (sign * result);
}

int	ft_check_args(t_params *params, int ac, char **av)
{
	params->start = ft_get_time();
	params->philo_num = 0;
	params->time_to_die = 0;
	params->time_to_eat = 0;
	params->time_to_sleep = 0;
	params->need_to_eat = -1;
	if (ac >= 2)
		params->philo_num = ft_atoi(av[1]);
	if (ac >= 3)
		params->time_to_die = ft_atoi(av[2]);
	if (ac >= 4)
		params->time_to_eat = ft_atoi(av[3]);
	if (ac >= 5)
		params->time_to_sleep = ft_atoi(av[4]);
	if (ac >= 6)
		params->need_to_eat = ft_atoi(av[5]);
	else
		params->need_to_eat = -1;
	if (params->philo_num < 1 || params->time_to_eat <= 0
		|| params->time_to_die <= 0 || params->time_to_sleep <= 0)
		return (0);
	return (1);
}
