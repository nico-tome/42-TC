/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:23:03 by ntome             #+#    #+#             */
/*   Updated: 2025/10/21 19:07:45 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr_node;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr_node = *lst;
	while (curr_node->next)
		curr_node = curr_node->next;
	curr_node->next = new;
}
