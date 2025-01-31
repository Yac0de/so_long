/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:12:51 by ymeziane          #+#    #+#             */
/*   Updated: 2023/11/27 21:32:32 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	load_single_texture(t_game *game, mlx_image_t **image,
		const char *file_path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(file_path);
	if (texture)
	{
		*image = mlx_texture_to_image(game->mlx, texture);
		mlx_delete_texture(texture);
	}
}

static void	load_rabbit_and_hunter_textures(t_game *game)
{
	load_single_texture(game, &game->rabbit_img[0], "textures/rabbitR0.png");
	load_single_texture(game, &game->rabbit_img[1], "textures/rabbitL0.png");
	load_single_texture(game, &game->rabbit_img[2], "textures/rabbitD0.png");
	load_single_texture(game, &game->rabbit_img[3], "textures/rabbitU0.png");
	load_single_texture(game, &game->hunter_img[0], "textures/hunter0.png");
	load_single_texture(game, &game->hunter_img[1], "textures/hunter1.png");
	load_single_texture(game, &game->hunter_img[2], "textures/hunter2.png");
	load_single_texture(game, &game->hunter_img[3], "textures/hunter3.png");
}

static void	load_jump_textures(t_game *game)
{
	load_single_texture(game, &game->rabbit_r_jump[0], "textures/rabbitR1.png");
	load_single_texture(game, &game->rabbit_r_jump[1], "textures/rabbitR2.png");
	load_single_texture(game, &game->rabbit_r_jump[2], "textures/rabbitR3.png");
	load_single_texture(game, &game->rabbit_r_jump[3], "textures/rabbitR0.png");
	load_single_texture(game, &game->rabbit_l_jump[0], "textures/rabbitL1.png");
	load_single_texture(game, &game->rabbit_l_jump[1], "textures/rabbitL2.png");
	load_single_texture(game, &game->rabbit_l_jump[2], "textures/rabbitL3.png");
	load_single_texture(game, &game->rabbit_l_jump[3], "textures/rabbitL0.png");
	load_single_texture(game, &game->rabbit_u_jump[0], "textures/rabbitU1.png");
	load_single_texture(game, &game->rabbit_u_jump[1], "textures/rabbitU2.png");
	load_single_texture(game, &game->rabbit_u_jump[2], "textures/rabbitU3.png");
	load_single_texture(game, &game->rabbit_u_jump[3], "textures/rabbitU0.png");
	load_single_texture(game, &game->rabbit_d_jump[0], "textures/rabbitD1.png");
	load_single_texture(game, &game->rabbit_d_jump[1], "textures/rabbitD2.png");
	load_single_texture(game, &game->rabbit_d_jump[2], "textures/rabbitD3.png");
	load_single_texture(game, &game->rabbit_d_jump[3], "textures/rabbitD0.png");
}

static void	load_environment_textures(t_game *game)
{
	load_single_texture(game, &game->tree_img, "textures/tree.png");
	load_single_texture(game, &game->tree2_img, "textures/tree2.png");
	load_single_texture(game, &game->exit_img, "textures/exit_hole.png");
	load_single_texture(game, &game->carrot_img, "textures/item_carrot.png");
	load_single_texture(game, &game->grass_img, "textures/grass.png");
}

void	load_textures(t_game *game)
{
	load_rabbit_and_hunter_textures(game);
	load_environment_textures(game);
	load_jump_textures(game);
}
