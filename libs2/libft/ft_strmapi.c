/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:31:42 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/02/27 17:38:39 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	x;

	if (!s || !f)
		return (0);
	dest = ft_strdup(s);
	if (!dest)
		return (0);
	x = 0;
	while (dest[x])
	{
		dest[x] = f(x, dest[x]);
		x++;
	}
	return (dest);
}
/*
char toup (unsigned int i, char c)
{
	return (c - 32);
}

int main(int argc, char **argv)
{
	(void) argc;
	char *res;
	
	printf("Sending \'%s\'\n", argv[1]);
	res = ft_strmapi(argv[1], &toup);
	printf("Returning \'%s\'\n", res);	
}*/
