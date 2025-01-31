/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:42:59 by ymeziane          #+#    #+#             */
/*   Updated: 2025/01/31 17:18:31 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Checks extension
static bool	has_valid_extension(const char *filename, const char *extension)
{
	const char	*dot;

	dot = ft_strrchr(filename, '.');
	return (dot && !ft_strcmp(dot, extension));
}

// Checks user input
static int	check_input(int argc, char **argv)
{
	if (argc != 2)
		return (ft_printf("Error\nUsage: %s <map_file.ber>\n", argv[0]), 0);
	if (!has_valid_extension(argv[1], ".ber"))
		return (ft_printf("Error\nThe file must have the extension '.ber'\n"),
			0);
	return (1);
}

int32_t	main(int argc, char **argv)
{
	t_game	game;

	if (!check_input(argc, argv))
		return (1);
	game.map = read_map(argv[1]);
	if (!game.map || !ft_strlen(game.map[0]))
		return (ft_printf("Error\nThe map is empty or an error has occurred\n"),
			0);
	if (!init_struct_game(&game))
		return (1);
	draw_map(&game);
	mlx_key_hook(game.mlx, movement, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	free_hunters(game.hunters);
	free_map(game.map);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
