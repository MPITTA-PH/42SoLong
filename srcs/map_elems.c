/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elems.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:55:08 by miguelhenri       #+#    #+#             */
/*   Updated: 2025/03/11 15:51:11 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	player_position(t_game *info, int x, int y)
{
	info->map_info.n_player++;
	info->map_info.player_x = x;
	info->map_info.player_y = y;
}

int	invalid_element(t_game *info, int x, int y)
{
	char	element;

	element = info->map_info.grid[y][x];

	if (element != PLAYER && element != EXIT
		&& element != COLLECTIBLE && element != EMPTY
		&& element != WALL && element != ENEMY) 
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
	char	element;

	x = 0;
	while (x <= end_x)
	{
		y = 0;
		while (y <= end_y)
		{
			element = info->map_info.grid[y][x];
			if (element == PLAYER)
				player_position(info, x, y);
			else if (element == COLLECTIBLE)
				info->map_info.n_collects++;
			else if (element == ENEMY)
				info->map_info.n_enemy++;
			else if (element == EXIT)
				info->map_info.n_exit++;
			if (invalid_element(info, x, y))
				ft_error("Invalid elements were found");
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