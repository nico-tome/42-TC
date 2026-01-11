/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:12:29 by ntome             #+#    #+#             */
/*   Updated: 2026/01/11 21:10:25 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_BONUS_H
# define FT_PHILO_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/time.h>
# include <stdio.h>
# include <semaphore.h>
# include <sys/wait.h>

# define EATING_MSG      "\033[0;92mis eating\n\033[0m"
# define THINKING_MSG    "\033[0;93mis thinking\n\033[0m"
# define SLEEPING_MSG    "\033[0;94mis sleeping\n\033[0m"
# define TAKING_FORK_MSG "\033[0;93mhas taken a fork\n\033[0m"
# define DIED_MSG        "\033[0;91mdied\n\033[0m"
# define FORK_SEM "/forks_sem"
# define WRITE_SEM "/write_sem"
# define CHECK_SEM "/check_sem"
# define RUN_SEM "/run_sem"

typedef struct s_params
{
	int			philo_num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			need_to_eat;
	long long	start;
}				t_params;

typedef struct s_semaphores
{
	sem_t	*writing;
	sem_t	*check;
	sem_t	*running;
	sem_t	*forks;
}				t_semaphores;

typedef struct s_philosopher
{
	long long		last_eat;
	t_params		*params;
	t_semaphores	*semaphores;
	int				eat_count;
	int				idx;
	int				*running;
}				t_philosopher;

typedef struct s_simulation
{
	pthread_t		*threads;
	t_philosopher	*philosophers;
	t_semaphores	semaphores;
	t_params		params;
	int				*pids;
	int				running;
}				t_simulation;

int			ft_check_args(t_params *params, int ac, char **av);
void		ft_init_philos(t_simulation *simulation, t_params params);
void		ft_free_semaphores(t_simulation *simulation);
void		ft_free_threads(t_simulation *simulation, int thread_count);
void		ft_free_simulation(t_simulation *simulation);
void		*ft_routine(void *param);
void		ft_mssleep(t_philosopher *philo, int sleep_time);
void		ft_sleeping(t_philosopher *philo);
void		ft_eating(t_philosopher *philo);
void		ft_take_fork(t_philosopher *philo);
void		ft_write_log(t_philosopher *philo, char *msg);
long long	ft_get_time(void);

#endif
