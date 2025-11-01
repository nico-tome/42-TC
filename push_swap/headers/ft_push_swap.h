/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:22:56 by ntome             #+#    #+#             */
/*   Updated: 2025/11/01 23:03:41 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../lib/libft/libft.h"

typedef struct s_stack
{
	int	*items;
	int	size;
}			t_stack;

int		ft_check(char **args);
int		ft_count_args(int ac, char **args);
int		*ft_parse_multiple_args(int size, char **args);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_sa(t_stack *stack_a);
void	ft_sb(t_stack *stack_b);
void	ft_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_ra(t_stack *stack_a);
void	ft_rb(t_stack *stack_b);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);
void	ft_rra(t_stack *stack_a);
void	ft_rrb(t_stack *stack_b);
void	ft_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_pb(t_stack *stack_a, t_stack *stack_b);
void	ft_sort(t_stack *stack_a, t_stack *stack_b);
int		ft_is_sorted(t_stack *stack);
int		ft_is_reverse_sorted(t_stack *stack);
int		ft_min_in_stack(t_stack *stack);
int		ft_max_in_stack(t_stack *stack);
int		ft_get_index(t_stack *stack, int item);
int		ft_get_next_value(t_stack *stack, int item);
int		ft_get_prev_value(t_stack *stack, int item);
int		ft_find_best_move(t_stack *stack_a, t_stack *stack_b);
int		ft_check_combined(t_stack *s_a, t_stack *s_b, int idx_a, int idx_b);
void	ft_do_move(t_stack *stack_a, t_stack *stack_b, int *idx_a, int *idx_b);
int		ft_abs(int i);
void	ft_push_in_stack_a(t_stack *stack_a, t_stack *stack_b);
void	ft_sort_3(t_stack *stack);
void	ft_sort(t_stack *stack_a, t_stack *stack_b);

#endif
