/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:36:57 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/13 16:30:00 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_press(int keycode, t_game	*info)
{
	//ft_printf("Key pressed: %d, key_pressed state: %d\n", keycode, info->key_pressed);

	if (info->key_pressed)
		return (0);

	info->key_pressed = 1;
	if (keycode == KEY_ESC)
		close_window(info);
	else if (keycode == KEY_W)
		move_player(info, 0, -1);
	else if (keycode == KEY_S)
		move_player(info, 0, +1); //mover S Arrow
	else if (keycode == KEY_A)
		move_player(info, -1, 0); //mover A Arrow
	else if (keycode == KEY_D)
		move_player(info, 1, 0); //mover D Arrow
	else
		info->key_pressed = 0;
	return (0);
}

int	key_release(int keycode, t_game *info)
{
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		info->key_pressed = 0;
	return (0);
}

static int	handle_collectibles(t_game *info, int new_x, int new_y)
{
	info->map_info.n_collects--;
	info->map_info.grid[new_y][new_x] = EMPTY;
	ft_printf("Collectible gathered!🐤 Remaining: %d\n", info->map_info.n_collects);
	update_exit_status(info);
	return (1);
}

static int	handle_exit(t_game *info)
{
	if (info->map_info.n_collects == 0)
	{
		ft_printf("Congratulations! You've completed this map with %d moves\n", info->moves);
		close_window(info);
		return (0);
	}
	ft_printf("You nedd to gather all the collectibles to open the exit!\n");
	return (0);
}

static int	handle_enemy(t_game *info)
{
    ft_printf("💀🪦Game over!🪦💀 You've hit an enemy after %d moves...\n", info->moves + 1);
	close_window(info);
	return (0);
}

static void write_moves(t_game *info)
{
    char *moves_str;
    
    // Converte o número de movimentos em string
    moves_str = ft_itoa(info->moves);
    if (moves_str == NULL)
        ft_error("Failed to allocate memory for 'moves_str'");
    
    // Limpar o valor anterior na tela, usando a mesma cor de fundo da janela
    mlx_string_put(info->mlx, info->window, 70, 20, 0X000000, "                "); // '000000' para o fundo preto, ajustando o tamanho de espaços conforme o necessário
    
    // Escrever o novo valor na tela
    mlx_string_put(info->mlx, info->window, 10, 20, 0XFFFFFF, "Moves:");
    mlx_string_put(info->mlx, info->window, 70, 20, 0XFFFFFF, moves_str);  // Novo valor
    
    free(moves_str);
}


void	move_player(t_game *info, int dir_x, int dir_y)
{
	int	new_x;
	int	new_y;
	char	next_tile;
	int	old_x;
	int	old_y;

	write_moves(info);

	new_x = info->map_info.player_x + dir_x;
	new_y = info->map_info.player_y + dir_y;

	if (new_x < 0 || new_x >= info->map_info.width
		|| new_y < 0 || new_y >= info->map_info.height)
		return;
	next_tile = info->map_info.grid[new_y][new_x];
	if (next_tile == WALL)
		return;
	else if (next_tile == EXIT)
	{
		if (info->map_info.n_collects == 0)
			handle_exit(info);
		else
			return;
	}
	else if (next_tile == COLLECTIBLE)
		handle_collectibles(info, new_x, new_y);
	else if (next_tile == ENEMY)
	{
		if (!handle_enemy(info))
			return;
	}
	old_x = info->map_info.player_x;
	old_y = info->map_info.player_y;

	info->map_info.grid[old_y][old_x] = EMPTY;
	info->map_info.grid[new_y][new_x] = PLAYER;

	info->map_info.player_x = new_x;
	info->map_info.player_y = new_y;

	info->moves++;

	render_tile(info, old_x, old_y);
	render_tile(info, new_x, new_y);

/* 	render_map(info);  */
}

int	close_window(t_game *info)
{
	free_resources(info);
	exit(0);
	return (0);
}