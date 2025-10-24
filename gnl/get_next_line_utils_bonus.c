/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:48:08 by ntome             #+#    #+#             */
/*   Updated: 2025/10/24 22:01:51 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2, int to_free)
{
	char	*new_string;
	size_t	s1_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	new_string = malloc(sizeof(char) * (s1_len + ft_strlen(s2) + 1));
	if (!new_string)
		return (NULL);
	ft_strcpy(new_string, s1, s1_len);
	ft_strcpy(new_string + s1_len, s2, ft_strlen(s2));
	if (to_free == 1)
		free(s1);
	return (new_string);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	if (str[i] == c)
		return (1);
	return (0);
}

int	ft_strlen(const char *str)
{
	const char	*tmp;

	tmp = str;
	while (*tmp)
		tmp++;
	return (tmp - str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	len_sub;

	if (!s)
		return (NULL);
	len_sub = ft_strlen(s);
	if (len_sub <= start)
	{
		ptr = malloc(1);
		*ptr = 0;
		return (ptr);
	}
	if (len_sub - start < len)
		len = len_sub - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ft_strcpy(ptr, s + start, len);
	return (ptr);
}

char	*ft_strcpy(char *dest, const char *src, size_t size)
{
	char	*tmp;

	tmp = dest;
	while (*src && size-- > 0)
		*dest++ = *src++;
	*dest = 0;
	return (tmp);
}
