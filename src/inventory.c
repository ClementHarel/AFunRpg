/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Inventory
*/

#include "my.h"
#include "config.h"

void	get_obj(window_t *win)
{
	char hp[18] = "Health Potion [0]\0";
	char mp [16] = "Mana Potion [0]\0";

	hp[15] = win->health_potion + '0';
	mp[13] = win->mana_potion + '0';
	sfText_setString(win->health_txt, hp);
	sfText_setString(win->mana_txt, mp);
}

void	using_item(window_t *win, player_t *player)
{
	int sahakian = win->event.key.code;

	if (sahakian != 0 && sahakian != 25)
		return;
	healing(sahakian, win, player);
	get_obj(win);
	get_stats_player(win, player);
	win->use_item = FALSE;
	if (player->battle == TRUE) {
		win->inventory_menu = FALSE;
		if ((win->melgor_encounter == FALSE ||
				win->melgor_turn == TRUE)) {
			win->ennemy_turn = TRUE;
			return;
		}
		if (win->melgor_turn == FALSE && win->melgor_encounter == TRUE)
			win->melgor_turn = TRUE;
	}
}

void	event_inventory(window_t *win, player_t *player)
{

	if ((win->event.key.code == 0 || (win->event.key.code == 25
			&& win->melgor_encounter == TRUE))
			&& (win->use_item == TRUE))
		using_item(win, player);
	if (win->event.key.code == 36 && win->use_item == FALSE)
		win->inventory_menu = FALSE;
	if (win->event.key.code == 36 && win->use_item == TRUE)
		win->use_item = FALSE;
	if (win->event.key.code == DOWN && win->use_item == FALSE)
		win->cursor_pos_inventory++;
	if (win->event.key.code == UP && win->use_item == FALSE)
		win->cursor_pos_inventory--;
	if (win->cursor_pos_inventory == 0)
		win->cursor_pos_inventory = 2;
	if (win->cursor_pos_inventory == 3)
		win->cursor_pos_inventory = 1;
	if (win->event.key.code == ENTER)
		item_use(win, player);
}

void	inventory_loop(window_t *win, sprite_t *sprite, player_t *player)
{
	get_obj(win);
	oui(sprite, win);
	sfRenderWindow_drawSprite(win->render_window,
			sprite->inventory_menu, NULL);
	sfRenderWindow_drawText(win->render_window, win->health_txt, NULL);
	sfRenderWindow_drawText(win->render_window, win->mana_txt, NULL);
	sfRenderWindow_drawSprite(win->render_window,
			sprite->cursor_equipment, NULL);
	if (win->use_item == TRUE) {
		sfRenderWindow_drawText(win->render_window,
				win->heal_player, NULL);
		if (win->melgor_encounter == TRUE)
			sfRenderWindow_drawText(win->render_window,
					win->heal_melgor, NULL);
	}
	while (sfRenderWindow_pollEvent(win->render_window, &win->event)) {
		if (win->event.type == sfEvtKeyReleased) {
			event_inventory(win, player);
		}
	}
}

void	inventory(window_t *win)
{
	win->inventory_menu = TRUE;
	win->use_item = FALSE;
}
