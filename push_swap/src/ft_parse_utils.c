/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:54:56 by ntome             #+#    #+#             */
/*   Updated: 2025/11/23 23:12:34 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_free_tmp_list(char **tmp_split, int *final_args)
{
	int	i;

	i = 0;
	while (tmp_split[i])
	{
		free(tmp_split[i]);
		i++;
	}
	free(tmp_split);
	free(final_args);
	ft_error_exit();
}

int	ft_is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	if (!ft_check_overflow(str))
		return (0);
	return (1);
}

int	*ft_parse_args(int ac, char **av, int size)
{
	int		*final_args;
	int		av_i;
	int		list_i;
	int		tmp_list_i;
	char	**tmp_split;

	av_i = 1;
	list_i = 0;
	final_args = malloc(sizeof(int) * size);
	while (final_args && av_i < ac)
	{
		tmp_split = ft_split(av[av_i], ' ');
		tmp_list_i = 0;
		while (tmp_split[tmp_list_i])
		{
			if (!ft_is_valid(tmp_split[tmp_list_i]))
				ft_free_tmp_list(tmp_split, final_args);
			final_args[list_i] = ft_atoi(tmp_split[tmp_list_i]);
			list_i++;
			tmp_list_i++;
		}
		ft_free_char_starstar(tmp_split);
		av_i++;
	}
	return (final_args);
}
