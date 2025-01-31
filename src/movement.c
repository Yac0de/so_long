/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:52:17 by ymeziane          #+#    #+#             */
/*   Updated: 2023/11/27 18:05:14 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Updates the rabbit's orientation as it moves
void	update_rabbit_orientation(t_game *game, int new_x, int new_y)
{
	game->rabbit_img[game->rabbit_orientation]->enabled = 0;
	if (new_x > game->player.x)
		game->rabbit_orientation = 2;
	else if (new_x < game->player.x)
		game->rabbit_orientation = 3;
	else if (new_y > game->player.y)
		game->rabbit_orientation = 0;
	else if (new_y < game->player.y)
		game->rabbit_orientation = 1;
}

// Update game.map after moving.
// Increment game.collectables if necessary. Redraws images on screen
static void	update_map_and_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_x][new_y] == 'C')
		game->collectables++;
	update_rabbit_orientation(game, new_x, new_y);
	draw_tile(game, new_x, new_y);
	game->map[game->player.x][game->player.y] = '0';
	game->map[new_x][new_y] = 'P';
	game->player.x = new_x;
	game->player.y = new_y;
}

// If possible, move the player
void	move_player(t_game *game, int new_x, int new_y)
{
	char	nxt_c;

	if (new_x >= 0 && new_x < game->map_height && new_y >= 0
		&& new_y < game->map_width)
	{
		nxt_c = game->map[new_x][new_y];
		if (nxt_c != '1' && (nxt_c != 'E' || its_won(game, new_x, new_y)))
		{
			game->is_jumping = 1;
			display_steps(game);
			if (nxt_c == 'H')
			{
				game->has_lost = 1;
				return ;
			}
			if (its_won(game, new_x, new_y))
			{
				mlx_image_to_window(game->mlx, game->grass_img, game->player.y
					* TILE_SIZE, (game->player.x + 1) * TILE_SIZE);
				game->has_won = 1;
				return ;
			}
			update_map_and_player(game, new_x, new_y);
		}
	}
}

// Retrieves the new position according to the key pressed
// and sends it to the move_player function
void	update_player_position(t_game *game, mlx_key_data_t key)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x;
	new_y = game->player.y;
	if (key.key == MLX_KEY_W)
		new_x -= 1;
	else if (key.key == MLX_KEY_S)
		new_x += 1;
	else if (key.key == MLX_KEY_A)
		new_y -= 1;
	else if (key.key == MLX_KEY_D)
		new_y += 1;
	if (key.key == MLX_KEY_W || key.key == MLX_KEY_S || key.key == MLX_KEY_A
		|| key.key == MLX_KEY_D)
		move_player(game, new_x, new_y);
}

// Moves the player according to the key pressed
void	movement(mlx_key_data_t key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->has_won || game->has_lost)
		return ;
	if (key.action == MLX_PRESS)
	{
		if (key.key == MLX_KEY_ESCAPE)
		{
			mlx_close_window(game->mlx);
			return ;
		}
		game->jump_frame = 0;
		game->jump_delay = 0;
		update_player_position(game, key);
	}
}
