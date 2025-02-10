/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:30:29 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/09 23:18:51 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_game(char *path_map_file, t_game *game)
{
	int		map_width_height;
	t_map	*map;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd ("ERROR: FEILED TO INICIALIZE MLX\n", 32);
		exit(1);
	}
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (ft_putstr_fd("[ERROR]Failed to allocate memory for map.\n", 2));
	game->map = read_maps(path_map_file);
	if (validate_map(map) != 0)
	{
		write(2, "Error: Invalid map\n", 19);
		exit(1);
	}
	map_width_height = get_map_dimensions(map, map->grid);
	render_map(game);
	game->player_x = find_player_x(game->map);
	game->player_y = find_player_y(game->map);
	loading_textures(game);
}

void	init_game(t_game *game)
{
	int	i;

	i = -1;
	game->mlx = NULL;
	game->moves_count = 0;
	game->map = NULL;
	while (++i < 5)
		game->imgs[i] = NULL;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc((sizeof(t_game) * 1));
	if (!game)
		return (1);
	if (argc != 2)
	{
		ft_putstr_fd("Error: Usage: ./so_long <map.ber>\n", 2);
		free(game);
		return (1);
	}
	start_game(argv[1], game);
	init_images(game);
	mlx_hook(game->win, 2, 1L << 0, handle_key, game);
	mlx_loop(game->mlx);
	exit_game(game);
	return (0);
}
