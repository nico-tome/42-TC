/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_parser_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:00:54 by ntome             #+#    #+#             */
/*   Updated: 2025/11/20 14:13:08 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/ft_so_long_bonus.h"
#include "../../includes_bonus/ft_error_bonus.h"

int	ft_check_file_type(char *file_path)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(file_path);
	while (file_path[i] && file_path[i] != '.')
		i++;
	if (!ft_strncmp(file_path + i, ".ber", 4) && i + 4 == size)
		return (TRUE);
	return (FALSE);
}

int	ft_get_map_size(char *file_path)
{
	int		fd;
	int		size;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		ft_exit_error(FILE_OPEN_ERROR_CODE);
	size = 0;
	line = get_next_line(fd);
	while (line)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (size);
}

t_map	ft_read_map(char *file_path, int map_size)
{
	t_map	map;
	char	*buffer;
	int		line_idx;
	int		fd;

	fd = open(file_path, O_RDONLY);
	map.map = malloc(sizeof(char *) * (map_size + 1));
	if (!map.map)
		ft_exit_error(MALLOC_ERROR_CODE);
	line_idx = 0;
	buffer = get_next_line(fd);
	while (buffer)
	{
		if (buffer[ft_strlen(buffer) - 1] == '\n')
			map.map[line_idx] = ft_substr(buffer, 0, ft_strlen(buffer) - 1);
		else
			map.map[line_idx] = ft_strdup(buffer);
		line_idx++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	map.map[line_idx] = NULL;
	close(fd);
	map.size = map_size;
	return (map);
}

t_map	ft_get_map(char *file_path)
{
	t_map	map;
	int		line_count;

	if (ft_check_file_type(file_path) == FALSE)
		ft_exit_error(FILE_TYPE_ERROR_CODE);
	line_count = ft_get_map_size(file_path);
	if (line_count == 0)
		ft_exit_error(FILE_EMPTY_ERROR_CODE);
	map = ft_read_map(file_path, line_count);
	return (map);
}
