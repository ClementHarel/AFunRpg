/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Player Movement
*/

#include "my.h"
#include "config.h"

void	anim(sprite_t *sprite)
{
	if (sprite->player_rect.left == SQUARE_SIZE * 3)
		sprite->player_rect.left = 0;
	else
		sprite->player_rect.left += SQUARE_SIZE;
}

void	change_direction(sprite_t *sprite, int value)
{
	switch (value) {
	case (RIGHT):
		sprite->player_rect.top = NPC_HEIGHT * 2;
		break;
	case (LEFT):
		sprite->player_rect.top = NPC_HEIGHT;
		break;
	case (DOWN):
		sprite->player_rect.top = NPC_HEIGHT * 3;
		break;
	case (UP):
		sprite->player_rect.top = 0;
		break;
	}
	sfSprite_setTextureRect(sprite->player, sprite->player_rect);
}

int	collide(window_t *win, sprite_t *sprite)
{
	int value = win->event.key.code;
	int temp_value = value;

	switch (value) {
	case (RIGHT):
		value = 1;
		break;
	case (LEFT):
		value = -1;
		break;
	case (DOWN):
		value = -MAP_X;
		break;
	case (UP):
		value = MAP_X;
		break;
	}
	return (collide_next(win, value, temp_value, sprite));
}

void	player_movement_loop(window_t *win, sprite_t *sprite)
{
	sfVector2f position = sfSprite_getPosition(sprite->player);
	int value = win->event.key.code;

	position = player_loop(position, value, sprite);
	anim(sprite);
	sfSprite_setTextureRect(sprite->player, sprite->player_rect);
	sfSprite_setPosition(sprite->player, position);
}

void	player_movement(window_t *win, sprite_t *sprite, player_t *player)
{
	int 		value = win->event.key.code;

	if ((value != LEFT && value != RIGHT && value != UP && value != DOWN)
			|| win->event.type == sfEvtKeyReleased
			|| win->text_on == 1) {
		sprite->is_animated = 0;
		return;
	}
	if (win->menu == TRUE || player->battle == TRUE)
		return;
	sprite->is_animated = 1;
	main_loop(win, sprite, player, 0);
	sprite->is_animated = 0;
	if (win->map_number >= 3 && win->map_number <= 5 && rand()% 10 == 1)
		battle(player, sprite, win);
}
