/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:23:15 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/02/27 17:38:10 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		((unsigned char *)s)[counter] = c;
		counter++;
	}
	return (s);
}
/*
int	main()
{
	int	ch, count;
        char    let[] = "rstu";
	ch = '2';
	count = 0;

        write(1, let, sizeof(char) * 4);
        write(1, "before\n", 7);
	ft_memset(&let, ch, 3);
        write(1, let, sizeof(char) * 4);
        write(1, "after\n", 6);
        return(0);
}*/
