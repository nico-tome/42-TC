/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:41:38 by ntome             #+#    #+#             */
/*   Updated: 2025/10/22 20:26:56 by ntome            ###   ########.fr       */
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
void	ft_strcpy(char *dest, char *src, size_t size);
int		ft_strchr(char *str, char c);
int		ft_strlen(const char *str);

#endif
