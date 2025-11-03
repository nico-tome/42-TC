/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:41:07 by ntome             #+#    #+#             */
/*   Updated: 2025/11/03 15:42:13 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int to_free)
{
	char	*new_string;
	size_t	s1_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	new_string = malloc(sizeof(char) * (s1_len + ft_strlen(s2) + 1));
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, s1, s1_len);
	ft_strlcpy(new_string + s1_len, s2, ft_strlen(s2));
	if (to_free == 1)
		free(s1);
	return (new_string);
}
