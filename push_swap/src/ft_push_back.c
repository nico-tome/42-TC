/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:58:01 by ntome             #+#    #+#             */
/*   Updated: 2025/11/01 23:53:38 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_setup_stack_a(t_stack *stack_a, int item)
{
	int	prev_idx;

	if (item > ft_max_in_stack(stack_a))
		prev_idx = ft_get_index(stack_a, ft_min_in_stack(stack_a));
	else
		prev_idx = ft_get_index(stack_a, ft_get_prev_value(stack_a, item));
	while (prev_idx != 0)
	{
		if (prev_idx < stack_a->size / 2)
		{
			ft_ra(stack_a);
			prev_idx--;
		}
		else
		{
			ft_rra(stack_a);
			prev_idx = (prev_idx + 1) % stack_a->size;
		}
	}
}

void	ft_final_sort(t_stack *stack)
{
	int	min_idx;
	int	min;
	int	mid;

	min = ft_min_in_stack(stack);
	mid = stack->size / 2;
	min_idx = ft_get_index(stack, min);
	while (min_idx != 0)
	{
		if (min_idx < mid)
			ft_ra(stack);
		else
			ft_rra(stack);
		min_idx = ft_get_index(stack, min);
	}
}

void	ft_push_in_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size > 0)
	{
		ft_setup_stack_a(stack_a, stack_b->items[0]);
		ft_pa(stack_a, stack_b);
	}
	if (!ft_is_sorted(stack_a))
		ft_final_sort(stack_a);
}
