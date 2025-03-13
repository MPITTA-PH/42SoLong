/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:30:00 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/13 15:30:00 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Centralized resource cleanup function */
void	free_resources(t_game *info)
{
	int	i;

	/* Destroy images if they exist */
	if (info->background)
		mlx_destroy_image(info->mlx, info->background);
	if (info->wall)
		mlx_destroy_image(info->mlx, info->wall);
	if (info->player)
		mlx_destroy_image(info->mlx, info->player);
	if (info->colectable)
		mlx_destroy_image(info->mlx, info->colectable);
	if (info->exit)
		mlx_destroy_image(info->mlx, info->exit);
	if (info->enemy)
		mlx_destroy_image(info->mlx, info->enemy);

	/* Destroy window and MLX if they exist */
	if (info->window && info->mlx)
		mlx_destroy_window(info->mlx, info->window);
	if (info->mlx)
	{
		mlx_destroy_display(info->mlx);
		free(info->mlx);
	}

	/* Free map grid if it exists */
	if (info->map_info.grid)
	{
		i = 0;
		while (i < info->map_info.height && info->map_info.grid[i])
		{
			free(info->map_info.grid[i]);
			i++;
		}
		free(info->map_info.grid);
	}
}