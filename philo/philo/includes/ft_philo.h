/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:12:29 by ntome             #+#    #+#             */
/*   Updated: 2025/11/30 17:07:09 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

# define EATING_MSG "is eating\n"
# define THINKING_MSG "is thinking\n"
# define SLEEPING_MSG "is sleeping\n"
# define TAKING_FORK_MSG "has taken a fork\n"
# define DIED_MSG "died\n"

typedef struct s_params
{
	int			philo_num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			need_to_eat;
	long long	start;
}				t_params;

typedef struct	s_mutexs
{
	pthread_mutex_t	writing;
	pthread_mutex_t	check;
	pthread_mutex_t	running;
}				t_mutexs;

typedef struct s_philosopher
{
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	long long		last_eat;
	t_params		*params;
	t_mutexs		*mutexs;
	int				*running;
	int				eat_count;
	int				idx;
}				t_philosopher;

typedef struct s_simulation
{
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	t_philosopher	*philosophers;
	t_mutexs		mutexs;
	t_params		params;
	int				running;
}				t_simulation;

int			ft_check_args(t_params *params, int ac, char **av);
void		ft_init_philos(t_simulation *simulation, t_params params);
void		ft_free_mutexs(t_simulation *simulation, int mutex_count);
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
