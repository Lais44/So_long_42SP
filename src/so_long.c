/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:30:29 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/07 17:39:45 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	mlx_key_hook(game->mlx, &game);
	mlx_loop(game->mlx);
}

void	start_game(const char *path_map_file, t_game *game)
{
	int		map_width_height;
	t_map	map_info;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd ("ERROR: FEILED TO INICIALIZE MLX\n", 32);
		exit(1);
	}
	map_info.grid = game->map;
	map_width_height = map_dimensions(game->map);
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
