/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:26:44 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/10 19:21:55 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_map(t_game *info, char *f_name)
{
	int		fd;
	int		i;
	char	*line;
	char	*char_search;

	i = 0;
	info->map_info.height = measure_lines(info, f_name);
	info->map_info.grid = ft_calloc(info->map_info.height + 2, sizeof(char **));
	if (!info->map_info.grid)
		ft_error("Erro a alocar memoria para o map");
	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		ft_error("ERROR - nao abriu o ficheiro");
	line = get_next_line(fd);
	while (line && i < info->map_info.height)
	{
		char_search = ft_strchr(line, '\n');
		if (char_search)
			*char_search = '\0';
		info->map_info.grid[i] = ft_strdup(line);
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
	info->moves = 0;//falta criar
}