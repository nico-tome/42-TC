/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:41:38 by ntome             #+#    #+#             */
/*   Updated: 2025/10/24 22:01:19 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dest, const char *src, size_t size);
int		ft_strchr(char *str, char c);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2, int to_free);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
