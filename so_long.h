/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:44:43 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/05 17:46:18 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

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
int		main(void);
int		validate_extension(const char *filename);
void	start_game(const char *path_map_file);
void	init_game(t_game *game);
char	**copy_the_original_map(char **original_map, int height);
void	flood_fill(char **map, int x, int y);
void	free_map_copy(char **grid, int height);
#endif