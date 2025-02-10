/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:08:03 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/10 17:42:43 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_map_width(char **map_data)
{
	char	**map;

	map = map_data;
	if (!map[0])
		return (0);
	return (ft_strlen(map[0]) - 1);
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
	height++;
	return (height);
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
