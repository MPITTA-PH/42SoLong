/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elems.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelhenriques <miguelhenriques@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:55:08 by miguelhenri       #+#    #+#             */
/*   Updated: 2025/03/07 18:57:17 by miguelhenri      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_game *info, int x, int y)
{
	info->map_info.n_player++;
	info->map_info.player_x = x;
	info->map_info.player_y = y;
	ft_printf("P_X = %d\n", x);
	ft_printf("P_Y = %d\n", y);
}

int	invalid_element(t_game *info, int x, int y)
{
	if (info->map_info.grid[y][x] == 'P' || info->map_info.grid != 'E'
		|| info->map_info.grid != 'C' || info->map_info.grid != '0'
		|| info->map_info.grid != '1' || info->map_info.grid != 'X') //aqui talvez faça falta a quebra de linha o ou NULL
	{
		return (-1);
	}
	return (0);
}

void	num_of_elems(t_game *info)
{
	if (info->map_info.n_player < 1)
		ft_error("Insufficient players");
	if (info->map_info.n_player > 1)
		ft_error("To many players");
	if (info->map_info.n_exit != 1)
		ft_error("Wrong number of exits");
	if (info->map_info.n_collects == 0)
		ft_error("Not enough collectables");
}

void	elem_counter(t_game *info, int end_x, int end_y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= end_x || y <= end_y)
	{
		y = 0;
		while (y <= end_y)
		{
			if (info->map_info.grid[y][x] == 'P')
				player_position(info, x, y);
			else if (info->map_info.grid[y][x] == 'C')
				info->map_info.n_collects++;
			else if (info->map_info.grid[y][x] == 'X')
				info->map_info.n_enemy++;
			else if (info->map_info.grid[y][x] == 'E')
				info->map_info.n_exit++;
			if (invalid_element(info, x, y))
				error("Invalid elements were found");
			y++;
		}
		x++;
	}
}
void	set_map_limits(t_game *info)
{
	int	end_x;
	int	end_y;

	end_x = info->map_info.width - 1;
	end_y = info->map_info.height - 1;
	elem_counter(info, end_x, end_y);
}