/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:29:21 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/08 20:30:33 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**read_maps(const char *map_type)
{
	int		fd;
	char	*line;
	int		i;
	char	**map;

	i = 0;
	fd = open(map_type, O_RDONLY, 0777);
	if (fd < 0)
		ft_putstr_fd("ERROR: CONNOT OPEN THE MAP TYPE\n", 2);
	map = malloc(sizeof(char *) * 1024);
	if (!map)
		ft_putstr_fd("ERROR: FAILED ON MEMORY", 2);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
