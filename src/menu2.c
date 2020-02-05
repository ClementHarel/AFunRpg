/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Menu next
*/

#include "my.h"
#include "config.h"

void	get_goal(window_t *win)
{
	int fd = open("ressources/dialogue/goal", O_RDONLY);
	char *str;
	int i = -1;

	while (++i <= win->flags)
		str = get_next_line(fd);
	sfText_setString(win->goal, str);
}

void	get_location(window_t *win)
{
	int fd = open("ressources/dialogue/location", O_RDONLY);
	char *str;
	int i = -1;

	while (++i <= win->map_number)
		str = get_next_line(fd);
	sfText_setString(win->location, str);
}

void	get_money(window_t *win)
{
	char money[5] = "000 G";

	money[0] = win->money / 100 + '0';
	money[1] = win->money / 10 % 10 + '0';
	money[2] = win->money % 10 + '0';
	sfText_setString(win->money_menu, money);
}

void	get_stats_melgor(window_t *win, player_t *player)
{
	char mana[10] = "100 / 100";
	char health[10] = "500 / 500";

	mana[6] = player->m_max_mana / 100 + '0';
	mana[7] = player->m_max_mana / 10 % 10 + '0';
	mana[8] = player->m_max_mana % 10 + '0';
	mana[0] = player->m_mana / 100 + '0';
	mana[1] = player->m_mana / 10 % 10 + '0';
	mana[2] = player->m_mana % 10 + '0';
	health[6] = player->m_max_health / 100 + '0';
	health[7] = player->m_max_health / 10 % 10 + '0';
	health[8] = player->m_max_health % 10 + '0';
	health[0] = player->m_health / 100 + '0';
	health[1] = player->m_health / 10 % 10 + '0';
	health[2] = player->m_health % 10 + '0';
	sfText_setString(win->melgor_mana_menu, mana);
	sfText_setString(win->melgor_health_menu, health);
}

void	melgor_menu(window_t *win, sprite_t *sprite, player_t *player)
{
	get_stats_melgor(win, player);
	sfRenderWindow_drawSprite(win->render_window,
			sprite->melgor_menu, NULL);
	sfRenderWindow_drawText(win->render_window,
			win->melgor_name_menu, NULL);
	sfRenderWindow_drawText(win->render_window,
			win->melgor_health_menu, NULL);
	sfRenderWindow_drawText(win->render_window,
			win->melgor_mana_menu, NULL);
}
