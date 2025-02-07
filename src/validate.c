/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:28:49 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/05 20:41:39 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_rectangular_map(t_map *map)
{
	int		i;
	int		len;

	i = 0;
	while (i < map->height)
	{
		len = ft_strlen(map->grid[i]);
		if (len != map->width)
			return (0);
		i++;
	}
	return (1);
}

static int	wall_check(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->grid[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		if (map-> grid[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_components(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] != 'P' || map->grid[i][j] != 'E'
				|| map->grid[i][j] != 'C' || map->grid[i][j]!= 'W'
					|| map->grid[i][j] != 'O')
				return (ft_putstr_fd("ERROR: NEED ALL COMPONENTS", 2), 0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	path_valid_to_check(t_map *map)
{
	char	**copy_map;
	int		line;
	int		column;

	copy_map = copy_the_original_map(map->grid, map->height);
	if (!copy_map)
		return (0);
	flood_fill(copy_map, map->player_x, map->player_y);
	line = 0;
	while (line < map->height)
	{
		column = 0;
		while (column < map->width)
		{
			if (copy_map[line][column] == 'C' || copy_map[line][column] == 'E')
			{
				free_map_copy(copy_map, map->height);
				return (0);
			}
			column++;
		}
		line++;
	}
	free_map_copy(copy_map, map->height);
	return (1);
}

int	validate_map(t_map *map)
{
	if (!check_rectangular_map(map))
		return (ft_putstr_fd("ERROR: MAP IS NOT RECTANGULAR\n", 2), 0);
	if (!wall_check(map))
		return (ft_putstr_fd("ERROR: MAP IS NOT SURROUNDED BY WALLS\n", 2), 0);
	if (!check_components(map))
		return (ft_putstr_fd("ERROR: INVALID NUMBER OF ELEMENTS\n", 2), 0);
	if (!path_valid_to_check(map))
		return (ft_putstr_fd("ERROR: INVALID PATH\n", 2), 0);
	return (1);
}
