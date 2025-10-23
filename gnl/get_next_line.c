/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:28:48 by ntome             #+#    #+#             */
/*   Updated: 2025/10/22 22:53:28 by ntome            ###   ########.fr       */
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
	ft_strcpy(new_string, s1, s1_len);
	ft_strcpy(new_string + s1_len, s2, ft_strlen(s2));
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

	str = malloc(1);
	if (!str)
		return (NULL);
	*str = 0;
	while (buf != head)
	{
		tmp_str = str;
		str = ft_strjoin(str, buf->buffer);
		free(tmp_str);
		buf = buf->next;
	}
	t = ft_strchr(buf->buffer, '\n') - buf->buffer + 1;
	tmp_str = str;
	char	*caca = ft_substr(buf->buffer, 0, t);
	str = ft_strjoin(str, caca);
	free(caca);
	free(tmp_str);
	*n = BUFFER_SIZE - t;
	return (str);
}

char	*get_next_line(int fd)
{
	static t_buffer	buf[1024] = {0};
	t_buffer		*head;
	int				flag;
	int				n;
	char			*str;

	head = &buf[fd];
	if (!ft_strchr(head->buffer, '\n') && *head->buffer)
	{
		head->next = malloc(sizeof(t_buffer));
		head = head->next;
		head->next = NULL;
		*head->buffer = 0;
	}
	while (1)
	{	
		flag = ft_strlen(head->buffer);
		if (!ft_strchr(head->buffer, '\n'))
		{
			flag = read(fd, head->buffer, BUFFER_SIZE);
			if (flag <= 0)
				return (NULL);
		}
		head->buffer[flag] = 0;
		if (ft_strchr(head->buffer, '\n'))
		{
			str = ft_get_line_from_buffer(&buf[fd], head, &n);
			ft_strcpy(buf[fd].buffer, head->buffer + BUFFER_SIZE - n, n);

			head = buf[fd].next;
			t_buffer *tmp = head;
			t_buffer *prev;

			while (tmp)
			{
				prev = tmp;
				tmp = tmp->next;
				free(prev);
			}

			break;
		}
		else
		{
			head->next = malloc(sizeof(t_buffer));
			head = head->next;
			head->next = NULL;
			*head->buffer = 0;
		}
	}
	return (str);
}

#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_RDONLY);

	char	*line;

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
}
