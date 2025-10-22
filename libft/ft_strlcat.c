/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:01:07 by ntome             #+#    #+#             */
/*   Updated: 2025/10/22 19:03:05 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;

	if (!dest && src && size == 0)
		return (ft_strlen(src));
	dest_len = ft_strlen(dest);
	if ((!dest || !src))
		return (0);
	if (!size)
		return (ft_strlen(src));
	if (size <= dest_len)
		return (size + ft_strlen(src));
	size -= (dest_len + 1);
	while (*src && size-- > 0)
		dest[dest_len++] = *(src++);
	dest[dest_len] = '\0';
	return (ft_strlen(src) + dest_len);
}
