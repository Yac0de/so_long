/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:31:34 by ymeziane          #+#    #+#             */
/*   Updated: 2025/01/31 17:19:45 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//counts the lines in the file
static int	count_lines(const char *file_path)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 0)
			count++;
		free(line);
		line = get_next_line(fd);
	}
	if (count == 0)
		return (-1);
	close(fd);
	return (count);
}

//Returns a line from the file descriptor without the '\n'
static char	*read_and_process_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	return (line);
}

//Fill the map by reading the file descriptor line by line
static char	**fill_map(int fd, int line_count)
{
	char	**map;
	int		i;
	char	*line;

	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	i = 0;
	line = read_and_process_line(fd);
	while (line)
	{
		map[i++] = line;
		line = read_and_process_line(fd);
	}
	map[i] = NULL;
	if (i != line_count)
	{
		while (--i >= 0)
			free(map[i]);
		free(map);
		return (NULL);
	}
	return (map);
}

//reads the map and returns it
char	**read_map(const char *file_path)
{
	int		fd;
	int		line_count;
	char	**map;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line_count = count_lines(file_path);
	if (line_count < 0)
		return (close(fd), NULL);
	map = fill_map(fd, line_count);
	close(fd);
	if (!map)
		return (NULL);
	return (map);
}
