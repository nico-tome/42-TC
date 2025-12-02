/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:09:20 by ntome             #+#    #+#             */
/*   Updated: 2025/12/01 23:29:38 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"
#include <pthread.h>

int	ft_check_death(t_simulation *simulation, int i)
{
	long long	time;

	time = ft_get_time();
	pthread_mutex_lock(&simulation->mutexs.check);
	if (time - simulation->philosophers[i].last_eat
		> simulation->params.time_to_die)
	{
		pthread_mutex_unlock(&simulation->mutexs.check);
		return (1);
	}
	pthread_mutex_unlock(&simulation->mutexs.check);
	return (0);
}

int	ft_check_fills(t_simulation *simulation, int i)
{
	long long	time;

	time = ft_get_time();
	pthread_mutex_lock(&simulation->mutexs.check);
	if (time - simulation->philosophers[i].eat_count
		> simulation->params.need_to_eat)
	{
		pthread_mutex_unlock(&simulation->mutexs.check);
		return (1);
	}
	pthread_mutex_unlock(&simulation->mutexs.check);
	return (0);
}

void	ft_monitoring(t_simulation *simulation)
{
	int	i;
	//int	count;

	while (1)
	{
		i = 0;
		//count = 0;
		while (i < simulation->params.philo_num)
		{
			if (ft_check_death(simulation, i))
			{
				simulation->running = 0;
				printf("%d dead\n", i);
				exit(EXIT_SUCCESS);
			}
			//count += ft_check_fills(simulation, i);
			i++;
		}
		//if (count == simulation->params.philo_num && simulation->params.need_to_eat > 0)
		//{
		//	simulation->running = 0;
		//	printf("bad \n");
		//	exit(EXIT_SUCCESS);
		//}
	}
}

int	main(int ac, char **av)
{
	t_params		params;
	t_simulation	simulation;

	if (!ft_check_args(&params, ac, av))
	{
		write(2, "Args error !\n", 13);
		exit(EXIT_FAILURE);
	}
	simulation.running = 1;
	ft_init_philos(&simulation, params);
	ft_monitoring(&simulation);
}
