/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:43:48 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/10 19:30:46 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	args_checker(int ac, char *f_name)
{
	arg_num(ac);
	arg_format(f_name);
	check_map(f_name);
	
}

void	arg_num(int ac)
{
	if (ac > 2)
		ft_error("To many arguments");
	if (ac < 2)
	ft_error("Insufficient arguments");
}

void	arg_format(char *f_name)
{
	size_t	len;
	char	*extension;

	len = ft_strlen(f_name);
	if (len < 5)
		ft_error("Invalid file name");
	extension = f_name + (len - 4);
	if (ft_strncmp(extension, ".ber", 4) != 0)
		ft_error("File format no supported(must be '.ber')");
	if (len == 4 || f_name[len - 5] == '/')
		ft_error("Invalid file name");
}

void	check_map(char *f_name)
{
	int	fd;
	
	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		ft_error("Cannot opne this map");
	close (fd);
}
