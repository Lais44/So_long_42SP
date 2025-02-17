/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:30:29 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/15 20:06:16 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_game(t_game *game, char *path_map_file)
{
	game->map = read_map(path_map_file);
	game->map_copy = read_map(path_map_file);
	game->moves_count = 0;
	if (!game->map || !game->map_copy)
	{
		ft_putstr_fd("Error\nMap not loaded\n", 2);
		exit(1);
	}
	dimenssions_map(game);
	game->player_x = find_player_x(game->map);
	game->player_y = find_player_y(game->map);
	if (!validate_map(game))
		exit(1);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nmlx not initialized\n", 2);
		exit(1);
	}
	game->collectible_count = 0;
	game->collects = count_chars_game(game->map, 'C');
	game->window = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "window");
	loading_textures(game);
}

int	exit_game_2(t_game *game)
{
	exit_game(game);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game) * 1);
	if (!game)
		return (1);
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 33);
		return (1);
	}
	if (!validate_extension(argv[1]))
		return (ft_putstr_fd("[ERR0R] map must have .ber extension!\n", 2), 1);
	start_game(game, argv[1]);
	init_images(game);
	render_map(game);
	mlx_key_hook(game->window, handle, game);
	mlx_hook(game->window, 17, 0, exit_game_2, game);
	mlx_loop(game->mlx);
	free_maps(game->map, game->height);
	exit_game_2(game);
	free(game);
	return (0);
}
