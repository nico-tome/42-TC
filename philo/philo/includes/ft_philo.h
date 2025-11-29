/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:12:29 by ntome             #+#    #+#             */
/*   Updated: 2025/11/29 11:24:03 by ntome            ###   ########.fr       */
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
# include "../libs/printf/ft_printf.h"

# define EATING_MSG "is eating\n"
# define THINKING_MSG "is thinking\n"
# define SLEEPING_MSG "is sleeping\n"
# define TAKING_FORK_MSG "has taken a fork\n"
# define DIED_MSG "died\n"

typedef struct s_params
{
	int	philo_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	need_to_eat;
}				t_params;

typedef struct s_philosopher
{
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	int				eat_count;
	int				last_eat;
	t_params		*params;
	int				idx;
	pthread_mutex_t	*writing;
}				t_philosopher;

typedef struct s_simulation
{
	t_params		params;
	pthread_t		*threads;
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	int				running;
}				t_simulation;

int		ft_check_args(t_params *params, int ac, char **av);
void	ft_init_philos(t_simulation *simulation, t_params params);
void	ft_free_mutexs(t_simulation *simulation, int mutex_count);
void	ft_free_threads(t_simulation *simulation, int thread_count);
void	ft_free_simulation(t_simulation *simulation);
void	*ft_routine(void *param);
int		ft_get_time(void);
void	ft_mssleep(t_philosopher *philo, int sleep_time);
void	ft_sleeping(t_philosopher *philo);
void	ft_eating(t_philosopher *philo);
void	ft_take_fork(t_philosopher *philo);
void	ft_write_log(t_philosopher *philo, char *msg);

#endif
