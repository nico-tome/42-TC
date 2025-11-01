/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best_move_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:45:02 by ntome             #+#    #+#             */
/*   Updated: 2025/11/01 23:33:19 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

int	ft_move_to_top_count(t_stack *stack, int idx)
{
	if (idx < stack->size / 2)
		return (idx);
	return (stack->size - idx);
}

int	ft_merge_moves(t_stack *stack_a, t_stack *stack_b, int a_idx, int b_idx)
{
	if (a_idx > stack_a->size / 2)
	{
		if (ft_abs((stack_a->size - a_idx) - (stack_b->size - b_idx)))
			return (stack_a->size - a_idx);
		return (ft_abs((stack_a->size - a_idx) - (stack_b->size - b_idx)));
	}
	return (ft_abs(a_idx - b_idx));
}

int	ft_calculate_mv(t_stack *stack_a, t_stack *stack_b, int item, int idx)
{
	int	mv_a;
	int	mv_b;
	int	merged_moves;
	int	next_value;

	if (item < ft_min_in_stack(stack_b))
		mv_b = 0;
	else
	{
		next_value = ft_get_next_value(stack_b, item);
		next_value = ft_get_index(stack_b, next_value);
		mv_b = ft_move_to_top_count(stack_b, next_value);
	}
	mv_a = ft_move_to_top_count(stack_a, idx);
	merged_moves = 0;
	if (ft_check_combined(stack_a, stack_b, idx, next_value) > 0)
		merged_moves = ft_merge_moves(stack_a, stack_b, idx, next_value);
	return (mv_a + mv_b - merged_moves);
}

int	ft_find_best_move(t_stack *stack_a, t_stack *stack_b)
{
	int	best_idx;
	int	best_moves;
	int	moves_count;
	int	i;

	i = 0;
	best_idx = 0;
	best_moves = -1;
	while (i < stack_a->size && best_moves != 0)
	{
		moves_count = ft_calculate_mv(stack_a, stack_b, stack_a->items[i], i);
		if (moves_count < best_moves || best_moves == -1)
		{
			best_moves = moves_count;
			best_idx = i;
		}
		i++;
	}
	return (best_idx);
}
