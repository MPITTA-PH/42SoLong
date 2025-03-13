/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:26:44 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/12 15:43:19 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_map(t_game *info, char *f_name)
{
	int		fd;
	int		i;
	char	*line;
	char	*newline_pos;

	i = 0;
	info->map_info.height = measure_lines(info, f_name);
	info->map_info.grid = ft_calloc(info->map_info.height + 1, sizeof(char **));
	if (!info->map_info.grid)
		ft_error("Memory allocation for map grid failed");
	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		ft_error("Failed to open map file");
	line = get_next_line(fd);
	while (line && i < info->map_info.height)
	{
		newline_pos = ft_strchr(line, '\n');
		if (newline_pos)
			*newline_pos = '\0';
		info->map_info.grid[i] = ft_strdup(line);
		if (!info->map_info.grid[i])
		{
			while (--i >= 0)
				free (info->map_info.grid[i]);
			free (info->map_info.grid);
			free (line);
			close (fd);
			ft_error ("Memory allocation failed for the map");
		}
		free(line);
		i++;
		line = get_next_line(fd);
	}
	info->map_info.grid[i] = NULL;
	close (fd);
}

void	init_elems(t_game *info)
{
	info->map_info.n_player = 0;
	info->map_info.n_enemy = 0;
	info->map_info.n_collects = 0;
	info->map_info.n_exit = 0;
	info->moves = 0;
	info->key_pressed = 0;

	info->background = NULL;
	info->wall = NULL;
	info->player = NULL;
	info->colectable = NULL;
	info->exit = NULL;
	info->enemy = NULL;

	info->mlx = NULL;
	info->window = NULL;
}