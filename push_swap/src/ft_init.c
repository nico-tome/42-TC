/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:32:16 by ntome             #+#    #+#             */
/*   Updated: 2025/11/03 21:32:32 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->items)
		free(stack_a->items);
	if (stack_b->items)
		free(stack_b->items);
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
}

void	ft_init_stack(t_stack *stack_a, t_stack *stack_b, int *items, int size)
{
	stack_a->size = size;
	stack_a->items = malloc(size * sizeof(int));
	stack_b->size = 0;
	stack_b->items = malloc(size * sizeof(int));
	if (!stack_a->items || !stack_b->items)
		return ;
	ft_memcpy(stack_a->items, items, size * sizeof(int));
	free(items);
}
