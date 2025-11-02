/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:14:08 by ntome             #+#    #+#             */
/*   Updated: 2025/11/02 21:25:12 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"
#include <stdlib.h>

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

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*stack_items;
	int		size;

	if (ac == 1)
		exit(EXIT_FAILURE);
	size = ft_count_total_args(ac - 1, av);
	stack_items = ft_parse_args(ac, av, size);
	if (ft_check_dup(stack_items, size))
		ft_error_exit();
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
	{
		ft_free_stacks(stack_a, stack_b);
		exit(EXIT_FAILURE);
	}
	ft_init_stack(stack_a, stack_b, stack_items, size);
	ft_sort(stack_a, stack_b);
	ft_free_stacks(stack_a, stack_b);
}
