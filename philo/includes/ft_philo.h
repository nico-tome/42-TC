/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:12:29 by ntome             #+#    #+#             */
/*   Updated: 2025/11/19 19:05:33 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_params
{
	int	philo_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	need_to_eat;
	int	error;
}				t_params;

void	ft_check_args(t_params *params, int ac, char **av);

#endif
