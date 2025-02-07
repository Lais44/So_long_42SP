/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:30:29 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/07 13:31:54 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc((sizeof(t_game) * 1));
	if (!game)
		return (1);
	if (argc != 2)
	{
		write(2, "Error: Usage: ./so_long <map.ber>\n", 33);
		free(game);
		return (1);
	}

/*int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "window");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (1);
	}
	while (1)
	{
		mlx_destroy_window(mlx_ptr, win_ptr);
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
	}
	return (0);
}
*/

int	validate_extension(const char *name)
{
	size_t	len;

	len = ft_strlen(name);
	if (len < 4)
		return (0);
	return (!ft_strncmp(name + len - 4, ".ber", 4));
}

void	start_game(const char *path_map_file)
{
	t_map	*map;
	t_game	game;

	init_game(&game);
}

void	init_game(t_game *game)
{
	int	i;

	i = -1;
	game->mlx = NULL;
	game->moves_count = 0;
	game->map = NULL;
	while (++i < 5)
		game->imgs[i] = NULL;
}
