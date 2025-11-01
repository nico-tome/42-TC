/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:54:56 by ntome             #+#    #+#             */
/*   Updated: 2025/11/01 19:20:11 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

int	ft_is_valide(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!ft_is_valide(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_args(int ac, char **args)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (ac == 2)
	{
		while (args[1][i])
		{
			count++;
			i++;
		}
	}
	else
	{
		i = 1;
		while (args[i])
		{
			count++;
			i++;
		}
	}
	return (count);
}

int	*ft_parse_multiple_args(int size, char **args)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 1;
	while (args[i])
	{
		tab[i - 1] = ft_atoi(args[i]);
		i++;
	}
	return (tab);
}
