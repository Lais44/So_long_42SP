/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:08:03 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/13 01:04:16 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_map_width(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] && game->map[i] != NULL)
		i++;
	return (i);
}

int	get_map_height(t_game *game)
{
	int	i;

	i = 0;
	if (game->map != NULL && game->map[i] != NULL)
	{
		while (game->map[0][i])
		{
			i++;
		}
	}
	return (i);
}

int	dimenssions_map(t_game *game)
{
	game->width = get_map_height(game);
	game->height = get_map_width(game);
	game->width -= 1;
	return (0);
}

int	find_player_x(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				return (x);
			x++;
		}
	y++;
	}
	return (-1);
}

int	find_player_y(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				return (y);
			x++;
		}
		y++;
	}
	return (-1);
}
