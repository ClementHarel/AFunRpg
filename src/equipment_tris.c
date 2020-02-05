/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Oui.
*/

#include "my.h"

void	equi_loop(window_t *win, player_t *player)
{
	sfRenderWindow_drawText(win->render_window, win->atk, NULL);
	sfRenderWindow_drawText(win->render_window, win->def, NULL);
	sfRenderWindow_drawText(win->render_window, win->short_sword, NULL);
	sfRenderWindow_drawText(win->render_window, win->nothing, NULL);
	if (win->long_sword == TRUE && win->cursor_pos_equipment == 1)
		sfRenderWindow_drawText(win->render_window,
				win->long_sword_txt, NULL);
	if (win->heavy_armor == TRUE && win->cursor_pos_equipment == 2)
		sfRenderWindow_drawText(win->render_window,
				win->heavy_armor_txt, NULL);
	while (sfRenderWindow_pollEvent(win->render_window, &win->event)) {
		if (win->event.type == sfEvtKeyReleased)
			event(win, player);
	}
}

void	equi_text(window_t *win)
{
	sfText_setString(win->long_sword_txt, "Long Sword");
	sfText_setString(win->heavy_armor_txt, "Heavy Armor");
	if (win->cursor_pos_equipment == 1) {
		sfText_setString(win->short_sword, "Short Sword (E)");
		sfText_setString(win->nothing, "(Nothing)");
	}
	if (win->cursor_pos_equipment == 2) {
		sfText_setString(win->short_sword, "Light Armor (E)");
		sfText_setString(win->nothing, "(Nothing)");
	}
	if (win->cursor_pos_equipment == 3) {
		sfText_setString(win->short_sword, "(Nothing) (E)");
		sfText_setString(win->nothing, "");
	}
	if (win->cursor_pos_equipment == 3 && win->quest_on == 2) {
		sfText_setString(win->short_sword, "Fate's Necklace (E)");
		sfText_setString(win->nothing, "");
	}
}

void	equipment_text(window_t *win)
{
	if (win->cursor_pos_equipment == 1) {
		if (win->weapon == 0) {
			sfText_setString(win->short_sword, "Short Sword (E)");
			sfText_setString(win->nothing, "(Nothing)");
		}
		if (win->weapon == 1) {
			sfText_setString(win->short_sword, "Short Sword");
			sfText_setString(win->nothing, "(Nothing) (E)");
		}
		if (win->weapon == 2) {
			sfText_setString(win->short_sword, "Short Sword");
			sfText_setString(win->nothing, "(Nothing)");
			sfText_setString(win->long_sword_txt, "Long Sword (E)");
		}
	}
}

void	check_weapon(window_t *win, player_t *player)
{
	if ((win->weapon == 0 || win->weapon == 2)
			&& win->cursor_pos_equipment2 == 2
			&& win->cursor_pos_equipment == 1) {
		if (win->weapon == 2)
			player->attack -= 14;
		else
			player->attack -= 4;
		win->weapon = 1;
	}
	if ((win->weapon == 1 || win->weapon == 2)
			&& win->cursor_pos_equipment2 == 1
			&& win->cursor_pos_equipment == 1) {
		if (win->weapon == 2)
			player->attack -= 10;
		else
			player->attack += 4;
		win->weapon = 0;
	}
}
