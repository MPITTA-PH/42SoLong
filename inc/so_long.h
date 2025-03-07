/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelhenriques <miguelhenriques@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:56:12 by miguelhenri       #+#    #+#             */
/*   Updated: 2025/03/07 23:16:55 by miguelhenri      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_assets
{
	
}			t_assets;

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
	t_error		error;
	t_map		map_info;
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


#endif