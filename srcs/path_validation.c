/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:46:32 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/11 14:26:21 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static char	**copy_map(t_game *info)
{
	char **map_copy;
	int	i;

	map_copy = ft_calloc(info->map_info.height + 1, sizeof(char *));
	if (!map_copy)
		ft_error("Cannot allocate memory for the map copy");
	i = 0;
	while (i < info->map_info.height)
	{
		map_copy[i] = ft_strdup(info->map_info.grid[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			ft_error("Cannot copy the map)");
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static void	flood_fill(char **map, int x, int y, t_game *info)
{
	if (x < 0 || y < 0 || x >= info->map_info.width || y>= info->map_info.height || map[y][x] == '1' || map[y][x] == 'F')
		return;
	if (map[y][x] == 'C')
		(info->map_info.n_collects++);
	if (map[y][x] == 'X')
		(info->map_info.n_exit++);
	map[y][x] == 'F';
	flood_fill(map, x + 1, y, info);
	flood_fill(map, x - 1, y, info);
	flood_fill(map, x, y + 1, info);
	flood_fill(map, x, y - 1, info);	
}

static void	free_map_copy(char **map_copy, int height)
{
	int	i;

	i = 0;
	while (i <= height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}