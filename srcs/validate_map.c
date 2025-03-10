/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:17:58 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/10 19:06:23 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	validate_map(t_game *info, char *f_name)
{
	measure_lines(info, f_name);
	validate_map_shape(info);
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
		ft_printf("ola");
		if (ft_strlen(info->map_info.grid[i]) != f_line)
			ft_error("Comprimento do mapa invalido!");
		i++;
	}
	info->map_info.width = f_line;
}
