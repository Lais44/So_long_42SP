/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:28:49 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/10 19:11:47 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_surrounded_by_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if ((i == 0 || (map[i + 1] == NULL && map[i][j] != '1')))
				return (0);
			if ((j == 0 || (map[i][j + 1] == '\0' && map[i][j] != '1')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	count_chars(char **map, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

int	is_valid_path(t_game *game)
{
	char	**map_copy;

	map_copy = copy_map(game->map);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->player_x, game->player_y);
	return (check_unreachable(game, map_copy));
}

char	**copy_map(char **map)
{
	int		i;
	char	**new_map;
	int		height;

	height = get_map_height(map);
	new_map = malloc(sizeof(char *) * (height + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			free_map(new_map, i);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

int	validate_map(char **map)
{
	t_game	game;

	if (!is_surrounded_by_walls(map))
		return (0);
	if (count_chars(map, 'P') != 1)
		return (0);
	if (count_chars(map, 'E') != 1)
		return (0);
	if (count_chars(map, 'C') < 1)
		return (0);
	if (!is_valid_path(&game))
	{
		write(2, "Error: No valid path\n", 21);
		return (0);
	}
	return (1);
}
