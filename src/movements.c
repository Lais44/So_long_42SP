/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:09:24 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/10 18:09:51 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_game *game, int px, int py)
{
	if (game->map[py][px] == 'C')
		game->collect--;
	game->map[game->player_y][game->player_x] = '0';
	game->map[py][px] = 'P';
	game->player_x = px;
	game->player_y = py;
	render_map(game);
	if (game->collect == 0 && game->map[py][px] == 'E')
		exit_game(game);
}

int	handle_key(int key, void *param)
{
	int		px;
	int		py;
	t_game	*game;

	game = (t_game *)param;
	px = game->player_x;
	py = game->player_y;
	if (key == KEY_ESC)
		mlx_loop_end(game->mlx);
	else if (key == KEY_W)
		process_movement(game, px, py - 1);
	else if (key == KEY_A)
		process_movement(game, px - 1, py);
	else if (key == KEY_S)
		process_movement(game, px, py + 1);
	else if (key == KEY_D)
		process_movement(game, px + 1, py);
	return (0);
}

void	process_movement(t_game *game, int px, int py)
{
	if (px < 0 || py < 0 || px >= get_map_width(game->map)
		|| py >= get_map_height(game->map) || game->map[py][px] == '1')
		return ;
	if (game->map[py][px] == 'E' && game->collect > 0)
		return ;
	move_player(game, px, py);
}
