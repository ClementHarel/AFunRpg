/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Main.c
*/

#include "my.h"

int	main(void)
{
	window_t	win;
	sprite_t	sprite;

	new_window(&win);
	game_setup(&win, &sprite);
	return (0);
}
