/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:24:42 by ymeziane          #+#    #+#             */
/*   Updated: 2023/11/27 21:55:04 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Returns map height
int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

// Finds the character on the map and returns its coordinates
t_point	find_character(char **map)
{
	t_point	point;
	int		x;
	int		y;

	x = 0;
	point.x = 0;
	point.y = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				point.x = x;
				point.y = y;
				return (point);
			}
			y++;
		}
		x++;
	}
	return (point);
}

// Finds the exit on the map and returns its coordinates
t_point	find_exit(char **map)
{
	t_point	point;
	int		x;
	int		y;

	x = 0;
	point.x = 0;
	point.y = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'E')
			{
				point.x = x;
				point.y = y;
				return (point);
			}
			y++;
		}
		x++;
	}
	return (point);
}

// Counts the number of characters found in the map
int	count_char(char **map, char c)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == c)
				count++;
			y++;
		}
		y = 0;
		x++;
	}
	return (count);
}

// Checks if the player is going to win the game
int	its_won(t_game *game, int new_x, int new_y)
{
	if (game->total_collectables == game->collectables && new_x == game->exit.x
		&& new_y == game->exit.y)
		return (1);
	return (0);
}
