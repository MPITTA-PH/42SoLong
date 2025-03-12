/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:00:33 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/12 15:14:40 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	open_wind(t_game *info)
{

	int	window_width;
	int	window_height;
	
	window_width = info->map_info.width * 64;
	window_height = info->map_info.height * 64;

/* 	ft_printf("W:%d | H:%d\n", window_width, window_height);
 */	
	
	info->mlx = mlx_init();
	if (!info->mlx)
		ft_error("ERROR - falaha a conectar a mlx");
	info->window = mlx_new_window(info->mlx, window_width, window_height, "so_long");
	if (!info->window)
	{
		mlx_destroy_display(info->mlx);
		free(info->mlx);
		ft_error("Nao abriu a janela!");
	}
}