/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:28:49 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/15 20:11:31 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	retang_check_maps(t_game *game)
{
	int	i;
	int	line_size;

	i = 0;
	line_size = 0;
	while (game->map[i])
	{
		line_size = (((int) ft_strlen(game->map[i])) - 1);
		if (i == (game->height - 1) && !game->map[i][game->width])
			line_size++;
		if (line_size != game->width)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	border_check_maps(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_valid_char(char c)
{
	static int	is_p = 0;
	static int	is_c = 0;
	static int	is_e = 0;

	if (c == 'P')
		is_p++;
	else if (c == 'E')
		is_e++;
	else if (c == 'C')
		is_c = 1;
	else if (c == '0')
		return (1);
	else if (c == '1')
		return (1 + (is_c + is_e + is_p));
	else
		return (0);
	if (is_p > 1 || is_e > 1)
		return (0);
	return ((is_c + is_e + is_p));
}

int	components_check_maps(t_game *game)
{
	char		components[5];
	int			i;
	int			j;

	i = 0;
	components[4] = '\0';
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (!is_valid_char(game->map[i][j]))
				return (ft_putstr_fd("[ERROR] INVALID COMPONENT\n", 2), 0);
			j++;
		}
		i++;
	}
	if (is_valid_char('1') != 4)
		return (ft_putstr_fd("[ERROR] NEED ALL COMPONENTS\n", 2), 0);
	return (1);
}

int	validate_map(t_game *game)
{
	if (!retang_check_maps(game))
		return (ft_putstr_fd("[ERROR] MAPS NOT RETANGLE\n", 2),
			exit_game(game), free(game), 0);
	if (!border_check_maps(game))
		return (ft_putstr_fd("[ERROR] INVALID BORDER MAPS\n", 2),
			exit_game(game), free(game), 0);
	if (!components_check_maps(game))
		return (exit_game(game), free(game), 0);
	if (!check_for_exit(game))
		return (ft_putstr_fd("[ERROR] MAPS NOT VISITED\n", 2),
			exit_game(game), free(game), 0);
	return (1);
}
