/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:13:18 by ntome             #+#    #+#             */
/*   Updated: 2025/11/01 19:59:19 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	int	i;

	if (stack->size == 0)
		return (1);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->items[i] > stack->items[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_reverse_sorted(t_stack *stack)
{
	int	i;

	if (stack->size == 0)
		return (1);
	i = 0;
	while (i < stack->size)
	{
		if (stack->items[i] < stack->items[i + 1])
			return (0);
		i++;
	}
	return (1);
}
