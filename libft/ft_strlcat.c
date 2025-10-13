/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:01:07 by ntome             #+#    #+#             */
/*   Updated: 2025/10/13 15:07:52 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	t;

	i = 0;
	t = 0;
	while (dest[i])
		i++;
	while (src[t] && t < size)
	{
		dest[i] = src[t];
		i++;
		t++;
	}
	dest[i] = '\0';
	return (i);
}
