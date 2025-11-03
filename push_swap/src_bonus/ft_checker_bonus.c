/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:23:42 by ntome             #+#    #+#             */
/*   Updated: 2025/11/03 22:29:09 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

int	ft_check_move(char	*str)
{
	int	size;

	size = ft_strlen(str);
	if (size == 3)
	{
		if (!ft_strncmp(str, "ra\n", 3) || !ft_strncmp(str, "rb\n", 3))
			return (1);
		else if (!ft_strncmp(str, "rr\n", 3) || !ft_strncmp(str, "pa\n", 3))
			return (1);
		else if (!ft_strncmp(str, "pb\n", 3) || !ft_strncmp(str, "sa\n", 3))
			return (1);
		else if (!ft_strncmp(str, "sb\n", 3))
			return (1);
	}
	if (size == 4)
	{
		if (!ft_strncmp(str, "rrr\n", 4) || !ft_strncmp(str, "rra\n", 4))
			return (1);
		else if (!ft_strncmp(str, "rrb\n", 4))
			return (1);
	}
	return (0);
}

void	ft_do_instruction(char *instruction, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strlen(instruction) == 4)
	{
		if (instruction[2] == 'a' || instruction[2] == 'r')
			ft_reverse_rotate(stack_a);
		if (instruction[2] == 'b' || instruction[2] == 'r')
			ft_reverse_rotate(stack_b);
	}
	else
	{
		if (instruction[0] == 'r')
		{
			if (instruction[1] == 'a' || instruction[1] == 'r')
				ft_rotate(stack_a);
			if (instruction[1] == 'b' || instruction[1] == 'r')
				ft_rotate(stack_b);
		}
		else if (!ft_strncmp(instruction, "sa\n", 3))
			ft_swap(stack_a);
		else if (!ft_strncmp(instruction, "sb\n", 3))
			ft_swap(stack_b);
		else if (!ft_strncmp(instruction, "pa\n", 3))
			ft_push(stack_b, stack_a);
		else if (!ft_strncmp(instruction, "pb\n", 3))
			ft_push(stack_a, stack_b);
	}
}

void	ft_check(t_stack *stack_a, t_stack *stack_b)
{
	char	*buffer;

	buffer = get_next_line(0);
	while (buffer)
	{
		if (!ft_check_move(buffer))
		{
			free(get_next_line(0));
			free(buffer);
			ft_free_stacks(stack_a, stack_b);
			ft_error_exit();
		}
		ft_do_instruction(buffer, stack_a, stack_b);
		free(buffer);
		buffer = get_next_line(0);
	}
	if (ft_is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	ft_check(stack_a, stack_b);
	ft_free_stacks(stack_a, stack_b);
}
