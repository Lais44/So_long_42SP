/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:02:09 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/11 22:06:35 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	flood_fill(t_game *game, char **maps, int x, int y)
{
	if (x < 0 || y < 0 || !maps[y] || x >= (int)ft_strlen(maps[y])
		|| maps[y][x] == '1' || maps[y][x] == 'V')
		return (0);
	if (maps[y][x] == 'C')
	{
		game->collectible_count--;
		maps[y][x] = 'V';
	}
	if (maps[y][x] == '0')
		maps[y][x] = 'V';
	flood_fill(game, maps, x + 1, y);
	flood_fill(game, maps, x - 1, y);
	flood_fill(game, maps, x, y + 1);
	flood_fill(game, maps, x, y - 1);
	return (1);
}

int	free_maps(char **grid, int heigth)
{
	int	i;

	i = 0;
	if (!grid)
		return (0);
	while (i < heigth && grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	return (1);
}

void	exit_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->ground);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->portal);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	exit(0);
}
