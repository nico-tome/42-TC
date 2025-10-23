/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:41:38 by ntome             #+#    #+#             */
/*   Updated: 2025/10/22 21:46:30 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

typedef struct s_buffer
{
	char	buffer[BUFFER_SIZE + 1];
	struct s_buffer *next;
}	t_buffer;

char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, const char *src, size_t size);
char	*ft_strchr(char *str, char c);
int		ft_strlen(const char *str);

#endif
