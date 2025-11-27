/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:12:29 by ntome             #+#    #+#             */
/*   Updated: 2025/11/27 21:12:15 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef enum e_state
{
	SLEEPING,
	EATING,
	THINKING,
}			t_state;

typedef struct s_params
{
	int	philo_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	need_to_eat;
	int	error;
}				t_params;

typedef struct s_philosopher
{
	int		*fork_left;
	int		*fork_right;
	double	start_eating;
	double	start_sleeping;
	double	start_thinking;
	t_state	state;
}				t_philosopher;

typedef struct s_simulation
{
	pthread_t		*threads;
	t_philosopher	*philosophers;
}				t_simulation;

void	ft_check_args(t_params *params, int ac, char **av);
void	ft_init_philos(t_params *params);

#endif
