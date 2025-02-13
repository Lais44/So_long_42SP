/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:44:43 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/13 02:16:14 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "library/libft/libft.h"

# define TILE_SIZE 32
# define MAX_MAP_HEIGHT 100
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 600

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_game
{
	void		*mlx;
	int			moves_count;
	void		*player_imgs;
	void		*collect_imgs;
	char		**map;
	char		**map_copy;
	void		*win;
	void		*portal;
	void		*player;
	void		*ground;
	void		*wall;
	void		*collect;
	int			collects;
	int			player_x;
	int			player_y;
	int			collectible_count;
	void		*window;
	int			height;
	int			width;
}t_game;

typedef struct s_map
{
	char	**map;
	char	**grid;
	int		height;
	int		width;
	int		collectible_count;
	int		player_x;
	int		player_y;
}t_map;

// Macros para códigos de tecla
# define KEY_ESC 65307   // Código para a tecla ESC
# define KEY_W   119     // Código para a tecla W
# define KEY_A   97      // Código para a tecla A
# define KEY_S   115     // Código para a tecla S
# define KEY_D   100     // Código para a tecla D

int		check_for_exit(t_game *game);
void	copy_map(t_game *game);
char	**copy_the_original_map(char **original_map, int height);
int		validate_extension(const char *filename);
void	start_game(t_game *game, char *path_map_file);
void	init_game(t_game *game);
int		flood_fill(t_game *game, char **maps, int x, int y);
void	free_map_copy(char **grid, int height);
int		find_player_x(char **map);
int		find_player_y(char **map);
void	loading_textures(t_game *game);
int		render_map(t_game *game);
void	render_tile(t_game *game, char tile, int x, int y);
int		main(int argc, char **argv);
void	init_images(t_game *game);
int		handle(int keycode, t_game *game);
void	exit_game(t_game *game);
char	**read_maps(const char *map_type);
void	load_image(t_game *game, void **img, char *path);
void	process_movement(t_game *game, int px, int py);
int		is_surrounded_by_walls(char **map);
void	player_move(t_game *game, int x, int y);
int		dimenssions_map(t_game *game);
int		get_map_width(t_game *game);
int		get_map_height(t_game *game);
int		exit_game_2(void *game);
int		free_maps(char **grid, int heigth);
void	free_map(char **map, int size);
int		validate_map(t_game *game);
int		count_chars_game(char **map, char c);
char	**read_map(const char *file);

#endif