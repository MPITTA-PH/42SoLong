/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:36:57 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/12 19:00:19 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

int	key_press(int keycode, t_game	*info)
{
	if (info->key_pressed)
		return (0);

	info->key_pressed = 1;
	if (keycode == 65307)
		close_window(info);
	else if (keycode == 119)
		move_player(info, 0, -1); //mover Up Arrow
	else if (keycode == 115)
		move_player(info, 0, +1); //mover Down Arrow
	else if (keycode == 97)
		move_player(info, -1, 0); //mover Left Arrow
	else if (keycode == 100)
		move_player(info, 1, 0); //mover Right Arrow
	else
		info->key_pressed = 0;
	return (0);
}

int	key_release(int keycode, t_game *info)
{
	if (keycode == 110 || keycode == 115 || keycode == 97 || keycode == 100)
		info->key_pressed = 0;
	return (0);
}

int	close_window(t_game *info)
{
	int	i;

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

	if (info->window)
		mlx_destroy_window(info->mlx, info->window);

	if (info->mlx)
		mlx_destroy_display(info->mlx);

	free(info->mlx);

	//free map_grid
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
	exit (0);
	return (0);
}

void	move_player(t_game *info, int dir_x, int dir_y)
{
	int		new_x;
	int		new_y;
	char	next_tile;
	int		old_x;
	int		old_y;
/* 	char	*moves_str;
 */
	new_x = info->map_info.player_x + dir_x;
	new_y = info->map_info.player_y + dir_y;

	if (new_x < 0 || new_x >= info->map_info.width || new_y < 0 || new_y >= info->map_info.height)
		return;
	
	next_tile = info->map_info.grid[new_y][new_x];
	if (next_tile == '1')
		return;
	//funcao para reconhecer a captura de um coletavel
	if (next_tile == 'C')
	{
		info->map_info.n_collects--;
		info->map_info.grid[new_y][new_x] = '0';
		ft_printf("Collectible gathered!🐤 Remaining: %d\n", info->map_info.n_collects); //aqui posso mudar o novo tile para invez de ser so o chao ser uma versao da base do coletavel;
		update_exit_status(info);
	}
	//funcao para reconhecer a saida mas permitir terminar o jogo apenas coletar todos os coletaveis
	if (next_tile == 'E')
	{
		if (info->map_info.n_collects == 0)
		{
			ft_printf("Congratulations! You've completed this map with %d moves\n", info->moves + 1);
			close_window(info);
		}
		else
		{
			ft_printf("You need to gather all the collectible to open the exit!");
		}
		return;
	}
	//funcao para morrer e fechar a janela se tocar num inimigo
	if (next_tile == 'X')
	{
		ft_printf("💀🪦Game over!🪦💀 You've hit a enemy after %d moves...\n", info->moves + 1);
		close_window(info);
	}
	old_x = info->map_info.player_x;
	old_y = info->map_info.player_y;

	//aqui atualizo a posicao do player no mapa e reseto a sua posicao antiga
	info->map_info.grid[info->map_info.player_y][info->map_info.player_x] = '0';
	info->map_info.grid[new_y][new_x] = 'P';

	//aqui atualizo as coordenadas do player
	info->map_info.player_x = new_x;
	info->map_info.player_y = new_y;

	//incrementar em moves para exibir no ecra
	info->moves++;
	ft_printf("Moves: %d\n", info->moves);

	render_tile(info, old_x, old_y);
	render_tile(info, info->map_info.player_x, info->map_info.player_y);
/* 

	moves_str = ft_itoa(info->moves);
	if (moves_str == NULL)
		ft_error("Failed to allocate memory for 'moves_str'");
	
	mlx_string_put(info->mlx, info->window, 10, 20, 0X000000, "             "); // Clear previous text
	mlx_string_put(info->mlx, info->window, 10, 20, 0XFFFFFF, "Moves:");
	mlx_string_put(info->mlx, info->window, 70, 20, 0XFFFFFF, moves_str);
	free(moves_str); */
  	//voltar a renderizar o mapa com todas as atualizacoes
	render_map(info); 
} 
