/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:37:12 by miguelhenri       #+#    #+#             */
/*   Updated: 2025/03/10 13:06:19 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr > 9)
		i += ft_putunbr(nbr / 10);
	i += ft_putchar((nbr % 10) + '0');
	return (i);
}
