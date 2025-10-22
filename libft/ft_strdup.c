/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:55:33 by ntome             #+#    #+#             */
/*   Updated: 2025/10/22 02:35:14 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicated_str;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (!s)
		return (NULL);
	duplicated_str = malloc(sizeof(char) * (str_len + 1));
	if (!duplicated_str)
		return (NULL);
	ft_memcpy(duplicated_str, s, str_len);
	duplicated_str[str_len] = '\0';
	return (duplicated_str);
}
