/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:22:51 by ymeziane          #+#    #+#             */
/*   Updated: 2025/01/31 16:41:23 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Redraws a single map cell to the specified position
void	draw_tile(t_game *game, int x, int y)
{
	if (game->is_jumping)
	{
		disables_rabbit_textures(game);
		if (game->rabbit_orientation == 0)
			moove_and_enabled_img_jump(game->rabbit_r_jump, game, x, y);
		else if (game->rabbit_orientation == 1)
			moove_and_enabled_img_jump(game->rabbit_l_jump, game, x, y);
		else if (game->rabbit_orientation == 2)
			moove_and_enabled_img_jump(game->rabbit_d_jump, game, x, y);
		else
			moove_and_enabled_img_jump(game->rabbit_u_jump, game, x, y);
	}
	if (game->map[x][y] == 'C')
		game->grass_img->instances[x * game->map_width + y].z
			= game->rabbit_img[game->rabbit_orientation]->instances->z - 1;
}

// Displays the number of steps
void	display_steps(t_game *game)
{
	char	*steps_str;
	char	*full_str;
	int		full_str_len;

	steps_str = ft_itoa(game->count_steps);
	if (steps_str)
	{
		full_str_len = ft_strlen("Steps = ") + ft_strlen(steps_str) + 1;
		full_str = (char *)malloc(sizeof(char) * full_str_len);
		if (full_str)
		{
			ft_strlcpy(full_str, "Steps = ", full_str_len);
			ft_strlcat(full_str, steps_str, full_str_len);
			if (game->step_img)
			{
				mlx_delete_image(game->mlx, game->step_img);
				game->step_img = NULL;
			}
			game->step_img = mlx_put_string(game->mlx, full_str, 10, 5);
			free(full_str);
		}
		free(steps_str);
	}
	game->count_steps++;
}

// Draw the initial map
void	draw_map(t_game *game)
{
	int			x;
	int			y;
	mlx_image_t	*img;

	display_steps(game);
	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			game->count_square++;
			mlx_image_to_window(game->mlx, game->grass_img, y * TILE_SIZE, (x
					+ 1) * TILE_SIZE);
			game->grass_img->instances[game->grass_img->count - 1].z = 0;
			img = choose_image(game, x, y);
			if (img != NULL)
				mlx_image_to_window(game->mlx, img, y * TILE_SIZE, (x + 1)
					* TILE_SIZE);
			if (img == game->carrot_img)
				game->carrot_img->instances[game->carrot_img->count - 1].z = 1;
			y++;
		}
		x++;
	}
}
