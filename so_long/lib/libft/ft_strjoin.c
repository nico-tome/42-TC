/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:23:09 by ntome             #+#    #+#             */
/*   Updated: 2025/11/03 15:39:30 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	s1_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	new_string = malloc(sizeof(char) * (s1_len + ft_strlen(s2) + 1));
	if (!new_string)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		new_string[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		new_string[s1_len + i] = s2[i];
		i++;
	}
	new_string[s1_len + i] = '\0';
	return (new_string);
}
