/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:18:10 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/02/27 17:38:30 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	len;
	size_t	x;

	if (!s || !f)
		return ;
	len = ft_strlen(s);
	x = 0;
	while (x < len)
	{
		f(x, &s[x]);
		x++;
	}
}
/*
void tochange (unsigned int i, char *c)
{
        *c += i;
}

int main(int argc, char **argv)
{
        (void) argc;  
        
        printf("Sending \'%s\'\n", argv[1]);
        ft_striteri(argv[1], &tochange);
        printf("Returning \'%s\'\n", argv[1]);      
}*/
