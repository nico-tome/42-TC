/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:29:48 by ntome             #+#    #+#             */
/*   Updated: 2025/11/01 22:10:54 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

int	ft_min_in_stack(t_stack *stack)
{
	int	i;
	int	mini;

	i = 0;
	if (stack->size == 0)
		return (0);
	mini = stack->items[0];
	while (i < stack->size)
	{
		if (stack->items[i] < mini)
			mini = stack->items[i];
		i++;
	}
	return (mini);
}

int	ft_max_in_stack(t_stack *stack)
{
	int	i;
	int	max;

	if (stack->size == 0)
		return (0);
	i = 0;
	max = stack->items[0];
	while (i < stack->size)
	{
		if (stack->items[i] > max)
			max = stack->items[i];
		i++;
	}
	return (max);
}

int	ft_get_index(t_stack *stack, int item)
{
	int	i;

	i = 0;
	if (stack->size == 0)
		return (0);
	while (i < stack->size && stack->items[i] != item)
		i++;
	return (i);
}

int	ft_get_next_value(t_stack *stack, int item)
{
	int	i;
	int	value;

	i = 0;
	if (stack->size > 0)
	{
		value = stack->items[0];
		while (i < stack->size)
		{
			if (value > item || (stack->items[i] > value && stack->items[i] < item))
				value = stack->items[i];
			i++;
		}
	}
	return (value);
}

int	ft_get_prev_value(t_stack *stack, int item)
{
	int	i;
	int	value;

	i = 0;
	if (stack->size > 0)
	{
		while (i < stack->size)
		{
			if (!value || (stack->items[i] < value && stack->items[i] > item))
				value = stack->items[i];
			i++;
		}
	}
	return (value);
}
