/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:47:46 by ntome             #+#    #+#             */
/*   Updated: 2025/11/01 23:02:07 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"
#include <stdio.h>

void	ft_print_tabs(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	i2;
	int	a_wait;
	int	b_wait;

	if (stack_a->size > stack_b->size)
	{
		a_wait = 0;
		b_wait = stack_a->size - stack_b->size;
	}
	else if (stack_a->size <= stack_b->size)
	{
		a_wait = stack_b->size - stack_a->size;
		b_wait = 0;
	}
	i = 0;
	i2 = 0;
	printf("\n\nA B\n---\n");
	while (i < stack_a->size && i2 < stack_b->size)
	{
		if (a_wait > 0)
		{
			printf("x %d\n", stack_b->items[i2]);
			a_wait--;
			i2++;
		}
		else if (b_wait > 0)
		{
			printf("%d x\n", stack_a->items[i]);
			b_wait--;
			i++;
		}
		else 
		{
			printf("%d %d\n", stack_a->items[i], stack_b->items[i2]);
			i++;
			i2++;
		}
	}
	printf("---\n%d %d\n", stack_a->size, stack_b->size);
}
