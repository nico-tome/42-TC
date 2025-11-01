/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combined_move_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:15:47 by ntome             #+#    #+#             */
/*   Updated: 2025/11/01 23:04:05 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

int	ft_check_combined(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b)
{
	if (idx_a == 0 || idx_b == 0)
		return (0);
	if (idx_a < stack_a->size / 2 && idx_b < stack_b->size / 2)
		return (1);
	else if (idx_a > stack_a->size / 2 && idx_b > stack_b->size / 2)
		return (2);
	return (0);
}

void	ft_do_move(t_stack *stack_a, t_stack *stack_b, int *idx_a, int *idx_b)
{
	if (*idx_a <= stack_a->size / 2 && *idx_a != 0)
	{
		ft_ra(stack_a);
		(*idx_a)--;
	}
	else if (*idx_a > stack_a->size / 2 && *idx_a != 0)
	{
		ft_rra(stack_a);
		*idx_a = (*idx_a + 1) % stack_a->size;
	}
	if (*idx_b <= stack_b->size / 2 && *idx_b != 0)
	{
		ft_rb(stack_b);
		*idx_b = *idx_b - 1;
	}
	else if (*idx_b > stack_b->size / 2 && *idx_b != 0)
	{
		ft_rrb(stack_b);
		*idx_b = (*idx_b + 1) % stack_b->size;
	}
}
