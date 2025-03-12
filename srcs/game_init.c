/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:02:30 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/12 16:53:03 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/so_long.h"

void	init_image(t_game *info)
{
	int	img_width;
	int	img_height;

	img_width = 64;
	img_height = 64;
	
	info->background = mlx_xpm_file_to_image(info->mlx, "assets/chao.xpm", &img_width, &img_width);
	info->wall = mlx_xpm_file_to_image(info->mlx, "assets/parede.xpm", &img_width, &img_width);
	info->colectable = mlx_xpm_file_to_image(info->mlx, "assets/pato-com-fundo.xpm", &info->window_y, &info->window_x);
	//atencao! nao sei se o computador podera ser a saida
	//quero fazer um efeito visual na saida, com brilho e assim
	info->exit = mlx_xpm_file_to_image(info->mlx, "assets/computador(comfundo).xpm", &info->window_y, &info->window_x);
	info->player = mlx_xpm_file_to_image(info->mlx, "assets/Design(1).xpm", &img_width, &img_height);

/* 	info->player = NULL;
	info->colectable = NULL;
	info->exit = NULL;
	info->enemy = NULL; */
	
	if (!info->background)//falta player enemy e collect
		ft_error("Failed to load background!");
	if (!info->wall)
		ft_error("Failed to load wall!");
	if (!info->player)
		ft_error("Failed to load player");
}