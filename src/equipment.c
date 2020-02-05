/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Equipment
*/

#include "my.h"
#include "config.h"

void	check_equip(window_t *win, player_t *player)
{
	check_weapon(win, player);
	check_armor(win, player);
	check_accessory(win, player);
	if ((win->armor == 0 || win->armor == 1)
			&& win->cursor_pos_equipment2 == 4
			&& win->cursor_pos_equipment == 2) {
		if (win->armor == 1)
			player->def += 14;
		else
			player->def += 10;
		win->armor = 2;
	}
	get_stats_player(win, player);
}

void	event(window_t *win, player_t *player)
{
	if (equipment_event(win) == 1)
		return;
	if (equipment_event_bis(win) == 1)
		return;
	if (((win->cursor_pos_equipment == 2 && win->cursor_pos_equipment2 == 2
			&& win->event.key.code == DOWN)
			|| (win->cursor_pos_equipment == 2
			&& win->cursor_pos_equipment2 == 1
			&& win->event.key.code == UP))
			&& (win->heavy_armor == TRUE)) {
		win->cursor_pos_equipment2 = 4;
		return;
	}
	move_cursor_equip(win, player);
}

void	check_equipment(window_t *win)
{
	equipment_text(win);
	if (win->cursor_pos_equipment == 2) {
		if (win->armor == 0) {
			sfText_setString(win->short_sword, "Light Armor (E)");
			sfText_setString(win->nothing, "(Nothing)");
		}
		if (win->armor == 1) {
			sfText_setString(win->short_sword, "Light Armor");
			sfText_setString(win->nothing, "(Nothing) (E)");
		}
		if (win->armor == 2) {
			sfText_setString(win->short_sword, "Light Armor");
			sfText_setString(win->nothing, "(Nothing)");
			sfText_setString(win->heavy_armor_txt,
					"Heavy Armor (E)");
		}
	}
}

void	equipment_loop(window_t *win, sprite_t *sprite, player_t *player)
{
	equi_text(win);
	check_equipment(win);
	sfSprite_setPosition(sprite->cursor, (sfVector2f)
			{400 * win->cursor_pos_equipment - 400, 300});
	sfSprite_setPosition(sprite->cursor_equipment, (sfVector2f)
			{750, win->cursor_pos_equipment2 * 150 + 330});
	if (win->cursor_pos_equipment2 == 4) {
		sfSprite_setPosition(sprite->cursor_equipment, (sfVector2f)
				{1200, 150 + 330});
	}
	sfRenderWindow_drawSprite(win->render_window,
			sprite->equipment_menu, NULL);
	sfRenderWindow_drawSprite(win->render_window, sprite->cursor, NULL);
	sfRenderWindow_drawSprite(win->render_window,
			sprite->cursor_equipment, NULL);
	equi_loop(win, player);
}

void	equipment(window_t *win)
{
	win->equipment_menu = TRUE;
	win->event.key.code = FALSE;
}
