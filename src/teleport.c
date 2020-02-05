/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Teleport
*/

#include "my.h"
#include "config.h"

void	new_map(sprite_t *sprite, window_t *win, int x, int y)
{
	sfVector2f pos = {x, y};
	char string[25] = "ressources/tileset/?.png";
	char string2[26] = "ressources/tileset/?m.png";

	string[19] = win->map_number + '0';
	string2[19] = win->map_number + '0';
	update_sprite(string, sprite->map);
	update_sprite(string2, sprite->map_masque);
	if (win->map_number < 3)
		update_sprite("ressources/fog.png", sprite->light);
	else if (win->map_number < 6)
		update_sprite("ressources/light.png", sprite->light);
	else
		update_sprite("ressources/fog2.png", sprite->light);
	sfSprite_setPosition(sprite->player, pos);
	generate_colision(win);
	win->repeat = 1;
}

void	teleport_next_next_next(window_t *win, sprite_t *sprite)
{
	if (win->map_number == 6 && win->player_x == 38) {
		win->map_number = 7;
		new_map(sprite, win, 2 * SQUARE_SIZE, (SQUARE_SIZE * 12) - 16);
	}
	else if (win->map_number == 7 && win->player_x == 2) {
		win->map_number = 6;
		new_map(sprite, win, 37 * SQUARE_SIZE, (SQUARE_SIZE * 9) - 16);
	}
	if (win->map_number == 6 && win->player_y == 0) {
		win->map_number = 8;
		new_map(sprite, win, 20 * SQUARE_SIZE, (SQUARE_SIZE * 16) - 16);
	}
}

void	teleport_next_next(window_t *win, sprite_t *sprite)
{
	if (win->map_number == 4 && win->player_y == 1) {
		win->map_number = 5;
		new_map(sprite, win, 22 * SQUARE_SIZE, (SQUARE_SIZE * 21) - 16);
	}
	else if (win->map_number == 5 && win->player_y == 22) {
		win->map_number = 4;
		new_map(sprite, win, 10 * SQUARE_SIZE, (SQUARE_SIZE * 2) - 16);
	}
	if (win->map_number == 5 && win->oxydia_attack == TRUE
			&& win->player_x == 39) {
		win->map_number = 6;
		new_map(sprite, win, 1 * SQUARE_SIZE, (SQUARE_SIZE * 8) - 16);
	}
	else if (win->map_number == 6 && win->player_x == 0) {
		win->map_number = 5;
		new_map(sprite, win, 38 * SQUARE_SIZE, (SQUARE_SIZE * 12) - 16);
	}
	else if (win->map_number == 6 || win->map_number == 7)
		teleport_next_next_next(win, sprite);
}

void	teleport_next(window_t *win, sprite_t *sprite)
{
	if (win->map_number == 1 && win->player_y == 1
			&& win->dialogue_henro == 1) {
		win->map_number = 3;
		new_map(sprite, win, 30 * SQUARE_SIZE, (SQUARE_SIZE * 21) - 16);
	}
	else if (win->map_number == 3 && win->player_y == 22
			&& win->oxydia_attack == 0) {
		win->map_number = 1;
		new_map(sprite, win, 17 * SQUARE_SIZE, (SQUARE_SIZE * 2) - 16);
	}
	if (win->map_number == 3 && win->player_x == 0) {
		win->player_x = 30;
		win->map_number = 4;
		new_map(sprite, win, 38 * SQUARE_SIZE, (SQUARE_SIZE * 14) - 16);
	}
	else if (win->map_number == 4 && win->player_x == 39) {
		win->map_number = 3;
		new_map(sprite, win,  1 * SQUARE_SIZE, (SQUARE_SIZE * 10) - 16);
	}
	teleport_next_next(win, sprite);
}

void	teleport(window_t *win, sprite_t *sprite)
{
	if (win->map_number == 0 && win->player_x == 39) {
		win->map_number = 1;
		new_map(sprite, win, SQUARE_SIZE * 1, (SQUARE_SIZE * 10) - 16);
	}
	else if (win->map_number == 1 && win->player_x == 0) {
		win->map_number = 0;
		new_map(sprite, win,
				(38 * SQUARE_SIZE), (SQUARE_SIZE * 14) - 16);
	}
	if (win->map_number == 1 && win->player_y == 23) {
		win->map_number = 2;
		new_map(sprite, win, 26 * SQUARE_SIZE, SQUARE_SIZE - 16);
	}
	else if (win->map_number == 2 && win->player_y == 0) {
		win->map_number = 1;
		new_map(sprite, win, 19 * SQUARE_SIZE, (SQUARE_SIZE * 22) - 16);
		win->player = 800;
	}
	teleport_next(win, sprite);
}
