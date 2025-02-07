/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_flood_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:02:09 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/07 16:02:15 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || x >= (int)ft_strlen(map[y])
		|| map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'E')
		map[y][x] = 'V';
	flood_fill (map, x + 1, y);
	flood_fill (map, x - 1, y);
	flood_fill (map, x, y + 1);
	flood_fill (map, x, y - 1);
}

void	free_map_copy(char **grid, int height)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (i < height && grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
