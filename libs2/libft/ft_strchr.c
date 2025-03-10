/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:12:06 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/02/27 17:38:24 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
		if (!*s++)
			return (0);
	return ((char *)s);
}
/*
int	main()
{
	char	*teste;
	int	prova;

	prova = ' ';
	teste = "bla plab lap";
	printf("value is: %s \n", (ft_strchr(teste, prova)));
        printf("value is: %s \n", (ft_strchr(&teste[4], prova)));

}*/
