/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:14:08 by ntome             #+#    #+#             */
/*   Updated: 2025/11/01 19:22:33 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"
#include <stdlib.h>

void	ft_free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->items);
	free(stack_b->items);
	free(stack_a);
	free(stack_b);
}

void	ft_init_stack(t_stack *stack_a, t_stack *stack_b, int ac, char **args)
{
	int	size;

	size = ft_count_args(ac, args);
	stack_a->size = size;
	stack_a->items = malloc(size * sizeof(int));
	stack_b->size = 0;
	stack_b->items = malloc(size * sizeof(int));
	if (!stack_a->items || !stack_b->items)
		return ;
	if (size == ac - 1)
		stack_a->items = ft_parse_multiple_args(size, args);
	else
		stack_a->items = ft_parse_multiple_args(size, ft_split(args[1], ' '));
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		exit(EXIT_FAILURE);
	if (ac == 2 && !ft_check(ft_split(av[1], ' ')))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (ac > 2 && !ft_check(av + 1))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		exit(EXIT_FAILURE);
	ft_init_stack(stack_a, stack_b, ac, av);
	ft_sort(stack_a, stack_b);
	ft_free_stacks(stack_a, stack_b);
}
