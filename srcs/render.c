/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:52:31 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/11 19:51:44 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	put_image(t_game *info, void *img, int x, int y)
{
	mlx_put_image_to_window(info->mlx, info->window, img, x * 64, y * 64);
}

void	render_tile(t_game *info, int x, int y)
{
	char	tile;
	
	tile = info->map_info.grid[y][x];
	put_image(info, info->background, x, y);

	if (tile == '1')
		put_image(info, info->wall, x, y);
	if (tile == 'P')
		put_image(info, info->player, x, y);
	if (tile == 'C')
		put_image(info, info->colectable, x, y);
	if (tile == 'E')
		put_image(info, info->exit, x, y);
	if (tile == 'X')
		put_image(info, info->enemy, x, y);
}

void render_map(t_game *info)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < info->map_info.height)
	{
		x = 0;
		while (x < info->map_info.width)
		{
			render_tile(info, x, y);
			x++;
		}
		y++;
	}
	char	*moves_str;

	moves_str = ft_itoa(info->moves);
	mlx_string_put(info->mlx, info->window, 10, 20, 0XFFFFFF, "Moves:");
	mlx_string_put(info->mlx, info->window, 70, 20, 0XFFFFFF, moves_str);
	free(moves_str);
}