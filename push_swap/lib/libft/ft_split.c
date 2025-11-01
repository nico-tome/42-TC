/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:17:43 by ntome             #+#    #+#             */
/*   Updated: 2025/10/21 21:30:07 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_word_size(char const *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start + i] != c && s[start + i])
	{
		i++;
	}
	return (i);
}

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**strs;
	int		size;
	int		j;

	i = 0;
	j = -1;
	strs = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (++j < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		size = ft_get_word_size(s, c, i);
		strs[j] = ft_substr(s, i, size);
		if (!strs[j])
		{
			ft_free(strs, j);
			return (NULL);
		}
		i += size;
	}
	strs[j] = NULL;
	return (strs);
}
