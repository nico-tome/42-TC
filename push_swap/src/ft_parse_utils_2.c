/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:41:24 by ntome             #+#    #+#             */
/*   Updated: 2025/11/02 21:23:06 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"
#include <stdlib.h>

int	ft_check_dup(int *items, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (items[j] == items[i])
			{
				free(items);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
