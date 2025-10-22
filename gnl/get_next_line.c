/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:28:48 by ntome             #+#    #+#             */
/*   Updated: 2025/10/22 20:28:32 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	len_sub;

	if (!s)
		return (0);
	len_sub = ft_strlen(s);
	if (len_sub <= start)
		return ("");
	if (len_sub - start < len)
		len = len_sub - start;
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_get_line_from_buffer(t_buffer *buf, t_buffer *head, int *n)
{
	char	*str;
	char	*tmp_str;
	int		t;

	while (buf != head)
	{
		ft_strjoin(str, buf->buffer);
		buf = buf->next;
	}
	t = ft_strchr(buf->buffer, '\n') - buf->buffer;
	ft_strjoin(str, ft_substr(buf->buffer, 0, t));
	*n = BUFFER_SIZE - t;
	return (str);
}

char	*get_next_line(int fd)
{
	static t_buffer	buf;
	t_buffer		*head;
	int				flag;
	int				n;
	char			*str;

	head = &buf;

	while (1)
	{	
		flag = read(fd, head->buffer, BUFFER_SIZE);
		if (flag < 0 || ft_strchr(head->buffer, '\n'))
		{
			str = ft_get_line_from_buffer(&buf, head, &n);
			ft_strcpy(buf.buffer, buf.buffer + BUFFER_SIZE - n, n + 1);
			break;
		}
		else
		{
			head->next = malloc(sizeof(t_buffer));
			head = head->next;
		}
	}
	return (str);
}
