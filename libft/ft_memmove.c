/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:48:16 by ntome             #+#    #+#             */
/*   Updated: 2025/10/15 14:54:56 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*tmp_dest;
	const char	*tmp_src;

	if (!dest && !src)
		return (0);
	tmp_dest = (char *)dest;
	tmp_src = (char *)src;
	if (tmp_dest < tmp_src)
	{
		while (n--)
		{
			*tmp_dest++ = *tmp_src++;
		}
	}
	else 
	{
		tmp_dest += n - 1;
		tmp_src += n - 1;
		while (n--)
		{
			*tmp_dest-- = *tmp_src--;
		}
	}
	return (dest);
}
