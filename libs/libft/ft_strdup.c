/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:00:41 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/02/27 17:38:27 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	cnt_1;
	unsigned int	cnt_2;
	char			*dest;

	cnt_1 = 0;
	cnt_2 = 0;
	while (s[cnt_1] != '\0')
		cnt_1++;
	dest = (char *)malloc(sizeof(char) * cnt_1 + 1);
	if (!dest)
		return (NULL);
	while (s[cnt_2] != '\0')
	{
		dest[cnt_2] = s[cnt_2];
		cnt_2++;
	}
	dest[cnt_2] = '\0';
	return (dest);
}
/*
int     main()
{
        char            *x = "12345";
        char            *d;
			    
	d = ft_strdup(x);
        printf("ft_strdup.c: resultado de funcao: %s \n", d);
}*/
