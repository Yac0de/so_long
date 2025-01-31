/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frames.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:23:27 by ymeziane          #+#    #+#             */
/*   Updated: 2023/11/27 22:26:24 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Draws all the frames of the jump animation
// and places them on the deepest layer to make them invisible
void	init_frames_jump(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_image_to_window(game->mlx, game->rabbit_r_jump[i], 0, 0);
		game->rabbit_r_jump[i]->instances->z = 3;
		game->rabbit_r_jump[i]->instances->enabled = 0;
		mlx_image_to_window(game->mlx, game->rabbit_l_jump[i], 0, 0);
		game->rabbit_l_jump[i]->instances->z = 3;
		game->rabbit_l_jump[i]->instances->enabled = 0;
		mlx_image_to_window(game->mlx, game->rabbit_u_jump[i], 0, 0);
		game->rabbit_u_jump[i]->instances->z = 3;
		game->rabbit_u_jump[i]->instances->enabled = 0;
		mlx_image_to_window(game->mlx, game->rabbit_d_jump[i], 0, 0);
		game->rabbit_d_jump[i]->instances->z = 3;
		game->rabbit_d_jump[i]->instances->enabled = 0;
		i++;
	}
}

// Draws all the frames of the direction rabbit
// and places them on the deepest layer to make them invisible
void	init_frames_rabit(t_game *game)
{
	mlx_image_to_window(game->mlx, game->rabbit_img[0], 0, 0);
	game->rabbit_img[0]->instances->z = 3;
	game->rabbit_img[0]->enabled = 0;
	mlx_image_to_window(game->mlx, game->rabbit_img[1], 0, 0);
	game->rabbit_img[1]->instances->z = 3;
	game->rabbit_img[1]->enabled = 0;
	mlx_image_to_window(game->mlx, game->rabbit_img[2], 0, 0);
	game->rabbit_img[2]->instances->z = 3;
	game->rabbit_img[2]->enabled = 1;
	mlx_image_to_window(game->mlx, game->rabbit_img[3], 0, 0);
	game->rabbit_img[3]->instances->z = 3;
	game->rabbit_img[3]->enabled = 0;
}

// Draws all the hunter animation frames
// at each of their locations on the map
void	init_frames_hunter(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_height)
	{
		y = 0;
		while (y < game->map_width)
		{
			if (game->map[x][y] == 'H')
			{
				mlx_image_to_window(game->mlx, game->hunter_img[0], y
					* TILE_SIZE, (x + 1) * TILE_SIZE);
				mlx_image_to_window(game->mlx, game->hunter_img[1], y
					* TILE_SIZE, (x + 1) * TILE_SIZE);
				mlx_image_to_window(game->mlx, game->hunter_img[2], y
					* TILE_SIZE, (x + 1) * TILE_SIZE);
				mlx_image_to_window(game->mlx, game->hunter_img[3], y
					* TILE_SIZE, (x + 1) * TILE_SIZE);
			}
			y++;
		}
		x++;
	}
}
