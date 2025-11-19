/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:22:30 by ntome             #+#    #+#             */
/*   Updated: 2025/11/19 19:06:30 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

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

void	ft_check_args(t_params *params, int ac, char **av)
{
	params->philo_num = 0;
	params->time_to_die = 0;
	params->time_to_eat = 0;
	params->time_to_sleep = 0;
	params->need_to_eat = 0;
	params->error = 0;
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
	if (params->philo_num < 2 || params->time_to_eat <= 0 
		|| params->time_to_die <= 0 || params->time_to_sleep <= 0)
		params->error = 1;
}
