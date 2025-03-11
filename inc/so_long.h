/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:56:12 by miguelhenri       #+#    #+#             */
/*   Updated: 2025/03/11 19:47:05 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"
# include "../libs/printf/ft_printf.h"
# include "../libs/gnl/get_next_line.h"
# include "../libs/minilibx-linux/mlx.h"

typedef struct s_assets
{
	
}			t_assets;

typedef struct s_flood
{
	int		collectibles;
	int		exit_founded;
	int		width;
	int		heigth;
}			t_flood;

typedef struct s_map
{
	char	 **grid;
	int		width;
	int		height;
	int	 	n_player;
	int		n_collects;
	int		n_enemy;
	int		n_exit;
	int		player_x;
	int		player_y;
}			t_map;

//FALTA RESTRUTURAR ISTO, ESTES DADOS DEVEM IR PARA A RESPETIVA ESTRUTURA */

typedef struct	s_game
{
	void		*mlx;
	void		*window;
	int			signal;
	int			window_x;
	int			window_y;
	int			moves;
	bool		game_over;
	t_assets	assets;
//	t_error		error;
	t_map		map_info;
	//
	void		*background;
	void		*wall;
	void		*player;
	void		*colectable;
	void		*exit;
	void		*enemy;
}			t_game;

//Functions

//MAP ELEMENTS
void	player_position(t_game *info, int x, int y);
int		invalid_element(t_game *info, int x, int y);
void	num_of_elems(t_game *info);
void	elem_counter(t_game *info, int end_x, int end_y);
void	set_map_limits(t_game *info);

//ERROR
void	ft_error(char *msg);

//ARGUMENTS CHECKER
void	args_checker(int ac, char *f_name);
void	arg_num(int ac);
void	arg_format(char *f_name);
void	check_map(char *f_name);

void	open_wind(t_game *info);

int		measure_lines(t_game *info, char *f_name);

void	validate_map_shape(t_game *info);

void	init_map(t_game *info, char *f_name);

void	init_elems(t_game *info);

void	validate_map(t_game *info, char *f_name);

//MAP VALIDATION
void	validate_map_walls(t_game *info);

//PATH VALIDATION
void	validate_path(t_game *info);

void	init_image(t_game *info);

//RENDER
void	render_tile(t_game *info, int x, int y);
void 	render_map(t_game *info);

/* static void	init_image(t_game *info); */


#endif