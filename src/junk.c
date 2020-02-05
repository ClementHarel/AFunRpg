/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Other function because norm
*/

#include "my.h"

void	init_win(window_t *win)
{
	win->flags = FALSE;
	win->weapon = 0;
	win->armor = 0;
	win->inventory_menu = FALSE;
	win->health_potion = 5;
	win->mana_potion = 3;
	win->cursor_pos_inventory = TRUE;
	win->use_item = FALSE;
	win->skill_loop = FALSE;
	win->skill_used = 0;
	win->shop_loop = 0;
	win->cursor_pos_shop = TRUE;
	win->long_sword = FALSE;
	win->heavy_armor = FALSE;
	win->elendia_arrival = FALSE;
	win->final_battle = FALSE;
	win->load = FALSE;
	win->htp = FALSE;
	win->quest_on = FALSE;
}

void	non(sfColor color, window_t *win, int fd, sfText* text)
{
	int i = 0;

	while (color.a < 254) {
		sfRenderWindow_clear(win->render_window, sfWhite);
		sfSprite_setColor(win->white, color);
		sfRenderWindow_drawSprite(win->render_window, win->white, NULL);
		sfRenderWindow_drawText(win->render_window, text, NULL);
		sfRenderWindow_display(win->render_window);
		color.a += 1;
		color.r -= 1;
		for (i = 0; i < 9999999; i++);
		if (color.a >= 125 && win->repeat == 3 && fd < 0)
			sfText_setString(text, "Save file not fo"
					"und.\n\n\t\tGoodbye !");
	}
}

void	oui(sprite_t *sprite, window_t *win)
{
	sfSprite_setPosition(sprite->cursor_equipment, (sfVector2f)
			{400, win->cursor_pos_inventory * 135 + 120});
}

void	item_use(window_t *win, player_t *player)
{
	char heal_player[26] = "Press 'A' to heal Sahakian";
	char heal_melgor[25] = "Press 'Z' to heal Melgor\0";
	int i = -1;

	while (player->name[++i] != '\0')
		heal_player[i + 18] = player->name[i];
	heal_player[i + 18] = '\0';
	sfText_setString(win->heal_player, heal_player);
	sfText_setString(win->heal_melgor, heal_melgor);
	if ((win->cursor_pos_inventory == 1 && win->health_potion > 0)
			|| (win->cursor_pos_inventory == 2
			&& win->mana_potion > 0))
		win->use_item = TRUE;
}

void	healing(int sahakian, window_t *win, player_t *player)
{
	if (sahakian == 0 && win->cursor_pos_inventory == 1) {
		win->health_potion--;
		player->health = player->max_health;
	}
	if (sahakian == 25 && win->cursor_pos_inventory == 1) {
		win->health_potion--;
		player->m_health = player->m_max_health;
	}
	if (sahakian == 0 && win->cursor_pos_inventory == 2) {
		win->mana_potion--;
		player->mana = player->max_mana;
	}
	if (sahakian == 25 && win->cursor_pos_inventory == 2) {
		win->mana_potion--;
		player->m_mana = player->m_max_mana;
	}
}
