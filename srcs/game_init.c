/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:02:30 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/11 19:52:08 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/so_long.h"

void	init_image(t_game *info)
{
	int	img_width;
	int	img_height;

	img_width = 64;
	img_height = 64;
	
	info->background = mlx_xpm_file_to_image(info->mlx, "assets/chao.xpm", &info->window_y, &info->window_x);
	info->wall = mlx_xpm_file_to_image(info->mlx, "assets/parede.xpm", &info->window_y, &info->window_x);
	/* info->colectable = mlx_xpm_file_to_image(info->mlx, "assets/duck", &info->window_y, &info->window_x);
	//atencao! nao sei se o computador podera ser a saida
	info->exit = mlx_xpm_file_to_image(info->mlx, "assets/Computer", &info->window_y, &info->window_x); */

	if (!info->background || !info->wall)//falta player enemy e collect
		ft_error("Failed to load images!");
} 