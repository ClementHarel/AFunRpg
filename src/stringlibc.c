/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** string.c
*/

#include "my.h"

char	*my_strdup(char *str)
{
	int size = my_strlen(str);
	char *new = malloc(size + 1);
	int i = -1;

	while (++i < size)
		new[i] = str[i];
	new[size] = 0;
	return (new);
}

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_putstr(char *str)
{
	int size = -1;

	while (str[++size]);
	write(1, str, size);
	return (size);
}

int	my_strlen(char *str)
{
	int size = -1;

	while (str[++size]);
	return (size);
}

int	my_strcmp(char *stra, char *strb)
{
	int i = 0;

	while (stra[i] && strb[i]) {
		if (stra[i] != strb[i])
			return ((stra[i] < strb[i]) * -2 + 1);
		i += 1;
	}
	if (!stra[i] && !strb[i])
		return (0);
	return ((stra[i] < strb[i]) * -2 + 1);
}
