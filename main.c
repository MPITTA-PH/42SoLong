#include "minilibx_linux/mlx.h"
#include <stdio.h>

/*typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	// Calcula o endereço do pixel (x, y)
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// Coloca o valor de cor no endereço calculado
	*(unsigned int*)dst = color;
}

int	close(int	keycode, t_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
int	main(void)
{
	void	*mlx;
	void	*mlx_nwin;
	t_data	img;
	t_data	vars;

	mlx = mlx_init();
	if (!mlx)
		return (-1);
	mlx_nwin = mlx_new_window(mlx, 1940, 1080, "janela 1");
	if (!mlx_nwin)
		return (-1);
	img.img = mlx_new_image(mlx, 1940, 1080);
	if (!img.img)
		return (-1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (!img.addr)
		return (-1);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_nwin, img.img, 0, 0);

	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(mlx);
}*/


typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

int	close_if_ESC(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		return (0);
	}
	return (1);
}

int	close_if_X(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("tecla pressionada: %d\n", keycode);
	return (0);
}

int	ola_mouse(int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
    //printf("Rato entrou na janela! Posição: %d, %d\n", x, y);
	printf("Rato entrou na janela!");
	return (0);
}

int	bye_mouse(int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	//printf("Adeus rato... :(         Posição: %d, %d\n", x, y);
	printf("Adeus rato... :(");
	return (0); 
}
int	mouse_position(int x, int y, t_vars *vars)
{
	(void)vars;
	printf("O rato esta em X: %d, Y: %d\n", x, y);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	//criar a ligacao ao X11
	vars.mlx = mlx_init();
	//abrir a janela
	vars.win = mlx_new_window(vars.mlx, 640, 480, "janela aberta");

	//eventos para fechar a janela
	mlx_hook(vars.win, 2, 1L<<0, close_if_ESC, &vars); //fecha se carregar numa tecla
	mlx_hook(vars.win, 17, 1L, close_if_X, &vars); //fecha se carregar na cruz da janela
	//mlx_hook(vars.win, 6, 1L<<6, close, &vars); //fecha se mexer o rato
	
	//eventos para pressionar em teclas - hook para uma funcao criada acima
	mlx_key_hook(vars.win, key_hook, &vars);

	//evento para indicar as coordenadas do mouse
	//mlx_hook(vars.win, 6, 1L<<6, mouse_position, &vars);

	//dizer ola ao rato
	mlx_hook(vars.win, 7, 1L<<4, ola_mouse, &vars);

	//dizer adeus ao rato
	mlx_hook(vars.win, 8, 1L<<5, bye_mouse, &vars);

	//loop para manter a janela aberta
	mlx_loop(vars.mlx);
}
