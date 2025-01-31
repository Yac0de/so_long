/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:40:28 by ymeziane          #+#    #+#             */
/*   Updated: 2023/11/27 21:40:01 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Updates the bunny jump animation every x frames if is jumping
static void	update_jump_rabbit_animation(t_game *game)
{
	if (game->is_jumping)
	{
		game->jump_delay++;
		if (game->jump_delay >= 50)
		{
			game->jump_frame++;
			game->jump_delay = 0;
			if (game->jump_frame >= 4)
			{
				game->jump_frame = 0;
				game->is_jumping = false;
			}
			draw_tile(game, game->player.x, game->player.y);
		}
	}
}

// Update hunter animation every x frames
static void	update_hunter_animation(t_game *game)
{
	game->hunter_delay++;
	if (game->hunter_delay >= 100)
	{
		game->hunter_frame = (game->hunter_frame + 1) % 4;
		game->hunter_delay = 0;
		game->hunter_img[0]->enabled = 0;
		game->hunter_img[1]->enabled = 0;
		game->hunter_img[2]->enabled = 0;
		game->hunter_img[3]->enabled = 0;
		game->hunter_img[game->hunter_frame]->enabled = 1;
	}
}

static void	print_win_message(void)
{
	ft_printf("\n\n:::   :::  ::::::::  :::    ::: 	:::  "
		"     :::  ::::::::  ::::    ::: \n"
		":+:   :+: :+:    :+: :+:    :+:"
		" 	:+:       :+: :+:    :+: :+:+:   :+:\n"
		" +:+ +:+  +:+    +:+ +:+    +:+"
		" 	+:+       +:+ +:+    +:+ :+:+:+  +:+ \n"
		"  +#++:   +#+    +:+ +#+    +:+"
		" 	+#+  +:+  +#+ +#+    +:+ +#+ +:+ +#+\n"
		"   +#+    +#+    +#+ +#+    +#+"
		" 	+#+ +#+#+ +#+ +#+    +#+ +#+  +#+#+#\n"
		"   #+#    #+#    #+# #+#    #+#"
		" 	 #+#+# #+#+#  #+#    #+# #+#   #+#+#\n"
		"   ###     ########   ########"
		"  	  ###   ###    ########  ###    ####\n\n");
}

static void	print_loose_message(void)
{
	ft_printf("\n\n:::   :::  ::::::::  :::"
		"    ::: 	:::         ::::::::   :::::::: ::::::::::\n"
		":+:   :+: :+:    :+: :+:    :+:"
		" 	:+:        :+:    :+: :+:    :+:    :+:     \n"
		" +:+ +:+  +:+    +:+ +:+    +:+"
		" 	+:+        +:+    +:+ +:+           +:+     \n"
		"  +#++:   +#+    +:+ +#+    +:+"
		" 	+#+        +#+    +:+ +#++:++#++    +#+  \n"
		"   +#+    +#+    +#+ +#+    +#+"
		" 	+#+        +#+    +#+        +#+    +#+  \n"
		"   #+#    #+#    #+# #+#    #+#"
		" 	#+#        #+#    #+# #+#    #+#    #+#   \n"
		"   ###     ########   ########"
		"  	##########  ########   ########     ###   \n\n");
}

// Game loop executed every frame. Manages victory or defeat and animations
void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->has_won)
	{
		game->win_counter++;
		if (game->win_counter >= 50)
		{
			mlx_close_window(game->mlx);
			print_win_message();
		}
	}
	else if (game->has_lost)
	{
		mlx_close_window(game->mlx);
		print_loose_message();
	}
	else
	{
		update_jump_rabbit_animation(game);
		update_hunter_animation(game);
	}
}
