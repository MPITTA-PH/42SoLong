/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:23:00 by miguelhenri       #+#    #+#             */
/*   Updated: 2025/03/11 12:05:05 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error(char *msg)
{
	ft_printf("ERROR - %s\n", msg);
	exit(0);
}
//VERIFICAR SE ASSIM TEM LEAKS