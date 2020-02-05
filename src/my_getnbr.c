/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** itlte
*/

#include "my.h"

void	no_clue(window_t *win, sprite_t *sprite,
		player_t *player, float mana)
{
	tornado(win, sprite, player, 0);
	if (player->mana < 0)
		player->mana = 0;
	if (player->m_mana < 0)
		player->m_mana = 0;
	mana = (double)player->mana / (double)player->max_mana;
	sfSprite_setScale(sprite->blue_bar, (sfVector2f) {mana, 1});
}

void	menu_draw(window_t *win, player_t *player,
		sprite_t *sprite, sfVector2f pos)
{
	get_location(win);
	get_goal(win);
	get_lvl(player, win);
	sfText_setString(win->player_name_menu, player->name);
	pos.y += win->menu_cursor * 77;
	sfSprite_setPosition(sprite->cursor, pos);
	sfSprite_setPosition(sprite->hero_menu, (sfVector2f){180, 230});
	sfSprite_setPosition(sprite->melgor_menu, (sfVector2f){180, 400});
	sfRenderWindow_drawSprite(win->render_window, sprite->cursor, NULL);
	sfRenderWindow_drawSprite(win->render_window, sprite->hero_menu, NULL);
	sfRenderWindow_drawText(win->render_window,
			win->player_name_menu, NULL);
	sfRenderWindow_drawText(win->render_window,
			win->player_health_menu, NULL);
	sfRenderWindow_drawText(win->render_window,
			win->player_mana_menu, NULL);
	sfRenderWindow_drawText(win->render_window, win->money_menu, NULL);
	sfRenderWindow_drawText(win->render_window, win->location, NULL);
	sfRenderWindow_drawText(win->render_window, win->goal, NULL);
	sfRenderWindow_drawText(win->render_window, win->lvl_menu, NULL);
}

void	update_stat(char *health, char *mana, player_t *player)
{
	mana[6] = player->max_mana / 100 + '0';
	mana[7] = player->max_mana / 10 % 10 + '0';
	mana[8] = player->max_mana % 10 + '0';
	mana[0] = player->mana / 100 + '0';
	mana[1] = player->mana / 10 % 10 + '0';
	mana[2] = player->mana % 10 + '0';
	health[6] = player->max_health / 100 + '0';
	health[7] = player->max_health / 10 % 10 + '0';
	health[8] = player->max_health % 10 + '0';
	health[0] = player->health / 100 + '0';
	health[1] = player->health / 10 % 10 + '0';
	health[2] = player->health % 10 + '0';
}

void	init_player(window_t *win, player_t *player)
{
	win->repeat = 1;
	player->health = 600;
	player->max_health = 600;
	player->mana = 200;
	player->max_mana = 200;
	player->m_health = 650;
	player->m_max_health = 650;
	player->m_mana = 50;
	player->m_max_mana = 50;
	player->exp = 0;
	player->m_exp = 0;
	player->lvl = 1;
	player->m_lvl = 2;
	player->lvl_up = 0;
	player->attack = 7;
	player->def = 5;
	player->m_attack = 6;
	player->m_def = 3;
	player->battle = FALSE;
	player->cursor_pos = 0;
}

int	my_getnbr(char const *str)
{
	long number = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			sign *= -1;
		i += 1;
	}
	while (str[i] >= '0' && str[i] <= '9') {
		number *= 10;
		number += str[i] - 48;
		i += 1;
	}
	if (number > 2147483647 || number < -2147483648)
		return (0);
	return (number * sign);
}
