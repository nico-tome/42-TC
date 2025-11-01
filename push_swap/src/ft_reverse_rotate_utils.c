/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:45:11 by ntome             #+#    #+#             */
/*   Updated: 2025/10/30 20:48:23 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_reverse_rotate(t_stack *stack)
{
	int	tmp_last;
	int	i;

	if (stack->size < 2)
		return ;
	i = stack->size - 1;
	tmp_last = stack->items[i];
	while (i > 0)
	{
		stack->items[i] = stack->items[i - 1];
		i--;
	}
	stack->items[i] = tmp_last;
}

void	ft_rra(t_stack *stack_a)
{
	ft_reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *stack_b)
{
	ft_reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
