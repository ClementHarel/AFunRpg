/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Cinematics of the game
*/

#include "my.h"
#include "config.h"

int	intro(window_t *win, int  i, sprite_t *sprite, player_t *player)
{
	if (win->event.type == sfEvtKeyReleased && sprite->is_animated == 0) {
		if (i == 0 && win->load == FALSE) {
			win->dialogue_nb = 6;
			dialogue(win, sprite, player, 1);
			if (win->text_on == 0)
				i = 1;
		}
		if (win->block_forest == 0)
			text(win, sprite, player);
	}
	return (i);
}

void	block_ottoman(window_t *win, sprite_t *sprite, player_t *player)
{
	sfVector2f position = sfSprite_getPosition(sprite->player);

	if (win->player_x > 38 && win->map_number == 5
			&& win->block_ottoman == 0 && win->oxydia_attack == 0) {
		position.x -= SQUARE_SIZE * 2;
		sfSprite_setTextureRect(sprite->player, sprite->player_rect);
		sfSprite_setPosition(sprite->player, position);
		win->player -= SQUARE_SIZE * 2;
		win->player_x = win->player % MAP_X;
		win->block_forest = 1;
		win->dialogue_nb = 9;
		dialogue(win, sprite, player, 1);
	}

}

void	block_forest(window_t *win, sprite_t *sprite, player_t *player)
{
	sfVector2f position = sfSprite_getPosition(sprite->player);

	if (win->player <= 45 && win->map_number == 1
			&& win->dialogue_henro == 0) {
		position.y += SQUARE_SIZE * 2;
		sfSprite_setTextureRect(sprite->player, sprite->player_rect);
		sfSprite_setPosition(sprite->player, position);
		win->player += SQUARE_SIZE * 2;
		win->block_forest = 1;
		win->dialogue_nb = 8;
		dialogue(win, sprite, player, 1);
	}
}

void	melgor_encounter(window_t *win, sprite_t *sprite, player_t *player)
{
	if (win->map_number == 4 && win->melgor_encounter == 0
			&& win->block_forest != 1 && win->player_x < 22) {
		win->dialogue_nb = 10;
		win->block_forest = 1;
		dialogue(win, sprite, player, 1);
	}
}

void	melgor_after_battle(window_t *win, sprite_t *sprite,
		player_t *player)
{
	if (win->map_number == 4 && win->melgor_encounter == 1
			&& win->block_forest != 1
			&& win->melgor_after_battle == 0) {
		win->dialogue_nb = 11;
		win->block_forest = 1;
		dialogue(win, sprite, player, 1);
	}
}
