/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:33:45 by ntome             #+#    #+#             */
/*   Updated: 2025/10/17 00:41:05 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_list(char const *letters, char const letter)
{
	size_t	i;

	i = 0;
	while (letters[i])
	{
		if (letters[i] == letter)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	begin;

	begin = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1) - 1;
	while (ft_is_in_list(set, s1[begin]))
		begin++;
	while (ft_is_in_list(set, s1[end]))
		end--;
	return (ft_substr(s1, begin, end - begin + 1));
}
