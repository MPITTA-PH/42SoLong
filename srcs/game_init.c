/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gae_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:02:30 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/08 20:18:33 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_image(t_game *game)
{
	game->background = mlx_xpm_file_to_image(game->mlx, "assets/Floor.xpm", &game->window_y, &game->window_x);
	game->wall = mlx_xpm_file_to_image(game->mlx, "assets/Wall.xpm", &game->window_y, &game->window_x);
	game->colectable = mlx_xpm_file_to_image(game->mlx, "assets/duck", &game->window_y, &game->window_x);
	//atencao! nao sei se o computador podera ser a saida
	game->exit = mlx_xpm_file_to_image(game->mlx, "assets/Computer", &game->window_y, &game->window_x);
}