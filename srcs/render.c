/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:52:31 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/12 18:54:22 by mpitta-p         ###   ########.fr       */
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
	if (info->background)
		put_image(info, info->background, x, y);

	if (tile == '1' && info->wall)
		put_image(info, info->wall, x, y);

	if (tile == 'P' && info->player)
		put_image(info, info->player, x, y);

	if (tile == 'C' && info->colectable)
		put_image(info, info->colectable, x, y);

	if (tile == 'E' && info->exit)
		put_image(info, info->exit, x, y);
		//aqui posso fazer a atualizacao da imagem, quando apanho todos os patos o computador liga...
		
	if (tile == 'X' && info->enemy)
		put_image(info, info->enemy, x, y);
}

void render_map(t_game *info)
{
	int	x;
	int	y;
	char	*moves_str;
	
	y = 0;
	while (y < info->map_info.height)
	{
		x = 0;
		while (x < info->map_info.width)
		{
			render_tile(info, x, y);
/* 			ft_printf("dentro da funcao render tile"); */
			x++;
		}
		/* ft_printf("dentro do loop de render_map"); */
		y++;
	}
/* 	ft_printf("ANTES DA ALOCACAO DE MEMORIA PARA A STRING MOVES"); */
	moves_str = ft_itoa(info->moves);
	if (moves_str == NULL)
		ft_error("Failed to allocate memory for 'moves_str'");
	
	//funcao para apagar a string antiga para depois escrever a nova
	mlx_string_put(info->mlx, info->window, 10, 20, 0X000000, "             ");
	
	//escrever a string no ecra
	mlx_string_put(info->mlx, info->window, 10, 20, 0XFFFFFF, "Moves:");
	mlx_string_put(info->mlx, info->window, 70, 20, 0XFFFFFF, moves_str);
	free(moves_str);
}

void	update_exit_status(t_game *info)
{
	static int exit_status;

	exit_status = 0;
	if (info->map_info.n_collects == 0)
	{
		ft_printf("Nice job, you've collected all collectibles!🐤 Exit is now open🚪🔓");
		exit_status = 1;
	}
}