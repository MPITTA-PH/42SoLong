/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:46:32 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/11 15:53:33 by mpitta-p         ###   ########.fr       */
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

static void	flood_fill(char **map, int x, int y, t_flood *flood_info)
{
	if (x < 0 || y < 0 || x >= flood_info->width || y>= flood_info->heigth || map[y][x] == '1' || map[y][x] == 'F')
		return;
	if (map[y][x] == 'C')
		(flood_info->collectibles++);
	if (map[y][x] == 'E')
		(flood_info->exit_founded = 1);
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, flood_info);
	flood_fill(map, x - 1, y, flood_info);
	flood_fill(map, x, y + 1, flood_info);
	flood_fill(map, x, y - 1, flood_info);	
}

void	validate_path(t_game *info)
{
	char	**map_copy;
	t_flood	flood_info;

	flood_info.collectibles = 0;
	flood_info.exit_founded = 0;
	flood_info.width = info->map_info.width;
	flood_info.heigth = info->map_info.height;

	map_copy = copy_map(info);
	flood_fill(map_copy, info->map_info.player_x, info->map_info.player_y, &flood_info);
	if (flood_info.collectibles != info->map_info.n_collects)
	{
		free_map_copy(map_copy, info->map_info.height);
		ft_error("Not all collectibles are reachble");
	}
	if (!flood_info.exit_founded)
	{
		free_map_copy(map_copy, info->map_info.height);
		ft_error("Exit is not reachble");
	}
	free_map_copy(map_copy, info->map_info.height);
	ft_printf("Path Validation passed with sucssess! All collectibles and exits are reachble!");
}