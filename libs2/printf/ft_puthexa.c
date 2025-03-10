/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:36:58 by miguelhenri       #+#    #+#             */
/*   Updated: 2025/03/10 13:05:41 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long n, char format)
{
	char	*base;
	int		i;

	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	i = 0;
	if (n >= 16)
	{
		i += ft_puthexa(n / 16, format);
		i += ft_puthexa(n % 16, format);
	}
	else if (n < 16)
		i += ft_putchar(base[n]);
	return (i);
}
