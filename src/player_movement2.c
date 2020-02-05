/*
** EPITECH PROJECT, 2018
** Player movement 2
** File description:
** My_RPG
*/

#include "my.h"
#include "config.h"

void	main_loop(window_t *win, sprite_t *sprite, player_t *player, int i)
{
	sfClock*	player_clock = sfClock_create();
	sfTime		player_time;
	int 		j = 0;

	while (i < 4) {
		if (j == 0 && collide(win, sprite) == 0) {
			sprite->is_animated = 0;
			return;
		}
		j++;
		player_time = sfClock_getElapsedTime(player_clock);
		if (player_time.microseconds > PLAYER_SPEED) {
			player_movement_loop(win, sprite);
			sfClock_restart(player_clock);
			i++;
		} else
			game_loop(win, sprite, player);
	}
}

sfVector2f	player_loop(sfVector2f position, int value, sprite_t *sprite)
{
	switch (value) {
	case (RIGHT):
		sprite->player_rect.top = NPC_HEIGHT * 2;
		position.x += SQUARE_SIZE / 4;
		break;
	case (LEFT):
		sprite->player_rect.top = NPC_HEIGHT;
		position.x -= SQUARE_SIZE / 4;
		break;
	case (DOWN):
		sprite->player_rect.top = NPC_HEIGHT * 3;
		position.y -= SQUARE_SIZE / 4;
		break;
	case (UP):
		sprite->player_rect.top = 0;
		position.y += SQUARE_SIZE / 4;
	}
	return (position);
}

int	collide_next(window_t *win, int value,
		int temp_value, sprite_t *sprite)
{
	win->player += value;
	if (win->colision[win->player] == 1) {
		win->player -= value;
		change_direction(sprite, temp_value);
		return (0);
	}
	return (1);
}
