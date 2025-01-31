/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:59:11 by ymeziane          #+#    #+#             */
/*   Updated: 2025/01/31 17:19:04 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//Allocates memory to my t_game structure's hunter list
//and adds hunters to the list with their positions
static void	allocate_hunters(t_game *game)
{
	int	x;
	int	y;
	int	hunter_index;

	game->hunters = malloc(sizeof(t_hunter) * game->hunter_count);
	hunter_index = 0;
	x = 0;
	while (x < game->map_height && hunter_index < game->hunter_count)
	{
		y = 0;
		while (y < game->map_width)
		{
			if (game->map[x][y] == 'H')
				game->hunters[hunter_index++] = (t_hunter){{x, y}};
			y++;
		}
		x++;
	}
}

// Initializes all integers in t_game structure
static void	init_int(t_game *game)
{
	game->rabbit_orientation = 2;
	game->count_square = 0;
	game->collectables = 0;
	game->total_collectables = count_char(game->map, 'C');
	game->count_steps = 0;
	game->is_jumping = 0;
	game->jump_frame = 0;
	game->jump_delay = 0;
	game->hunter_frame = 0;
	game->hunter_delay = 0;
	game->has_won = 0;
	game->has_lost = 0;
	game->win_counter = 0;
}

// Initializes objects in t_game structure
int	init_struct_game(t_game *game)
{
	game->map_width = ft_strlen(game->map[0]);
	game->map_height = get_map_height(game->map);
	if (!valid_map(game->map, game->map_width, game->map_height))
		return (free_map(game->map), 0);
	game->mlx = mlx_init(game->map_width * TILE_SIZE, (game->map_height + 1)
			* TILE_SIZE, "SO LONG", true);
	if (!game->mlx)
		return (0);
	load_textures(game);
	game->step_img = NULL;
	init_int(game);
	game->player = find_character(game->map);
	game->exit = find_exit(game->map);
	game->hunter_count = count_char(game->map, 'H');
	allocate_hunters(game);
	init_frames_jump(game);
	init_frames_rabit(game);
	init_frames_hunter(game);
	return (1);
}
