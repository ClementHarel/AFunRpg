/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Menu
*/

#include "my.h"
#include "config.h"

void	get_stats_player(window_t *win, player_t *player)
{
	char mana[10] = "100 / 100";
	char health[10] = "500 / 500";
	char atk [3] = "00\0";
	char def [3] = "00\0";

	update_stat(health, mana, player);
	atk[0] = player->attack / 10 + '0';
	atk[1] = player->attack % 10 + '0';
	def[0] = player->def / 10 + '0';
	def[1] = player->def % 10 + '0';
	sfText_setString(win->player_mana_menu, mana);
	sfText_setString(win->player_health_menu, health);
	sfText_setString(win->atk, atk);
	sfText_setString(win->def, def);
}

void	menu_player(sprite_t *sprite)
{
	static sfIntRect player_rect;

	player_rect.top = 0;
	player_rect.left += SQUARE_SIZE;
	if (player_rect.left >= SQUARE_SIZE * 4)
		player_rect.left = 0;
	player_rect.width = SQUARE_SIZE;
	player_rect.height = NPC_HEIGHT;
	sfSprite_setTextureRect(sprite->hero_menu, player_rect);
	sfSprite_setTextureRect(sprite->melgor_menu, player_rect);

}

void	menu_loop(window_t *win, sprite_t *sprite, player_t *player)
{
	sfVector2f pos = { 827, 220};

	get_money(win);
	menu_draw(win, player, sprite, pos);
	if (win->melgor_encounter == TRUE)
		sfRenderWindow_drawText(win->render_window,
				win->m_lvl_menu, NULL);
	menu_player(sprite);
	if (win->melgor_encounter == 1)
		melgor_menu(win, sprite, player);
}

void	menu_move_cursor(window_t *win, sprite_t *sprite, player_t *player)
{
	if (win->event.key.code == DOWN)
		win->menu_cursor--;
	if (win->event.key.code == UP)
		win->menu_cursor++;
	if (win->menu_cursor == -1)
		win->menu_cursor = 4;
	else if (win->menu_cursor == 5)
		win->menu_cursor = 0;
	if (win->event.key.code == ENTER)
		submenu(win, sprite, player);
}

void	menu(window_t *win, player_t *player)
{
	get_stats_player(win, player);
	if (win->block_forest == TRUE || win->text_on == TRUE
			|| player->battle == TRUE)
		return;
	if (win->menu == FALSE)
		win->menu = TRUE;
	else
		win->menu = FALSE;
}
