/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:17:58 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/11 12:44:14 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	validate_map(t_game *info, char *f_name)
{
	measure_lines(info, f_name);
	validate_map_shape(info);
	validate_map_walls(info);
	set_map_limits(info);
	num_of_elems(info);
}

int	measure_lines(t_game *info, char *f_name)
{
	int		fd;
	int		n_lines;
	char	*line;

	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		ft_error("Nao foi possivel abrir o ficheiro");
	n_lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		n_lines++;
		line = get_next_line(fd);		
	}
	close (fd);
	if (n_lines == 0)
		ft_error("Altura invalida");
	info->map_info.height = n_lines;
	return (n_lines);
}

void	validate_map_shape(t_game *info)
{
	int		i;
	size_t	f_line;

	if (!info->map_info.grid || !info->map_info.grid[0])
		ft_error("Tamanho do mapa invalido");
	f_line = ft_strlen(info->map_info.grid[0]);
	i = 1;
	while (info->map_info.grid[i])
	{
		if (ft_strlen(info->map_info.grid[i]) != f_line)
			ft_error("Comprimento do mapa invalido!");
		i++;
	}
	info->map_info.width = f_line;
}

void	validate_map_walls(t_game *info)
{
	int	i;
	int	height;
	int	width;

	i = 0;
	height = info->map_info.height;
	width = info->map_info.width;
	while (i < width)
	{
		if (info->map_info.grid[0][i] != '1' || info->map_info.grid[height - 1][i] != '1')
			ft_error("The map is not surrounded by 1's!");
		else
			i++;
	}
	i = 0;
	while (i < height)
	{
		if (info->map_info.grid[i][0] != '1' || info->map_info.grid[i][width - 1] != '1')
			ft_error("The map os not surrounded by 1's");
		else
			i++;
	}
}