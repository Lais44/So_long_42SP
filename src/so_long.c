/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:30:29 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/10 20:03:52 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_game(t_game *game, char *path_map_file)
{
	int		map_width;
	int		map_height;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		write(2, "Error: Failed to initialize MLX\n", 32);
		free(game);
		exit(1);
	}
	game->map = read_maps(path_map_file);
	if (validate_map(game->map) != 0)
	{
		write(2, "Error: Invalid map\n", 19);
		free(game->map);
		exit(1);
	}
	game->player_x = find_player_x(game->map);
	game->player_y = find_player_y(game->map);
	game->collects = count_chars(game->map, 'C');
	map_width = get_map_width(game->map);
	map_height = get_map_height(game->map);
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "so_long");
	loading_textures(game);
}

int	handle_exit(void *param)
{
	exit_game((t_game *)param);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc((sizeof(t_game) * 1));
	if (!game)
		return (1);
	if (argc != 2)
	{
		write(2, "Error\nUsage: ./so_long <map.ber>\n", 33);
		free(game);
		return (1);
	}
	start_game(game, argv[1]);
	init_images(game);
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, handle_key, game);
	mlx_hook(game->win, 17, 0, handle_exit, game);
	mlx_loop(game->mlx);
	exit_game(game);
	return (0);
}
