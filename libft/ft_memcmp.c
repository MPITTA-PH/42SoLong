/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:44:51 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/02/27 17:38:05 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src;
	unsigned char	*dest;

	src = (unsigned char *)s1;
	dest = (unsigned char *)s2;
	while (n--)
	{
		if (*src != *dest)
			return (*src - *dest);
		else
		{
			src++;
			dest++;
		}
	}
	return (0);
}
/*
int     main()
{
        char    *t1, *t2;

        t1 = "belele";
        t2 = "belle";
        printf("value is : %d \n", ft_memcmp(t1, t2, 5));
} */
