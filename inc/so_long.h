/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:56:12 by miguelhenri       #+#    #+#             */
/*   Updated: 2025/03/12 18:10:36 by mpitta-p         ###   ########.fr       */
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


# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define EMPTY '0'
# define WALL '1'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define ENEMY 'X'
# define VISITED 'F'

# define TYLE_SIZE 64

# define BACKGROUD_PATH "assets/chao6464.xpm"
# define WALL_PATH "assets/parede.xpm"
# define PLAYER_PATH "assets/Design(1).xpm"
# define ENEMY_PATH "assets/Design(1).xpm"//
# define COLLECTIBLE_PATH "assets/pato-com-fundo.xpm"
# define EXIT_PATH "assets/computador(comfundo).xpm"

#define USE_DOUBLE_BUFFER 1

typedef struct s_flood
{
	int		collectibles;
	int		exit_founded;
	int		width;
	int		height;
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
	void	*mlx;
	void	*window;
	int		moves;
	bool	key_pressed;
	t_map	map_info;

	void	*background;
	void	*wall;
	void	*player;
	void	*colectable;
	void	*exit;
	void	*enemy;
}			t_game;

//Functions

//Argument validation
void	args_checker(int ac, char *f_name);
void	arg_num(int ac);
void	arg_format(char *f_name);
void	check_map(char *f_name);

//Error handling
void	ft_error(char *msg);

//Map initialization and validation
void	init_map(t_game *info, char *f_name);
int		measure_lines(t_game *info, char *f_name);
void	validate_map_shape(t_game *info);
void validate_map(t_game *info);
void	validate_map_walls(t_game *info);
void	validate_path(t_game *info);

//Game elements handling
void	player_position(t_game *info, int x, int y);
int		invalid_element(t_game *info, int x, int y);
void	num_of_elems(t_game *info);
void	elem_counter(t_game *info, int end_x, int end_y);
void	set_map_limits(t_game *info);

void	free_resources(t_game *info);

//Game initialization
void	open_wind(t_game *info);
void	init_elems(t_game *info);
void	init_image(t_game *info);

//Rendering
void	render_tile(t_game *info, int x, int y);
void 	render_map(t_game *info);
void	update_exit_status(t_game *info);

//Rendering
int	key_press(int keycode, t_game	*info);
int	close_window(t_game *info);
void	move_player(t_game *info, int dir_x, int dir_y);
int	key_release(int keycode, t_game *info);

//Game status management
void	free_resources(t_game *info);

#endif