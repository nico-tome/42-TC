/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:28:48 by ntome             #+#    #+#             */
/*   Updated: 2025/10/24 22:16:17 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
			str = ft_strjoin(str, buffer, 1);
		else
			str = ft_strdup(buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024] = {0};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read(fd, str[fd]);
	if (str[fd] && !*str[fd])
	{
		free(str[fd]);
		str[fd] = NULL;
	}
	if (str[fd])
	{
		line = ft_get_line(str[fd]);
		str[fd] = ft_clean(str[fd]);
	}
	else
		line = str[fd];
	return (line);
}
