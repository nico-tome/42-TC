/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:32:10 by ntome             #+#    #+#             */
/*   Updated: 2025/11/01 23:01:51 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_sort_2(t_stack *stack)
{
	if (!ft_is_sorted(stack))
		ft_sa(stack);
}

void	ft_sort_3(t_stack *stack)
{
	int	max_idx;

	if (stack->size == 2)
	{
		ft_sort_2(stack);
		return ;
	}
	max_idx = ft_get_index(stack, ft_max_in_stack(stack));
	if (max_idx == 0)
		ft_ra(stack);
	else if (max_idx == 1)
		ft_rra(stack);
	if (!ft_is_sorted(stack))
		ft_sa(stack);
}
