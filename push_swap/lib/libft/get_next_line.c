/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:28:48 by ntome             #+#    #+#             */
/*   Updated: 2025/11/03 15:40:14 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicated_str;
	size_t	str_len;
	int		i;

	str_len = ft_strlen(s);
	if (!s)
		return (NULL);
	duplicated_str = malloc(sizeof(char) * (str_len + 1));
	if (!duplicated_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		duplicated_str[i] = s[i];
		i++;
	}
	duplicated_str[str_len] = '\0';
	return (duplicated_str);
}

char	*ft_clean(char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	str = ft_substr(s, i + 1, ft_strlen(s));
	free(s);
	return (str);
}

char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_substr(str, 0, i + 1);
	return (line);
}

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		flag;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	flag = 1;
	while (flag > 0)
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag <= 0)
			break ;
		buffer[flag] = '\0';
		flag = !ft_strchr(buffer, '\n');
		if (str)
			str = ft_strjoin_free(str, buffer, 1);
		else
			str = ft_strdup(buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*sub_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (str && !*str)
	{
		free(str);
		str = NULL;
	}
	if (str)
	{
		sub_str = ft_get_line(str);
		str = ft_clean(str);
	}
	else
		sub_str = str;
	return (sub_str);
}
