/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:29:37 by ntome             #+#    #+#             */
/*   Updated: 2026/01/11 23:11:25 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_philo_bonus.h"
#include <semaphore.h>
#include <unistd.h>

void	ft_init_value(t_simulation *simulation, int idx)
{
	simulation->philosophers[idx].idx = idx;
	simulation->philosophers[idx].eat_count = 0;
	simulation->philosophers[idx].last_eat = 0;
	simulation->philosophers[idx].semaphores = &simulation->semaphores;
	simulation->philosophers[idx].params = &simulation->params;
	simulation->philosophers[idx].running = &simulation->running;
}

int	ft_init_semaphores(t_simulation *simulation)
{
	int	num;

	num = simulation->params.philo_num;
	sem_unlink(RUN_SEM);
	sem_unlink(CHECK_SEM);
	sem_unlink(WRITE_SEM);
	sem_unlink(FORK_SEM);
	simulation->semaphores.running = sem_open(RUN_SEM, O_CREAT, 644, 0);
	simulation->semaphores.check = sem_open(CHECK_SEM, O_CREAT, 644, 1);
	simulation->semaphores.writing = sem_open(WRITE_SEM, O_CREAT, 644, 1);
	simulation->semaphores.forks = sem_open(FORK_SEM, O_CREAT, 644, num);
	if (simulation->semaphores.forks == SEM_FAILED
		|| simulation->semaphores.writing == SEM_FAILED
		|| simulation->semaphores.check == SEM_FAILED
		|| simulation->semaphores.running == SEM_FAILED)
		return (0);
	sem_post(simulation->semaphores.running);
	sem_wait(simulation->semaphores.running);
	return (1);
}

void	*ft_check_running(void *params)
{
	t_simulation	*simulation;

	simulation = params;
	sem_wait(simulation->semaphores.running);
	sem_wait(simulation->semaphores.check);
	simulation->running = 0;
	sem_post(simulation->semaphores.check);
	return (simulation);
}

int	check_run(t_simulation *simulation)
{
	sem_wait(simulation->semaphores.check);
	if (simulation->running == 0)
	{
		sem_post(simulation->semaphores.check);
		return (0);
	}
	sem_post(simulation->semaphores.check);
	return (1);
}

void	ft_launch_philo(t_simulation *simulation, int i)
{
	pthread_t	check_death;

	simulation->philosophers[i].idx = i;
	if (i % 2 == 1)
		usleep(20);
	if (pthread_create(&check_death, NULL, ft_check_running, simulation))
	{
		sem_wait(simulation->semaphores.running);
		ft_free_semaphores(simulation);
		return ;
	}
	while (check_run(simulation))
	{
		ft_take_fork(&simulation->philosophers[i]);
		ft_eating(&simulation->philosophers[i]);
		ft_sleeping(&simulation->philosophers[i]);
	}
	pthread_join(check_death, NULL);
}

void	ft_init_philos(t_simulation *simulation, t_params params)
{
	int	i;

	simulation->philosophers = malloc(sizeof(t_philosopher) * params.philo_num);
	simulation->pids = malloc(sizeof(int) * params.philo_num);
	if (!simulation->pids)
		return ;
	simulation->params = params;
	if (!ft_init_semaphores(simulation))
		free(simulation->pids);
	i = -1;
	while (i++ < params.philo_num)
	{
		ft_init_value(simulation, i);
		simulation->pids[i] = 0;
	}
	i = -1;
	while (++i < params.philo_num)
	{
		simulation->pids[i] = fork();
		if (simulation->pids[i] == 0)
		{
			ft_launch_philo(simulation, i);
			exit(EXIT_SUCCESS);
		}
	}
}
