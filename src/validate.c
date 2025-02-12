/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:28:49 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/11 20:57:26 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	retang_check_maps(t_game *game)
{
	int	i;

	i = 1;
	while (i < game -> height)
	{
		if ((int) ft_strlen(game->map[i]) != game->width)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	border_check_maps(t_game *game)
{
	int	i;

	i = 0;
	if (!retang_check_maps(game))
		return (0);
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < game->width)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	components_check_maps(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->height)
		{
			if (game->map[i][j] != 'P' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'C' && game->map[i][j]!= '1'
					&& game->map[i][j] != 'O')
				return (ft_putstr_fd("ERROR: NEED ALL COMPONENTS", 2), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	game = malloc(sizeof(t_game) * 1);
	if (!game)
		return (free(game), 0);
	if (!retang_check_maps(game))
		return (ft_putstr_fd("[ERROR] MAPS NOT RETANGLE\n", 2), 0);
	if (!border_check_maps(game))
		return (ft_putstr_fd("[ERROR] INVALID BORDER MAPS\n", 2), 0);
	if (!components_check_maps(game))
		return (ft_putstr_fd("ERROR: NEED ALL COMPONENTS", 2), 0);
	if (!flood_fill(game, game->map, game->player_x, game->player_y))
	{
		return (ft_putstr_fd("[ERROR] MAPS NOT VISITED\n", 2), 0);
	}
	return (1);
}
