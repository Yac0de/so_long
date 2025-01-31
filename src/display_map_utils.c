/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:44:00 by ymeziane          #+#    #+#             */
/*   Updated: 2023/11/27 22:45:06 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Returns the image selected
// according to the character found at the given position
mlx_image_t	*choose_image(t_game *game, int x, int y)
{
	if (game->map[x][y] == '1')
	{
		if (game->count_square % 2)
			return (game->tree_img);
		return (game->tree2_img);
	}
	else if (game->map[x][y] == 'P')
	{
		game->rabbit_img[2]->instances->x = y * TILE_SIZE;
		game->rabbit_img[2]->instances->y = (x + 1) * TILE_SIZE;
	}
	else if (game->map[x][y] == 'E')
		return (game->exit_img);
	else if (game->map[x][y] == 'C')
		return (game->carrot_img);
	return (NULL);
}

// Disables all rabbit textures
void	disables_rabbit_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->rabbit_r_jump[i]->instances->enabled = 0;
		game->rabbit_l_jump[i]->instances->enabled = 0;
		game->rabbit_u_jump[i]->instances->enabled = 0;
		game->rabbit_d_jump[i]->instances->enabled = 0;
		game->rabbit_img[i]->instances->enabled = 0;
		i++;
	}
}

void	moove_and_enabled_img_jump(mlx_image_t **img,
	t_game *game, int x, int y)
{
	img[game->jump_frame]->instances->x = y * TILE_SIZE;
	img[game->jump_frame]->instances->y = (x + 1)
		* TILE_SIZE;
	img[game->jump_frame]->instances->enabled = 1;
}
