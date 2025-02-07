/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:15:18 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/05 18:59:31 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	loading_textures(t_game *game)
{
	int	size;

	size = 64;
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"image/wall.xpm", &size, &size);
	game->ground = mlx_xpm_file_to_image(game->mlx,
			"textures/ground.xpm", &size, &size);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &size, &size);
	game->portal = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &size, &size);
	game->collect = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &size, &size);
	if (!game->wall || !game->ground || !game->player
		|| !game->portal || !game->collect)
	{
		write(2, "Error\nFailed to load textures\n", 31);
		exit(1);
	}
}

void	init_images(t_game *game)
{
	load_image(game, &game->wall, "textures/wall.xpm");
	load_image(game, &game->portal, "textures/portal.xpm");
	load_image(game, &game->player, "textures/player.xpm");
	load_image(game, &game->ground, "textures/ground.xpm");
}

void	load_image(t_game *game, void **img, char *path)
{
	int	img_x;
	int	img_y;

	img_x = TILE_SIZE;
	img_y = TILE_SIZE;
	*img = mlx_xpm_file_to_image(game->mlx, path, &img_x, &img_y);
	if (!*img)
	{
		write(2, "Error: Failed to load ", 24);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		exit(1);
	}
}
