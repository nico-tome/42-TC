/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:14:08 by ntome             #+#    #+#             */
/*   Updated: 2025/11/03 21:32:46 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

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
