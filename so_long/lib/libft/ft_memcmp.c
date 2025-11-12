/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:35:45 by ntome             #+#    #+#             */
/*   Updated: 2025/10/21 19:08:45 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*tmp_s1;
	const unsigned char	*tmp_s2;

	i = 0;
	tmp_s1 = s1;
	tmp_s2 = s2;
	while (i < n)
	{
		if (*(tmp_s1++) != *(tmp_s2++))
			return (*(tmp_s1 - 1) - *(tmp_s2 - 1));
		i++;
	}
	return (0);
}
