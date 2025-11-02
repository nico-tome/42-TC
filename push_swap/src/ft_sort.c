/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:59:33 by ntome             #+#    #+#             */
/*   Updated: 2025/11/02 18:23:37 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_move_index_to_top(int idx, t_stack *stack_a, t_stack *stack_b)
{
	int	next_item;
	int	next_index;

	if (stack_a->items[idx] < ft_min_in_stack(stack_b))
		next_item = ft_max_in_stack(stack_b);
	else
		next_item = ft_get_next_value(stack_b, stack_a->items[idx]);
	next_index = ft_get_index(stack_b, next_item);
	while (ft_check_combined(stack_a, stack_b, idx, next_index) > 0)
	{
		if (ft_check_combined(stack_a, stack_b, idx, next_index) == 1)
		{
			ft_rr(stack_a, stack_b);
			idx--;
			next_index--;
		}
		else if (ft_check_combined(stack_a, stack_b, idx, next_index) == 2)
		{
			ft_rrr(stack_a, stack_b);
			idx = (idx + 1) % stack_a->size;
			next_index = (next_index + 1) % stack_b->size;
		}
	}
	while (next_index != 0 || idx != 0)
		ft_do_move(stack_a, stack_b, &idx, &next_index);
}

void	ft_sort_in_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	int	best_move;

	while (stack_a->size > 3)
	{
		best_move = ft_find_best_move(stack_a, stack_b);
		ft_move_index_to_top(best_move, stack_a, stack_b);
		ft_pb(stack_a, stack_b);
	}
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 3)
	{
		ft_pb(stack_a, stack_b);
		ft_pb(stack_a, stack_b);
		ft_sort_in_stack_b(stack_a, stack_b);
	}
	ft_sort_3(stack_a);
	if (stack_b->size > 0)
		ft_push_in_stack_a(stack_a, stack_b);
}
