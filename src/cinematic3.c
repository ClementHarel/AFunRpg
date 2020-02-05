/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** La norme c b1
*/

#include "my.h"
#include "config.h"

void	ending(window_t *win, sprite_t *sprite, player_t *player)
{
	if (win->final_battle == 2 && win->block_forest == 0) {
		win->dialogue_nb = 22;
		win->block_forest = 1;
		dialogue(win, sprite, player, 1);
	}
	if (win->final_battle == 3)
		win->repeat = 2;
}

void	final_battle(window_t *win, sprite_t *sprite, player_t *player)
{
	if (win->map_number == 8 && win->block_forest != 1
			&& win->final_battle == FALSE) {
		win->dialogue_nb = 21;
		win->block_forest = 1;
		sfSprite_setPosition(sprite->melgor,
		(sfVector2f ) { 19 * SQUARE_SIZE, 15 * SQUARE_SIZE - 16});
		change_dir(DOWN, sprite->melgor);
		change_dir(DOWN, sprite->player);
		dialogue(win, sprite, player, 1);
	}
}

void	elendia_arrival(window_t *win, sprite_t *sprite, player_t *player)
{
	if (win->map_number == 6 && win->block_forest != 1
			&& win->elendia_arrival == FALSE) {
		win->dialogue_nb = 25;
		win->block_forest = 1;
		dialogue(win, sprite, player, 1);
	}
}

void	attack_oxydia(window_t *win, sprite_t *sprite, player_t *player)
{
	if (win->map_number == 1 && win->block_forest != 1
			&& win->melgor_after_battle == 1
			&& win->oxydia_attack == 0) {
		win->dialogue_nb = 12;
		win->block_forest = 1;
		dialogue(win, sprite, player, 1);
		sfSprite_setPosition(sprite->melgor,
		(sfVector2f ) { 19 * SQUARE_SIZE, 3 * SQUARE_SIZE - 16});
		change_dir(UP, sprite->melgor);
		}
}
