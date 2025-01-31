/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:25:12 by ymeziane          #+#    #+#             */
/*   Updated: 2025/01/31 17:08:54 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Clear the binary mask
static void	clean_map(char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
		{
			map[i][j] &= ~0b10000000;
			j++;
		}
		i++;
	}
}

// Recursive function that checks whether a path
// can be reached from coordinates 'i' 'j' to the target.
// Places a binary mask on each traversed square
static int	check_path(char **map, int i, int j, char target)
{
	if (map[i][j] == target)
		return (1);
	map[i][j] |= 0b10000000;
	if ((!(map[i][j + 1] & 0b10000000) && map[i][j + 1] != '1' && map[i][j
			+ 1] != 'H' &&
			(target == 'E' || map[i][j + 1] != 'E') && check_path(map, i, j + 1,
					target)) ||
		(!(map[i][j - 1] & 0b10000000) && map[i][j - 1] != '1' && map[i][j
				- 1] != 'H' &&
			(target == 'E' || map[i][j - 1] != 'E') && check_path(map, i, j - 1,
					target)) ||
		(!(map[i + 1][j] & 0b10000000) && map[i + 1][j] != '1' && map[i
				+ 1][j] != 'H' &&
			(target == 'E' || map[i + 1][j] != 'E') && check_path(map, i + 1, j,
					target)) ||
		(!(map[i - 1][j] & 0b10000000) && map[i - 1][j] != '1' && map[i
				- 1][j] != 'H' &&
			(target == 'E' || map[i - 1][j] != 'E') && check_path(map, i - 1, j,
					target)))
		return (1);
	else
		return (0);
}

// Check that the character can reach the exit
// and check that each of the collectables is reachable,
// then clean the mask map.
static int	check_path_and_clean_map(char **map, int height, int i, int j)
{
	if (map[i][j] == 'P')
	{
		if (!check_path(map, i, j, 'E'))
			return (ft_printf("Error\nInvalid map, no valid path\n"), 0);
	}
	else if (map[i][j] == 'C')
	{
		if (!check_path(map, i, j, 'P'))
			return (ft_printf("Error\nInvalid map, no valid path\n"), 0);
	}
	clean_map(map, height);
	return (1);
}

// Checks that the map is valid
int	valid_map(char **map, int width, int height)
{
	int	x;
	int	y;

	if (!check_lines_same_length(map, width) || !check_walls(map, width, height)
		|| !check_chars(map))
		return (0);
	x = 0;
	y = 0;
	while (x < height)
	{
		while (y < width)
		{
			if (!check_path_and_clean_map(map, height, x, y))
				return (0);
			y++;
		}
		y = 0;
		x++;
	}
	return (1);
}
