/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:26:01 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/02/27 17:38:44 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*x;

	x = NULL;
	while (*s)
	{
		if (*s == (char)c)
			x = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (x);
}
/*
int	main()
{
	char	*teste;
	int	prova;

	prova = 'l';
	teste = "blaplabrpla";
	printf("value is: %s \n", ft_strrchr(teste, prova));
} */
