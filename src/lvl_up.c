/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** Lvlup
*/

#include "my.h"
#include "config.h"

void	fd_update(window_t *win, char *fd_string)
{
	if (win->dialogue_nb == 20)
		win->dialogue_nb += 3;
	if (win->dialogue_nb == 23 && win->quest_on != 1)
		return;
	if (win->dialogue_nb == 16 && win->quest_on == 2)
		win->dialogue_nb = 24;
	fd_string[20] = win->dialogue_nb + '0';
	fd_string[21] = '\0';
	if (win->dialogue_nb > 9) {
		fd_string[20] = (win->dialogue_nb / 10) + '0';
		fd_string[21] = (win->dialogue_nb % 10) + '0';
	}
}

void	dialogue_update(window_t *win, int i ,
		sprite_t *sprite, player_t *player)
{
	win->dialogue_nb = i;
	cinematic_npc(i, win);
	dialogue(win, sprite, player, i);
}

void	draw_battle_next(window_t *win, sprite_t *sprite)
{
	sfRenderWindow_drawSprite(win->render_window, sprite->mp_bar, NULL);
	sfRenderWindow_drawSprite(win->render_window, sprite->red_bar, NULL);
	sfRenderWindow_drawSprite(win->render_window, sprite->blue_bar, NULL);
	sfRenderWindow_drawSprite(win->render_window, sprite->hp_bar, NULL);
	sfRenderWindow_drawSprite(win->render_window, sprite->mob_bar, NULL);
	sfRenderWindow_drawSprite(win->render_window,
			sprite->mob_bar_red, NULL);
	sfRenderWindow_drawSprite(win->render_window,
			sprite->cursor_battle, NULL);
	sfRenderWindow_drawSprite(win->render_window,
			sprite->ennemy_battle, NULL);
}

void	melgor_up(player_t *player, int up)
{
	player->m_lvl++;
	player->m_exp -= up;
	player->m_attack += 4;
	player->m_def += 3;
	player->m_max_health += 25;
	player->m_health = player->m_max_health;
	player->m_max_mana += 13;
	player->m_mana = player->m_max_mana;
}

void	lvl_up(player_t *player)
{
	int lvl_up = 10 * (player->lvl * 2) + player->lvl + 2;
	int lvl_up_m = 10 * (player->m_lvl *2) + player->m_lvl + 2;

	if (player->exp >= lvl_up) {
		player->lvl++;
		player->exp -= lvl_up;
		player->attack += 4;
		player->def += 3;
		player->max_health += 25;
		player->health = player->max_health;
		player->max_mana += 13;
		player->mana = player->max_mana;
	}
	if (player->m_exp >= lvl_up_m)
		melgor_up(player, lvl_up_m);
}
