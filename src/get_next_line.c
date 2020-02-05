/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get_next_line
*/

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	check_buf(char *buf, int buf_size)
{
	int i = 0;

	while (i < buf_size) {
		if (buf[i] == '|')
			return (i);
		i += 1;
	}
	return (-1);
}

void	my_strncpyi(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n) {
		dest[i] = src[i];
		i += 1;
	}
}

char	*my_realloc(char *buffer, int size, int new_size)
{
	char *new = malloc(new_size);

	if (new == NULL)
		return (NULL);
	if (new_size > size)
		my_strncpyi(new, buffer, size);
	else if (new_size < size)
		my_strncpyi(new, &buffer[size - new_size], new_size);
	return (new);
}

char	*get_next_line_ii(int fd, char *return_val, int index, int read_ret)
{
	int size = 0;
	char *buffer;

	while (check_buf(buffer, size) == -1 && read_ret == READ_SIZE) {
		if ((buffer = my_realloc(buffer, size, size + READ_SIZE))
				== NULL)
			return (NULL);
		size += read_ret = read(fd, &buffer[size], READ_SIZE);
	}
	index = check_buf(buffer, size) == -1 ? size : check_buf(buffer, size);
	if (read_ret == -1 || (read_ret == 0 && size < 1))
		return (NULL);
	if ((return_val = malloc(index + 1)) == NULL)
		return (NULL);
	my_strncpyi(return_val, buffer, index);
	return_val[index] = '\0';
	buffer = my_realloc(buffer, size, size - 1 - index);
	size = size - 1 - index;
	return (return_val);
}

char	*get_next_line(int fd)
{
	char *return_val = 0;
	int index = 0;
	int read_ret = READ_SIZE;

	if (fd < 0 || READ_SIZE < 1)
		return (NULL);
	return (get_next_line_ii(fd, return_val, index, read_ret));
}
