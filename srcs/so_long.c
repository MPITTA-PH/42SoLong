/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:55:48 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/12 15:26:45 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main(int ac, char **av)
{
	t_game	info;

	ft_printf("Starting program...\n");
	args_checker(ac, av[1]);
	ft_printf("Arguments checked successfully\n");
	//init elem
	//init map
	//valid map
	//open window
	init_elems(&info);
	ft_printf("Elements initialized\n");
	init_map(&info, av[1]);
	ft_printf("Map initialized\n");
	validate_map(&info, av[1]);
	ft_printf("Map validated\n");
	validate_path(&info);
	ft_printf("Path validated\n");

	ft_printf("About to open window...\n");
	open_wind(&info);
	ft_printf("Window opened successfully\n");

	ft_printf("About to initialize images...\n");
	init_image(&info);
	ft_printf("Images initialized successfully\n");

	ft_printf("About to render map...\n");
	render_map(&info);
	ft_printf("Map rendered successfully\n");

	ft_printf("Setting up hooks...\n");
	//keypress hooks
	mlx_hook(info.window, 2, 1L<<0, key_press, &info);
	mlx_hook(info.window, 17, 0, close_window, &info);     // Window close event
	ft_printf("Hooks set up successfully\n");

	ft_printf("Starting MLX loop...\n");
	mlx_loop(info.mlx);
	ft_printf("This should never print\n");
/* 	init_image(&info); */
}
