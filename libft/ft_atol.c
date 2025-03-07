/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:19:44 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/02/27 17:37:12 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	int		x;
	long	reslt;
	long	signal;

	x = 0;
	signal = 1;
	reslt = 0;
	while ((nptr[x] >= 9 && nptr[x] <= 13) || nptr[x] == 32)
		x++;
	if (nptr[x] == '-' || nptr[x] == '+')
	{
		if (nptr[x] == '-')
			signal = -1;
		x++;
	}
	while (nptr[x] >= 48 && nptr[x] <= 57)
	{
		reslt *= 10;
		reslt += nptr[x] - 48;
		x++;
	}
	return (reslt * signal);
}
