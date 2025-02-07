/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:44:43 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/07 17:36:31 by lleal-go         ###   ########.fr       */
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

# define TILE_SIZE 64
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# define MLX_ERROR 0

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'p'
# define EXIT 'E'
# define COLLECTIBLE 'C'

typedef struct s_game
{
	void		*mlx;
	int			moves_count;
	void		*player_imgs;
	void		*collect_imgs;
	char		*imgs[5];
	char		**map;
	void		*wall;
	void		*portal;
	void		*player;
	void		*ground;
	void		*collect;
	int			player_x;
	int			player_y;
}t_game;

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
	int		collectable_count;
	int		player_x;
	int		player_y;
}t_map;

char	**copy_the_original_map(char **original_map, int height);
int		validate_extension(const char *filename);
void	start_game(const char *path_map_file, t_game *game);
void	init_game(t_game *game);
char	**copy_the_original_map(char **original_map, int height);
void	flood_fill(char **map, int x, int y);
void	free_map_copy(char **grid, int height);
int		map_dimensions(t_map *map);
int		find_player_x(char **map);
int		find_player_y(char **map);
void	loading_textures(t_game *game);
int		render_map(t_game *game);
void	render_tile(t_game *game, char tile, int x, int y);
int		main(int argc, char **argv);

#endif