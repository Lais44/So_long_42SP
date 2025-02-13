/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:09:24 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/12 21:18:55 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_chars_game(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	update_player_position(t_game *game, int new_x, int new_y)
{
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves_count++;
	render_map(game);
}

static void	update_game_state(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + x;
	new_y = game->player_y + y;
	if (new_x < 0 || new_y < 0 || new_x >= game->width || new_y >= game->height)
		return ;
	if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'E')
	{
		if (game->map[new_y][new_x] == 'C')
			game->collectible_count++;
		game->map[new_y][new_x] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		update_player_position(game, new_x, new_y);
	}
	else if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectible_count == game->collects)
		{
			update_player_position(game, new_x, new_y);
			ft_putstr_fd("You win!\n", 1);
			exit_game(game);
		}
		return ;
	}
}

void	player_move(t_game *game, int x, int y)
{
	int	new_y;
	int	new_x;
	int	height;
	int	width;

	new_y = game->player_y + y;
	new_x = game->player_x + x;
	height = game->height;
	width = game->width;
	if (new_x >= 0 && new_y >= 0 && new_x < width && new_y < height)
	{
		if (game->map[new_y][new_x] != '1')
		{
			update_game_state(game, x, y);
		}
	}	
	ft_putstr_fd("Steps nubers: ", 1);
	ft_putnbr_fd(game->moves_count, 1);
	ft_putstr_fd("\n", 1);
}

int	handle(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game);
	else if (keycode == 119)
		player_move(game, 0, -1);
	else if (keycode == 115)
		player_move(game, 0, 1);
	else if (keycode == 97)
		player_move(game, -1, 0);
	else if (keycode == 100)
		player_move(game, 1, 0);
	return (0);
}
