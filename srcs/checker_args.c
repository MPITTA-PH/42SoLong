/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelhenriques <miguelhenriques@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:43:48 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/07 16:01:46 by miguelhenri      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	args_checker(int ac, char *f_name)
{
	arg_num(ac);
	arg_format(f_name);
	check_map(f_name);
	
}

void	arg_num(int ac)
{
	if (ac > 2)
	{
		ft_printf("ERROR - to many arguments");
		exit (EXIT_FAILURE);
	}
	if (ac < 2)
	{
		ft_printf("ERROR - insufficient arguments");
		exit (EXIT_FAILURE);
	}
}

void	arg_format(char *f_name)
{
	int	i;
	int	j;
	char	*format;

	i = ft_strlen(f_name) - 4;
	j = 0;
	format = ".ber";
	if (f_name[i - 1] == '/' || f_name[i - 1] == '\0')
	{
		ft_printf("ERROR - Wrong file.");
		exit (EXIT_FAILURE);
	}
	while (f_name[i])
	{
		if (f_name[i] == format[j])
		{
			i++;
			j++;
		}
		else
		{
			ft_printf("ERROR - file format not supported");
			exit (EXIT_FAILURE);
		}
	}
}

void	check_map(char *f_name)
{
	int	fd;
	
	fd = open(f_name, O_RDONLY);
	if (fd < 0)
	{
		error("Cannot opne this map");
		close(fd);
		exit;
	}
}
