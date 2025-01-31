/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:13:51 by ymeziane          #+#    #+#             */
/*   Updated: 2025/01/31 17:22:01 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Check that the map is a rectangle and that all its lines are the same size.
int	check_lines_same_length(char **map, int width)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) - (bool)ft_strchr(map[i], '\n') != width)
			return (ft_printf("Error\n"
					"Invalid map, the map is not a rectangle\n"), 0);
		i++;
	}
	return (1);
}

// Check that the map is enclosed by walls '1'
int	check_walls(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (ft_printf("Error\n"
					"Invalid map, the map is not surrounded by walls\n"), 0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (ft_printf("Error\n"
					"Invalid map, the map is not surrounded by walls\n"), 0);
		i++;
	}
	return (1);
}

// Count the number of 'E', 'C', 'P', and other different characters
static void	count_chars(char **map, int *counts)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			counts[0] += (map[i][j] == 'E');
			counts[1] += (map[i][j] == 'C');
			counts[2] += (map[i][j] == 'P');
			counts[3] += (map[i][j] != '1') && (map[i][j] != '0')
				&& (map[i][j] != 'E') && (map[i][j] != 'C')
				&& (map[i][j] != 'P') && (map[i][j] != 'H');
			j++;
		}
		i++;
	}
}

// Check that there are no unknown or missing characters
// or duplicates on the map
int	check_chars(char **map)
{
	int	counts[4];

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	counts[3] = 0;
	count_chars(map, counts);
	if (counts[0] > 1 || counts[2] > 1 || !counts[0] || !counts[1] || !counts[2]
		|| counts[3])
	{
		ft_printf("Error\nInvalid map, ");
		if (counts[3] != 0)
			ft_printf("unknown characters present\n");
		else if (counts[0] > 1 || counts[2] > 1)
			ft_printf("duplicates present\n");
		else
			ft_printf("missing characters\n");
		return (0);
	}
	return (1);
}
