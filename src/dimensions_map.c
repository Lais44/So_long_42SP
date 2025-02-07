/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:41:39 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/07 17:22:54 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_dimensions(t_map *map)
{
	int	max_width;
	int	max_height;

	max_width = 0;
	max_height = 0;
	if (max_height > 300 || max_width > 600)
		return (0);
	if (max_height <= 0 || max_width <= 0)
	{
		max_width = 1920;
		max_height = 1080;
	}
	if (!calculate_dimensions(map, max_width, max_height))
	{
		free(map);
		exit(1);
	}
	return (1);
}
