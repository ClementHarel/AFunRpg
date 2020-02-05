/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Ah oui le bac blanc
*/

#include "my.h"
#include "config.h"

float	get_damage(player_t *player, window_t *win)
{
	float dgt = 0;

	if (win->melgor_encounter == 0 || win->melgor_turn == FALSE)
		player->e_health -= player->attack - player->e_def;
	else
		player->e_health -= player->m_attack - player->e_def;
	dgt = (double)player->e_health / (double)player->e_health_max;
	if (dgt < 0) {
		dgt = 0;
		game_over(player, win);
	}
	if (win->melgor_encounter == 0 || win->melgor_turn == FALSE)
		anim_dgt(win, player->attack - player->e_def + rand() % 4);
	else
		anim_dgt(win, player->m_attack - player->e_def + rand() % 4);
	if (dgt > 1)
		dgt = 1;
	return (dgt);
}

void	submenu_battle(window_t *win, player_t *player, sprite_t *sprite)
{
	float dgt = 0;

	if (battle_tree(player, win, dgt, sprite) == 1)
		return;
	if (player->cursor_pos >= 0 && player->cursor_pos < 5
			&& player->cursor_pos != 3 && player->cursor_pos != 1) {
		if (win->melgor_turn == FALSE)
			player->m_defend = TRUE;
		else
			player->h_defend = TRUE;
		if ((win->melgor_encounter == FALSE
				|| win->melgor_turn == TRUE)) {
			win->ennemy_turn = TRUE;
			return;
		}
		if (win->melgor_turn == FALSE && win->melgor_encounter == TRUE)
			win->melgor_turn = TRUE;
	}
}

void	poll_event_battle(window_t *win, sprite_t *sprite, player_t *player)
{
	while (sfRenderWindow_pollEvent(win->render_window, &win->event)
			&& win->inventory_menu == FALSE) {
		if (win->event.type == sfEvtKeyReleased) {
				event_inventory(win, player);
			if (win->event.key.code == RIGHT
					&& player->cursor_pos != 4)
				player->cursor_pos++;
			if (win->event.key.code == LEFT
					&& player->cursor_pos != 0)
				player->cursor_pos--;
			if (win->event.key.code == ENTER
					&& win->skill_loop == FALSE) {
				submenu_battle(win, player, sprite);
			}
				if (win->skill_loop == TRUE)
					skill_event(win, player);
		}
		sfSprite_setPosition(sprite->cursor_battle, (sfVector2f)
			{200 + (178 * player->cursor_pos), 553});
	}
}

void	battle_loop(player_t *player, window_t *win, sprite_t *sprite)
{
	static int sahakian = 255;

	if (player->battle == TRUE) {
		anim_turn(sprite, win);
		if (win->dgt_on == FALSE) {
			poll_event_battle(win, sprite, player);
			sahakian = 255;
		}
		if (win->ennemy_turn == TRUE && win->dgt_on == FALSE) {
			ennemy_turn(player, sprite, win);
			win->ennemy_turn = FALSE;
		}
		draw_battle(win, sprite);
		sahakiann(win, sahakian);
	}
}

void	battle(player_t *player, sprite_t *sprite, window_t *win)
{
	char str[24] = "ressources/battle/?.png";

	player->cursor_pos = 0;
	sfSprite_setScale(sprite->mob_bar_red, (sfVector2f) {1, 1});
	if (win->melgor_encounter == TRUE && win->melgor_after_battle == FALSE)
		player->battle_id = 0;
	else
		player->battle_id = rand()%3;
	player->defend = FALSE;
	player->m_defend = FALSE;
	player->h_defend = FALSE;
	win->ennemy_turn = FALSE;
	win->dgt_on = FALSE;
	player->e_attack = 20 + rand()%20;
	battle_next(win, player, sprite, str);
}
