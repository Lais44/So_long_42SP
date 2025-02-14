/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:02:09 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/13 21:06:20 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	flood_fill(t_game *game, char **maps, int x, int y)
{
	if (x < 0 || y < 0 || !maps[y] || x >= (int)ft_strlen(maps[y])
		|| maps[y][x] == '1' || maps[y][x] == 'V')
		return (0);
	if (maps[y][x] == 'E')
	{
		maps[y][x] = 'V';
		return (0);
	}
	maps[y][x] = 'V';
	flood_fill(game, maps, x + 1, y);
	flood_fill(game, maps, x - 1, y);
	flood_fill(game, maps, x, y + 1);
	flood_fill(game, maps, x, y - 1);
	return (1);
}

int	check_for_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	flood_fill(game, game->map_copy, game->player_x, game->player_y);
	while (game->map_copy[i])
	{
		j = 0;
		while (game->map_copy[i][j])
		{
			if (game->map_copy[i][j] == 'E' || game->map_copy[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
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
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(0);
}
