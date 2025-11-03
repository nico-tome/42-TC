/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:36:24 by ntome             #+#    #+#             */
/*   Updated: 2025/11/03 22:24:17 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_rotate(t_stack *stack)
{
	int	tmp_first;
	int	i;

	if (stack->size < 2)
		return ;
	i = 0;
	tmp_first = stack->items[0];
	while (i < stack->size - 1)
	{
		stack->items[i] = stack->items[i + 1];
		i++;
	}
	stack->items[i] = tmp_first;
}

void	ft_ra(t_stack *stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack *stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}
