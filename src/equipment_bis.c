/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Epitech is fun
*/

#include "my.h"
#include "config.h"

int	equipment_event_bis(window_t *win)
{
	if (win->event.key.code == DOWN && win->cursor_pos_equipment != 3) {
		if (win->cursor_pos_equipment2 == 4) {
			win->cursor_pos_equipment2 = 2;
			return (1);
		}
		win->cursor_pos_equipment2 += 1;
	}
	if ((win->cursor_pos_equipment == 1 && win->cursor_pos_equipment2 == 2
			&& win->event.key.code == DOWN)
			|| ((win->cursor_pos_equipment == 1
			&& win->cursor_pos_equipment2 == 1
			&& win->event.key.code == UP)
			&& (win->long_sword == TRUE))) {
		win->cursor_pos_equipment2 = 4;
		return (1);
	}
	return (0);
}

int	equipment_event(window_t *win)
{
	if (win->event.key.code == 36)
		win->equipment_menu = FALSE;
	if (win->event.key.code == LEFT) {
		win->cursor_pos_equipment--;
		win->cursor_pos_equipment2 = 1;
	}
	if (win->event.key.code == RIGHT) {
		win->cursor_pos_equipment++;
		win->cursor_pos_equipment2 = 1;
	}
	if (win->event.key.code == UP && win->cursor_pos_equipment != 3) {
		if (win->cursor_pos_equipment2 == 4) {
			win->cursor_pos_equipment2 = 1;
			return (1);
		}
		win->cursor_pos_equipment2 -= 1;
	}
	return (0);
}

void	move_cursor_equip(window_t *win, player_t *player)
{
	if (win->cursor_pos_equipment == 0)
		win->cursor_pos_equipment = 3;
	if (win->cursor_pos_equipment == 4)
		win->cursor_pos_equipment = 1;
	if (win->cursor_pos_equipment2 == 0)
		win->cursor_pos_equipment2 = 2;
	if (win->cursor_pos_equipment2 == 3)
		win->cursor_pos_equipment2 = 1;
	if (win->event.key.code == ENTER)
		check_equip(win, player);
}

void	check_accessory(window_t *win, player_t *player)
{
	if ((win->armor == 1 || win->armor == 2)
			&& win->cursor_pos_equipment2 == 1
			&& win->cursor_pos_equipment == 2) {
		if (win->armor == 2)
			player->def -= 10;
		else
			player->def += 4;
		win->armor = 0;
	}
}

void	check_armor(window_t *win, player_t *player)
{
	if ((win->weapon == 0 || win->weapon == 1)
			&& win->cursor_pos_equipment2 == 4
			&& win->cursor_pos_equipment == 1) {
		if (win->weapon == 1)
			player->attack += 14;
		else
			player->attack += 10;
		win->weapon = 2;
	}
	if ((win->armor == 0  || win->armor == 2)
			&& win->cursor_pos_equipment2 == 2
			&& win->cursor_pos_equipment == 2) {
		if (win->armor == 2)
			player->def -= 14;
		else
			player->def -= 4;
		win->armor = 1;
	}
}
