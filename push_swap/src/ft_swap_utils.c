/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:18:04 by ntome             #+#    #+#             */
/*   Updated: 2025/10/30 20:35:43 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->items[0];
	stack->items[0] = stack->items[1];
	stack->items[1] = tmp;
}

void	ft_sa(t_stack *stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack *stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
