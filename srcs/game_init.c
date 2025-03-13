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

static void	*load_image(t_game *info, char *path)
{
	int	img_width;
	int	img_height;
	void	*img;

	img_width = TYLE_SIZE;
	img_height = TYLE_SIZE;

	img = mlx_xpm_file_to_image(info->mlx, path, &img_width, &img_height);
	if (!img)
		ft_printf("WARNING! Failed to load image: %s\n", path);
	
	return (img);
}

void	init_image(t_game *info)
{	
	info->background = load_image(info,BACKGROUD_PATH);
	info->wall = load_image(info, WALL_PATH);
	info->colectable = load_image(info, COLLECTIBLE_PATH);
	//atencao! nao sei se o computador podera ser a saida
	//quero fazer um efeito visual na saida, com brilho e assim
	info->exit = load_image(info, EXIT_PATH);
	info->player = load_image(info, PLAYER_PATH);
	info->enemy = load_image(info, ENEMY_PATH);

/* 	info->player = NULL;
	info->colectable = NULL;
	info->exit = NULL;
	info->enemy = NULL; */
	
	if (!info->background)
		ft_error("Failed to load background!");
	if (!info->wall)
		ft_error("Failed to load wall!");
	if (!info->player)
		ft_error("Failed to load player!");
	if (!info->exit)
		ft_error("Failed to load exit!");
	if (!info->enemy)
		ft_error("Failed to load enemy!");
	if (!info->colectable)
		ft_error("Failed to load collectible!");
}

void	open_wind(t_game *info)
{

	int	window_width;
	int	window_height;
	
	window_width = info->map_info.width * TYLE_SIZE;
	window_height = info->map_info.height * TYLE_SIZE;

/* 	ft_printf("W:%d | H:%d\n", window_width, window_height);
 */	
	
	info->mlx = mlx_init();
	if (!info->mlx)
		ft_error("Failed to initialize MLX");
	info->window = mlx_new_window(info->mlx, window_width, window_height, "so_long");
	if (!info->window)
	{
		mlx_destroy_display(info->mlx);
		free(info->mlx);
		ft_error("Failed to open window");
	}
}