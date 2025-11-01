/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:12:43 by ntome             #+#    #+#             */
/*   Updated: 2025/11/01 22:02:51 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_push(t_stack *stack_src, t_stack *stack_dest)
{
	int	i;
	int	pushed_value;

	if (stack_src->size < 1)
		return ;
	pushed_value = stack_src->items[0];
	i = 0;
	while (i < stack_src->size)
	{
		stack_src->items[i] = stack_src->items[i + 1];
		i++;
	}
	stack_src->size--;
	stack_dest->size++;
	i = stack_dest->size;
	while (i > 0)
	{
		stack_dest->items[i] = stack_dest->items[i - 1];
		i--;
	}
	stack_dest->items[0] = pushed_value;
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
