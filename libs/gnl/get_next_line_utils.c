/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:57:23 by miguelhenri       #+#    #+#             */
/*   Updated: 2025/03/10 17:11:52 by mpitta-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_ft_strlen(char *s, char c)
{
	char	*i;

	i = s;
	if (!s)
		return (0);
	while (*i && *i != c)
		i++;
	return (i - s);
}

char	*gnl_ft_strjoin(char *str1, char *str2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	len1 = gnl_ft_strlen(str1, '\0');
	len2 = gnl_ft_strlen(str2, '\0');
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (++i < len1)
		result[i] = str1[i];
	j = -1;
	while (++j < len2)
		result[i + j] = str2[j];
	result[i + j] = '\0';
	free(str1);
	return (result);
}

char	*gnl_ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	return (0);
}