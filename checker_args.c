/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:43:48 by mpitta-p          #+#    #+#             */
/*   Updated: 2025/03/07 13:45:48 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	arg_num(int ac, char **av)
{
	if (ac > 2)
	{
		ft_printf("ERRO - demasiados argumentos");
		return (-1);
	}
	if (ac < 2)
	{
		ft_printf("ERROR - argumentos insuficientes");
	}
}