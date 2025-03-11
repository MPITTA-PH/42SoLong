/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:55:48 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/11 20:00:14 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main(int ac, char **av)
{
	t_game	info;

	args_checker(ac, av[1]);
	//init elem
	//init map
	//valid map
	//open window
	init_elems(&info);
	init_map(&info, av[1]);
	validate_map(&info, av[1]);
	validate_path(&info);
	open_wind(&info);
	init_image(&info);
	render_map(&info);	
	mlx_loop(info.mlx);
/* 	init_image(&info); */
}
