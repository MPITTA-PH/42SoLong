/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelhenriques <miguelhenriques@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:51:48 by miguelhenri       #+#    #+#             */
/*   Updated: 2024/12/12 17:51:18 by miguelhenri      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*left[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left[fd] = function_read (fd, left[fd]);
	if (!left[fd])
		return (NULL);
	line = ft_getlines(left[fd]);
	left[fd] = ft_getlefts(left[fd]);
	return (line);
}

char	*function_read(int fd, char *str)
{
	char	*temp;
	int		byter_read;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	byter_read = 1;
	while (!ft_strchr(str, '\n') && (byter_read != 0))
	{
		byter_read = read(fd, temp, BUFFER_SIZE);
		if (byter_read == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[byter_read] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

char	*ft_getlines(char *left)
{
	int		i;
	char	*line;

	i = 0;
	if (!left[i])
		return (NULL);
	while (left[i] && left[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (left[i] && left[i] != '\n')
	{
		line[i] = left[i];
		i++;
	}
	if (left[i] == '\n')
	{
		line[i] = left[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_getlefts(char *left)
{
	char	*rest;
	int		i;
	int		j;
	int		l;

	i = ft_strlen(left, '\n');
	if (!left[i])
	{
		free(left);
		return (NULL);
	}
	l = ft_strlen(left, '\0');
	rest = (char *)malloc(sizeof(char) * (l - i + 1));
	if (!rest)
	{
		free(rest);
		return (NULL);
	}
	i++;
	j = 0;
	while (left[i])
		rest[j++] = left[i++];
	rest[j] = '\0';
	free(left);
	return (rest);
}

/*int main() {
    char *filename;
    char *line;
    int fd;

    // Test 1
    filename = "test1.txt";
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Reading from %s:\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    printf("\n");

    // Test 2
    filename = "test2.txt";
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Reading from %s:\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    printf("\n");

    // Test 3
    filename = "test3.txt";
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Reading from %s:\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    printf("\n");

    filename = "test4.txt";
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Reading from %s:\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    printf("\n");

	    // Test 5
    filename = "test5.txt";
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Reading from %s:\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    printf("\n");
	
    return 0;
}*/