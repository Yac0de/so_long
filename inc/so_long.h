/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:41:32 by ymeziane          #+#    #+#             */
/*   Updated: 2023/11/27 22:48:46 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/inc/libft.h"
# include <fcntl.h>

# define TILE_SIZE 32

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_hunter
{
	t_point		position;
}				t_hunter;

typedef struct s_game
{
	char		**map;
	int			map_width;
	int			map_height;
	mlx_t		*mlx;
	mlx_image_t	*rabbit_img[4];
	mlx_image_t	*rabbit_r_jump[4];
	mlx_image_t	*rabbit_l_jump[4];
	mlx_image_t	*rabbit_u_jump[4];
	mlx_image_t	*rabbit_d_jump[4];
	mlx_image_t	*hunter_img[4];
	mlx_image_t	*tree_img;
	mlx_image_t	*tree2_img;
	mlx_image_t	*exit_img;
	mlx_image_t	*carrot_img;
	mlx_image_t	*grass_img;
	mlx_image_t	*step_img;
	t_point		player;
	t_point		exit;
	int			rabbit_orientation;
	int			count_square;
	int			collectables;
	int			total_collectables;
	int			count_steps;
	int			is_jumping;
	int			jump_frame;
	int			jump_delay;
	int			hunter_frame;
	int			hunter_delay;
	int			has_won;
	int			has_lost;
	int			win_counter;
	int			hunter_count;
	t_hunter	*hunters;
}				t_game;

char			**read_map(const char *file_path);
int				get_map_height(char **map);
int				init_struct_game(t_game *game);
void			init_frames_jump(t_game *game);
void			init_frames_rabit(t_game *game);
void			init_frames_hunter(t_game *game);
int				valid_map(char **map, int width, int height);
int				check_lines_same_length(char **map, int width);
int				check_walls(char **map, int width, int height);
int				check_chars(char **map);
void			free_map(char **map);
void			load_textures(t_game *game);
int				count_char(char **map, char c);
t_point			find_character(char **map);
t_point			find_exit(char **map);
mlx_image_t		*choose_image(t_game *game, int x, int y);
void			disables_rabbit_textures(t_game *game);
void			moove_and_enabled_img_jump(mlx_image_t **img,
					t_game *game, int x, int y);
void			draw_map(t_game *game);
void			display_steps(t_game *game);
void			movement(mlx_key_data_t key, void *param);
int				its_won(t_game *game, int new_x, int new_y);
void			draw_tile(t_game *game, int x, int y);
void			game_loop(void *param);
void			free_hunters(t_hunter *hunters);

#endif