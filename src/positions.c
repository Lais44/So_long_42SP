/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:08:03 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/08 20:23:09 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_map_dimensions(t_map *map, char **map_data)
{
	if (!map || !map_data)
		return (-1);
	map->width = 0;
	map->height = 0;
	map->width = ft_strlen(map_data[0]);
	while (map_data[map->height])
		map->height++;
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
