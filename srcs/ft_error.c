/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:23:00 by miguelhenri       #+#    #+#             */
/*   Updated: 2025/03/11 12:05:05 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
/*
 * This function displays an error message and exits the program.
 * Note: Ideally, this should call a cleanup function to free all allocated
 * memory before exiting, but since the game struct might not be accessible
 * from every context where errors can occur, we simply exit.
 * 
 * Better approach would be to pass the game struct to ft_error and
 * free all resources before exiting, but that would require
 * refactoring most of the code base.
 */
void	ft_error(char *msg)
{
	ft_printf("ERROR - %s\n", msg);
	exit(EXIT_FAILURE);
}
//VERIFICAR SE ASSIM TEM LEAKS