/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:48:16 by ntome             #+#    #+#             */
/*   Updated: 2025/10/21 19:09:17 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*tmp_dest;
	const char	*tmp_src;

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
