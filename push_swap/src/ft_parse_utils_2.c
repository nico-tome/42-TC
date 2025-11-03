/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:41:24 by ntome             #+#    #+#             */
/*   Updated: 2025/11/03 21:33:31 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

int	ft_check_dup(int *items, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (items[j] == items[i])
			{
				free(items);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	ft_count_total_args(int ac, char **av)
{
	int		count;
	char	**tmp_split;
	int		i;

	i = 0;
	count = 0;
	while (i < ac)
	{
		tmp_split = ft_split(av[i], ' ');
		count += ft_count_args(tmp_split);
		ft_free_char_starstar(tmp_split);
		i++;
	}
	return (count);
}

int	ft_check_overflow(char *arg)
{
	char	*itoa_arg;
	int		result;

	itoa_arg = ft_itoa(ft_atoi(arg));
	result = 1;
	if (ft_strncmp(itoa_arg, arg, ft_strlen(arg)))
		result = 0;
	free(itoa_arg);
	return (result);
}
